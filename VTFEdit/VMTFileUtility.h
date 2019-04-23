/*
 * VTFEdit
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#pragma once

#include "stdafx.h"

using namespace System;

enum EToken
{
	TOKEN_EOF = 0,			// No more tokens to read.
	TOKEN_NEWLINE,			// Token is a newline (\n).
	TOKEN_WHITESPACE,		// Token is any whitespace other than a newline.
	TOKEN_FORWARD_SLASH,	// Token is a forward slash (/).
	TOKEN_QUOTE,			// Token is a quote (").
	TOKEN_OPEN_BRACE,		// Token is an open brace ({).
	TOKEN_CLOSE_BRACE,		// Token is a close brace (}).
	TOKEN_CHAR,				// Token is a char (any char).  Use GetChar().
	TOKEN_STRING,			// Token is a string.  Use GetString().
	TOKEN_SPECIAL			// Token is a specified special char.
};

namespace VTFEdit
{
	__gc class CVMTFileUtility
	{
	public:
		static System::String *GetTexturePathFromSystemPath(System::String *sTexture)
		{
			if(sTexture->Length == 0)
				return S"";

			System::String *sExtension = S".vtf";
			System::String *sMaterials = S"materials";

			sTexture = sTexture->Trim();
			sTexture = sTexture->Replace(S"\\", S"/");
			sTexture = sTexture->Replace(S"//", S"/");
			if(sTexture->Length >= 4 && String::Compare(sTexture, sTexture->Length - sExtension->Length, sExtension, 0, sExtension->Length, true) == 0)
			{
				sTexture = sTexture->Substring(0, sTexture->Length - sExtension->Length);
				sTexture = sTexture->Trim();
			}

			int index = sTexture->IndexOf(S":");
			if(index != -1)
			{
				sTexture = sTexture->Substring(index + 1);
			}

			for(int i = 0; i <= sTexture->Length - sMaterials->Length; i++)
			{
				if(String::Compare(sTexture, i, sMaterials, 0, sMaterials->Length, true) == 0)
				{
					sTexture = sTexture->Substring(i + sMaterials->Length);
					i = 0;
				}
			}

			while(sTexture->StartsWith(S"/"))
			{
				sTexture = sTexture->Substring(1);
			}

			while(sTexture->EndsWith(S"/"))
			{
				sTexture = sTexture->Substring(0, sTexture->Length - 1);
			}

			return sTexture;
		}

		static bool CreateDefaultMaterial(System::String *sVTFFile, System::String *sShader)
		{
			return CVMTFileUtility::CreateDefaultMaterial(sVTFFile, sShader, false);
		}

		static bool CreateDefaultMaterial(System::String *sVTFFile, System::String *sShader, bool bHasAlpha)
		{
			System::String *sVMTFile = sVTFFile;

			if(sVMTFile->Length < 4 || String::Compare(sVMTFile, sVMTFile->Length - 4, S".vtf", 0, 4, true) != 0)
			{
				return false;
			}

			sVMTFile = String::Concat(sVMTFile->Substring(0, sVMTFile->Length - 4), S".vmt");

			if(System::IO::File::Exists(sVMTFile))
			{
				return false;
			}

			vlBool bResult;
			char *cTemp0, *cTemp1;
			VTFLib::CVMTFile VMTFile;

			cTemp0 = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sShader).ToPointer();
			VMTFile.Create(cTemp0);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp0);

			cTemp0 = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(S"$basetexture").ToPointer();
			cTemp1 = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(CVMTFileUtility::GetTexturePathFromSystemPath(sVTFFile)).ToPointer();
			VMTFile.GetRoot()->AddStringNode(cTemp0, cTemp1);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp1);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp0);

			if(bHasAlpha)
			{
				cTemp0 = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(S"$translucent").ToPointer();
				VMTFile.GetRoot()->AddIntegerNode(cTemp0, 1);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp0);
			}

			cTemp0 = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sVMTFile).ToPointer();
			bResult = VMTFile.Save(cTemp0);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp0);

			return bResult != 0;
		}

		// Stores token information.
		__gc class CToken
		{
		private:
			EToken eToken;
			char cChar;
			int iIndex;

		public:
			// Create a normal token.  cChar was the tokenized char.
			CToken(EToken eToken, char cChar, int iIndex) : eToken(eToken), cChar(cChar), iIndex(iIndex)
			{

			}

			// Copy a token.
			CToken(const CToken &Token)
			{
				this->eToken = Token.eToken;
				this->cChar = Token.cChar;
			}

		public:
			// Convert the current token to a special token.
			// We need to do this because the tokenizer reads ahead and doen't
			// know if the requested token will be special until after the fact.
			void ToSpecial(char cSpecial)
			{
				if(this->cChar == cSpecial)
				{
					this->eToken = TOKEN_SPECIAL;
					return;
				}

				this->eToken = TOKEN_CHAR;
			}

			// Get the token that was read.
			EToken GetToken()
			{
				return this->eToken;
			}

			// Get the char that was tokenized.  Only works if
			// token is a TOKEN_CHAR or was tokenized by the byte
			// tokenizer.
			char GetChar()
			{
				return this->cChar;
			}

			int GetIndex()
			{
				return this->iIndex;
			}
		};

		// Tokenizes single byte tokens.
		__gc class CByteTokenizer
		{
		private:
			int iIndex;
			int iStart;
			int iEnd;
			String *Text;

		private:
			CToken *CurrentToken;
			CToken *NextToken;

		public:
			CByteTokenizer(String *Text, int iStart, int iEnd) : iIndex(0), iStart(iStart), iEnd(iEnd), Text(Text), CurrentToken(0), NextToken(0)
			{
				this->GetNextToken();
			}

		private:
			void GetNextToken()
			{
				this->GetNextToken('\0');
			}

			void GetNextToken(char cSpecial)
			{
				char cChar;

				if (this->iIndex < this->iStart)
					this->iIndex = this->iStart;

				if(this->iIndex == this->iEnd + 1 || this->iIndex == this->Text->Length)
				{
					this->NextToken = new CToken(TOKEN_EOF, '\0', this->iIndex);
					return;
				}

				cChar = (char)this->Text->Chars[this->iIndex];

				// If a special char was specified, only return TOKEN_CHAR tokens
				// unless the special char was found in which case return a
				// TOKEN_SPECIAL.
				if(cSpecial)
				{
					if(cChar == cSpecial)
					{
						this->NextToken = new CToken(TOKEN_SPECIAL, cChar, this->iIndex);
						return;
					}

					this->NextToken = new CToken(TOKEN_CHAR, cChar, this->iIndex);

					this->iIndex++;
					return;
				}
				
				if(cChar == '\r' || cChar == '\n')
				{
					this->NextToken = new CToken(TOKEN_NEWLINE, cChar, this->iIndex);
				}
				else if(isspace(cChar))
				{
					this->NextToken = new CToken(TOKEN_WHITESPACE, cChar, this->iIndex);
				}
				else if(cChar == '/')
				{
					this->NextToken = new CToken(TOKEN_FORWARD_SLASH, cChar, this->iIndex);
				}
				else if(cChar == '\"')
				{
					this->NextToken = new CToken(TOKEN_QUOTE, cChar, this->iIndex);
				}
				else if(cChar == '{')
				{
					this->NextToken = new CToken(TOKEN_OPEN_BRACE, cChar, this->iIndex);
				}
				else if(cChar == '}')
				{
					this->NextToken = new CToken(TOKEN_CLOSE_BRACE, cChar, this->iIndex);
				}
				else
				{
					this->NextToken = new CToken(TOKEN_CHAR, cChar, this->iIndex);
				}

				this->iIndex++;
			}

		public:
			// Get the current token and return the next one.
			CToken *Next()
			{
				return this->Next('\0');
			}

			CToken *Next(char cSpecial)
			{
				this->CurrentToken = this->NextToken;
				this->NextToken = 0;

				if(cSpecial && this->CurrentToken)
				{
					this->CurrentToken->ToSpecial(cSpecial);
				}

				this->GetNextToken();

				return this->CurrentToken;
			}

			// Get the curret token.
			CToken *Peek()
			{
				return this->NextToken;
			}
		};

		// Tokenizes multi byte tokens.
		__gc class CSyntaxHilighter
		{
		private:
			bool bEnabled;
			String *sOldText;
			System::Windows::Forms::RichTextBox *TextBox;

		public:
			CSyntaxHilighter(System::Windows::Forms::RichTextBox *TextBox) : bEnabled( false), sOldText(S""), TextBox(TextBox)
			{
			}

		public:
			__property bool get_Enabled()
			{
				return this->bEnabled;
			}

			__property void set_Enabled(bool bEnabled)
			{
				this->bEnabled = bEnabled;
			}

			void Purge()
			{
				sOldText = S"";
			}

			void Process()
			{
				if (!this->bEnabled)
					return;

				String *sNewText = TextBox->Text;
				int iStart = 0, iEnd = sNewText->Length - 1, iLength;

				for(int i = 0; i < sNewText->Length && i < this->sOldText->Length; i++)
				{
					if(sNewText->Chars[i] != this->sOldText->Chars[i])
					{
						break;
					}
					
					iStart = i;
				}

				for(int i = 0; i < sNewText->Length && i < this->sOldText->Length; i++)
				{
					if(sNewText->Chars[sNewText->Length - 1 - i] != this->sOldText->Chars[sOldText->Length - 1 - i])
					{
						break;
					}

					iEnd = sNewText->Length - 1 - i;
				}

				if (iEnd >= sNewText->Length)
					iEnd = sNewText->Length - 1;
				if (iEnd < iStart)
					iEnd = iStart;

				while (iStart > 0 && (char)sNewText->Chars[iStart] != '\r' && (char)sNewText->Chars[iStart] != '\n')
				{
					iStart--;
				}

				while(iEnd < sNewText->Length - 1 && (char)sNewText->Chars[iEnd] != '\r' && (char)sNewText->Chars[iEnd] != '\n')
				{
					iEnd++;
				}

				CByteTokenizer *ByteTokenizer = new CByteTokenizer(sNewText, iStart, iEnd);

				this->sOldText = sNewText;

				HWND Handle = (HWND)this->TextBox->Handle.ToPointer();

				//LockWindowUpdate(Handle);

				SendMessage(Handle, WM_SETREDRAW, FALSE, 0);
				LRESULT EventMask = SendMessage(Handle, EM_SETEVENTMASK, 0, 0);

				POINT ScrollLocation;
				SendMessage(Handle, EM_GETSCROLLPOS, 0, (LPARAM)&ScrollLocation);

				System::Drawing::Font *BoldFont = new System::Drawing::Font(this->TextBox->Font, System::Drawing::FontStyle::Bold);

				int iSelectionStart = this->TextBox->SelectionStart;
				int iSelectionLength = this->TextBox->SelectionLength;

				this->TextBox->Select(iStart, iEnd - iStart);
				//this->TextBox->SelectionStart = iStart;
				//this->TextBox->SelectionLength = iEnd - iStart;
				this->TextBox->SelectionColor = System::Drawing::Color::Black;
				this->TextBox->SelectionFont = this->TextBox->Font;

				CToken *Token;
				//int iStart, iLength;

				while(true)
				{
					Token = ByteTokenizer->Next();

					if(Token->GetToken() == TOKEN_EOF)
					{
						break;
					}

					// Consume all whitespace.
					while(Token->GetToken() == TOKEN_WHITESPACE)
					{
						Token = ByteTokenizer->Next();
					}

					iStart = Token->GetIndex();
					iLength = 1;

					switch(Token->GetToken())
					{
						// Comment (these are removed for the parser).
						case TOKEN_FORWARD_SLASH:
						{
							bool bError = false;

							if(ByteTokenizer->Peek()->GetToken() != TOKEN_FORWARD_SLASH)
							{
								bError = true;
							}

							while(true)
							{
								Token = ByteTokenizer->Next('\n');
								if(Token->GetToken() == TOKEN_CHAR)
								{
									iLength++;
								}
								else
								{
									break;
								}
							}

							this->TextBox->Select(iStart, iLength);
							this->TextBox->SelectionColor = bError ? System::Drawing::Color::Red : System::Drawing::Color::Green;
							break;
						}
						// Quoted string.
						case TOKEN_QUOTE:
						{
							bool bError = false;
							char cStart = '\0';

							this->TextBox->Select(iStart, iLength);
							this->TextBox->SelectionColor = System::Drawing::Color::DarkGray;
							this->TextBox->SelectionFont = BoldFont;

							iStart++;
							iLength = 0;

							while(true)
							{
								Token = ByteTokenizer->Next('\"');

								if(Token->GetToken() != TOKEN_CHAR)
								{
									break;
								}

								if(Token->GetChar() == '\r' || Token->GetChar() == '\n')
								{
									bError = true;
									break;
								}

								if(iLength == 0)
								{
									cStart = Token->GetChar();
								}

								iLength++;
							}

							if(bError || Token->GetToken() != TOKEN_SPECIAL)
							{
								this->TextBox->Select(iStart, iLength);
								this->TextBox->SelectionColor = System::Drawing::Color::Red;
							}
							else
							{
								/*if(cStart == '$')
								{
									this->TextBox->SelectionStart = iStart;
									this->TextBox->SelectionLength = iLength;
									this->TextBox->SelectionColor = System::Drawing::Color::Orange;
								}
								else if(cStart == '%')
								{
									this->TextBox->SelectionStart = iStart;
									this->TextBox->SelectionLength = iLength;
									this->TextBox->SelectionColor = System::Drawing::Color::Lime;
								}*/
								this->TextBox->Select(Token->GetIndex(), 1);
								this->TextBox->SelectionColor = System::Drawing::Color::DarkGray;
								this->TextBox->SelectionFont = BoldFont;
							}
							break;
						}
						// Unquoted string.
						case TOKEN_CHAR:
						{
							while(ByteTokenizer->Peek()->GetToken() == TOKEN_CHAR)
							{
								iLength++;
								Token = ByteTokenizer->Next();
							}

							this->TextBox->Select(iStart, iLength);
							this->TextBox->SelectionColor = System::Drawing::Color::Blue;
							break;
						}
						// Let these byte tokens "pass through".
						case TOKEN_EOF:
						case TOKEN_NEWLINE:
						{
							break;
						}
						case TOKEN_OPEN_BRACE:
						case TOKEN_CLOSE_BRACE:
						{
							this->TextBox->Select(iStart, iLength);
							this->TextBox->SelectionColor = System::Drawing::Color::DarkGray;
							this->TextBox->SelectionFont = BoldFont;
							break;
						}
						// The parser doesn't care about anything else.
						default:
						{
							break;
						}
					}
				}

				this->TextBox->Select(iSelectionStart, iSelectionLength);

				SendMessage(Handle, EM_SETSCROLLPOS, 0, (LPARAM)&ScrollLocation);

				SendMessage(Handle, EM_SETEVENTMASK, 0, EventMask);
				SendMessage(Handle, WM_SETREDRAW, TRUE, 0);

				RedrawWindow(Handle, NULL, NULL, RDW_INVALIDATE);

				//LockWindowUpdate(0);
			}
		};
	};
}