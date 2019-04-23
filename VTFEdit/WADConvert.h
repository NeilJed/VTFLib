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
#include "VTFOptions.h"
#include "VMTFileUtility.h"
#include "VTFFileUtility.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace VTFEdit
{
	public __gc class CWADConvert : public System::Windows::Forms::Form
	{
	private:
		CVTFOptions *Options;

	public: 
		CWADConvert(CVTFOptions *Options)
		{
			this->Options = Options;

			this->InitializeComponent();
		}
        
	protected: 
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::GroupBox *  grpOptions;
	private: System::Windows::Forms::Button *  btnConvert;
	private: System::Windows::Forms::GroupBox *  grpProgress;
	private: System::Windows::Forms::Label *  lblWADFile;
	private: System::Windows::Forms::TextBox *  txtWADFile;
	private: System::Windows::Forms::Button *  btnWADFileBrowse;
	private: System::Windows::Forms::Button *  btnOutputFolderBrowse;
	private: System::Windows::Forms::TextBox *  txtOutputFolder;
	private: System::Windows::Forms::Label *  lblOutputFolder;
	private: System::Windows::Forms::ProgressBar *  barProgress;
	private: System::Windows::Forms::OpenFileDialog *  dlgOpenWADFile;
	private: System::Windows::Forms::FolderBrowserDialog *  dlgOpenFolder;
	private: System::Windows::Forms::Button *  btnOptions;
	private: System::Windows::Forms::GroupBox *  grpLog;
	private: System::Windows::Forms::RichTextBox *  txtLog;
	private: System::Windows::Forms::Button *  btnClose;
	private: System::Windows::Forms::CheckBox *  chkCreateVMTFiles;
	private: System::Windows::Forms::ToolTip *  tipMain;
	private: System::ComponentModel::IContainer *  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = new System::ComponentModel::Container();
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(VTFEdit::CWADConvert));
			this->grpOptions = new System::Windows::Forms::GroupBox();
			this->chkCreateVMTFiles = new System::Windows::Forms::CheckBox();
			this->btnOutputFolderBrowse = new System::Windows::Forms::Button();
			this->txtOutputFolder = new System::Windows::Forms::TextBox();
			this->lblOutputFolder = new System::Windows::Forms::Label();
			this->btnWADFileBrowse = new System::Windows::Forms::Button();
			this->txtWADFile = new System::Windows::Forms::TextBox();
			this->lblWADFile = new System::Windows::Forms::Label();
			this->btnClose = new System::Windows::Forms::Button();
			this->btnConvert = new System::Windows::Forms::Button();
			this->grpProgress = new System::Windows::Forms::GroupBox();
			this->barProgress = new System::Windows::Forms::ProgressBar();
			this->dlgOpenWADFile = new System::Windows::Forms::OpenFileDialog();
			this->dlgOpenFolder = new System::Windows::Forms::FolderBrowserDialog();
			this->btnOptions = new System::Windows::Forms::Button();
			this->grpLog = new System::Windows::Forms::GroupBox();
			this->txtLog = new System::Windows::Forms::RichTextBox();
			this->tipMain = new System::Windows::Forms::ToolTip(this->components);
			this->grpOptions->SuspendLayout();
			this->grpProgress->SuspendLayout();
			this->grpLog->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpOptions
			// 
			this->grpOptions->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->grpOptions->Controls->Add(this->chkCreateVMTFiles);
			this->grpOptions->Controls->Add(this->btnOutputFolderBrowse);
			this->grpOptions->Controls->Add(this->txtOutputFolder);
			this->grpOptions->Controls->Add(this->lblOutputFolder);
			this->grpOptions->Controls->Add(this->btnWADFileBrowse);
			this->grpOptions->Controls->Add(this->txtWADFile);
			this->grpOptions->Controls->Add(this->lblWADFile);
			this->grpOptions->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->grpOptions->Location = System::Drawing::Point(8, 8);
			this->grpOptions->Name = S"grpOptions";
			this->grpOptions->Size = System::Drawing::Size(360, 96);
			this->grpOptions->TabIndex = 2;
			this->grpOptions->TabStop = false;
			this->grpOptions->Text = S"Options:";
			// 
			// chkCreateVMTFiles
			// 
			this->chkCreateVMTFiles->Checked = true;
			this->chkCreateVMTFiles->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkCreateVMTFiles->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkCreateVMTFiles->Location = System::Drawing::Point(88, 64);
			this->chkCreateVMTFiles->Name = S"chkCreateVMTFiles";
			this->chkCreateVMTFiles->Size = System::Drawing::Size(112, 24);
			this->chkCreateVMTFiles->TabIndex = 6;
			this->chkCreateVMTFiles->Text = S"Create &VMT Files";
			this->tipMain->SetToolTip(this->chkCreateVMTFiles, S"Generate .vmt files for .vtf files. Ouput folder should be a material folder.");
			// 
			// btnOutputFolderBrowse
			// 
			this->btnOutputFolderBrowse->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->btnOutputFolderBrowse->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOutputFolderBrowse->Location = System::Drawing::Point(328, 40);
			this->btnOutputFolderBrowse->Name = S"btnOutputFolderBrowse";
			this->btnOutputFolderBrowse->Size = System::Drawing::Size(20, 20);
			this->btnOutputFolderBrowse->TabIndex = 5;
			this->btnOutputFolderBrowse->Text = S"...";
			this->btnOutputFolderBrowse->Click += new System::EventHandler(this, &CWADConvert::btnOutputFolderBrowse_Click);
			// 
			// txtOutputFolder
			// 
			this->txtOutputFolder->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->txtOutputFolder->Location = System::Drawing::Point(88, 40);
			this->txtOutputFolder->Name = S"txtOutputFolder";
			this->txtOutputFolder->ReadOnly = true;
			this->txtOutputFolder->Size = System::Drawing::Size(232, 20);
			this->txtOutputFolder->TabIndex = 4;
			this->txtOutputFolder->Text = S"";
			this->tipMain->SetToolTip(this->txtOutputFolder, S"Destination image folder.");
			// 
			// lblOutputFolder
			// 
			this->lblOutputFolder->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblOutputFolder->Location = System::Drawing::Point(8, 40);
			this->lblOutputFolder->Name = S"lblOutputFolder";
			this->lblOutputFolder->Size = System::Drawing::Size(80, 23);
			this->lblOutputFolder->TabIndex = 3;
			this->lblOutputFolder->Text = S"Output Folder:";
			// 
			// btnWADFileBrowse
			// 
			this->btnWADFileBrowse->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->btnWADFileBrowse->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnWADFileBrowse->Location = System::Drawing::Point(328, 16);
			this->btnWADFileBrowse->Name = S"btnWADFileBrowse";
			this->btnWADFileBrowse->Size = System::Drawing::Size(20, 20);
			this->btnWADFileBrowse->TabIndex = 2;
			this->btnWADFileBrowse->Text = S"...";
			this->btnWADFileBrowse->Click += new System::EventHandler(this, &CWADConvert::btnWADFileBrowse_Click);
			// 
			// txtWADFile
			// 
			this->txtWADFile->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->txtWADFile->Location = System::Drawing::Point(88, 16);
			this->txtWADFile->Name = S"txtWADFile";
			this->txtWADFile->ReadOnly = true;
			this->txtWADFile->Size = System::Drawing::Size(232, 20);
			this->txtWADFile->TabIndex = 1;
			this->txtWADFile->Text = S"";
			this->tipMain->SetToolTip(this->txtWADFile, S"Source .wad file.");
			this->txtWADFile->TextChanged += new System::EventHandler(this, &CWADConvert::txtWADFile_TextChanged);
			// 
			// lblWADFile
			// 
			this->lblWADFile->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblWADFile->Location = System::Drawing::Point(8, 16);
			this->lblWADFile->Name = S"lblWADFile";
			this->lblWADFile->Size = System::Drawing::Size(80, 23);
			this->lblWADFile->TabIndex = 0;
			this->lblWADFile->Text = S"WAD File:";
			// 
			// btnClose
			// 
			this->btnClose->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right);
			this->btnClose->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnClose->Location = System::Drawing::Point(288, 320);
			this->btnClose->Name = S"btnClose";
			this->btnClose->Size = System::Drawing::Size(80, 23);
			this->btnClose->TabIndex = 1;
			this->btnClose->Text = S"&Close";
			this->btnClose->Click += new System::EventHandler(this, &CWADConvert::btnClose_Click);
			// 
			// btnConvert
			// 
			this->btnConvert->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right);
			this->btnConvert->Enabled = false;
			this->btnConvert->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnConvert->Location = System::Drawing::Point(200, 320);
			this->btnConvert->Name = S"btnConvert";
			this->btnConvert->Size = System::Drawing::Size(80, 23);
			this->btnConvert->TabIndex = 0;
			this->btnConvert->Text = S"Con&vert";
			this->btnConvert->Click += new System::EventHandler(this, &CWADConvert::btnConvert_Click);
			// 
			// grpProgress
			// 
			this->grpProgress->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->grpProgress->Controls->Add(this->barProgress);
			this->grpProgress->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->grpProgress->Location = System::Drawing::Point(8, 112);
			this->grpProgress->Name = S"grpProgress";
			this->grpProgress->Size = System::Drawing::Size(360, 48);
			this->grpProgress->TabIndex = 3;
			this->grpProgress->TabStop = false;
			this->grpProgress->Text = S"Progress:";
			// 
			// barProgress
			// 
			this->barProgress->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->barProgress->Location = System::Drawing::Point(8, 16);
			this->barProgress->Name = S"barProgress";
			this->barProgress->Size = System::Drawing::Size(344, 23);
			this->barProgress->TabIndex = 0;
			// 
			// dlgOpenWADFile
			// 
			this->dlgOpenWADFile->Filter = S"WAD Files (*.wad)|*.wad";
			this->dlgOpenWADFile->Title = S"Open WAD File";
			// 
			// dlgOpenFolder
			// 
			this->dlgOpenFolder->Description = S"Select a folder:";
			// 
			// btnOptions
			// 
			this->btnOptions->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left);
			this->btnOptions->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOptions->Location = System::Drawing::Point(8, 320);
			this->btnOptions->Name = S"btnOptions";
			this->btnOptions->Size = System::Drawing::Size(80, 23);
			this->btnOptions->TabIndex = 5;
			this->btnOptions->Text = S"&Options";
			this->btnOptions->Click += new System::EventHandler(this, &CWADConvert::btnOptions_Click);
			// 
			// grpLog
			// 
			this->grpLog->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->grpLog->Controls->Add(this->txtLog);
			this->grpLog->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->grpLog->Location = System::Drawing::Point(8, 168);
			this->grpLog->Name = S"grpLog";
			this->grpLog->Size = System::Drawing::Size(360, 144);
			this->grpLog->TabIndex = 4;
			this->grpLog->TabStop = false;
			this->grpLog->Text = S"Log:";
			// 
			// txtLog
			// 
			this->txtLog->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->txtLog->DetectUrls = false;
			this->txtLog->Location = System::Drawing::Point(8, 16);
			this->txtLog->Name = S"txtLog";
			this->txtLog->ReadOnly = true;
			this->txtLog->Size = System::Drawing::Size(344, 120);
			this->txtLog->TabIndex = 0;
			this->txtLog->Text = S"";
			// 
			// tipMain
			// 
			this->tipMain->AutoPopDelay = 10000;
			this->tipMain->InitialDelay = 500;
			this->tipMain->ReshowDelay = 100;
			// 
			// CWADConvert
			// 
			this->AcceptButton = this->btnConvert;
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->CancelButton = this->btnClose;
			this->ClientSize = System::Drawing::Size(378, 352);
			this->Controls->Add(this->btnOptions);
			this->Controls->Add(this->grpProgress);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnConvert);
			this->Controls->Add(this->grpOptions);
			this->Controls->Add(this->grpLog);
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = S"CWADConvert";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = S"Convert WAD File";
			this->grpOptions->ResumeLayout(false);
			this->grpProgress->ResumeLayout(false);
			this->grpLog->ResumeLayout(false);
			this->ResumeLayout(false);

		}		
		public: __property System::String *get_WADFile()
		{
			return this->txtWADFile->Text;
		}

		public: __property void set_WADFile(System::String *sWADFile)
		{
			if(System::IO::File::Exists(sWADFile))
			{
				this->txtWADFile->Text = sWADFile;
			}
		}

		public: __property System::String *get_OutputFolder()
		{
			return this->txtOutputFolder->Text;
		}

		public: __property void set_OutputFolder(System::String *sOutputFolder)
		{
			if(System::IO::Directory::Exists(sOutputFolder))
			{
				this->txtOutputFolder->Text = sOutputFolder;
			}
		}

		public: __property bool get_CreateVMTFiles()
		{
			return this->chkCreateVMTFiles->Checked == true;
		}

		public: __property void set_CreateVMTFiles(bool bCreateVMTFiles)
		{
			this->chkCreateVMTFiles->Checked = bCreateVMTFiles;
		}

		private: System::Void btnWADFileBrowse_Click(System::Object *  sender, System::EventArgs *  e)
		{
			if(this->dlgOpenWADFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->txtWADFile->Text = this->dlgOpenWADFile->FileName;
			}
		}

		private: System::Void btnOutputFolderBrowse_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->dlgOpenFolder->SelectedPath = this->txtOutputFolder->Text;
			if(this->dlgOpenFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->txtOutputFolder->Text = this->dlgOpenFolder->SelectedPath;
			}
		}

		private: System::Void txtWADFile_TextChanged(System::Object *  sender, System::EventArgs *  e)
		{
			this->btnConvert->Enabled = System::IO::File::Exists(this->txtWADFile->Text) && System::IO::Directory::Exists(this->txtOutputFolder->Text);
		}

		private: System::Void btnConvert_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->Cursor = System::Windows::Forms::Cursors::WaitCursor;

			this->barProgress->Value = 0;
			this->barProgress->Maximum = 1;
			this->txtLog->Clear();

			HLLib::CWADFile WADFile = HLLib::CWADFile();
			VTFLib::CVTFFile VTFFile = VTFLib::CVTFFile();

			SVTFCreateOptions VTFCreateOptions = CVTFFileUtility::GetCreateOptions(this->Options);

			char *cWADFile = (char *)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->txtWADFile->Text)).ToPointer();

			if(!WADFile.Open(cWADFile, HL_MODE_READ))
			{
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cWADFile);

				this->Cursor = System::Windows::Forms::Cursors::Default;

				MessageBox::Show(String::Concat("Error loading WAD file:\n\n", new String(hlGetString(HL_ERROR_LONG_FORMATED))), Application::ProductName, MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cWADFile);

			HLLib::CDirectoryFolder *Root = WADFile.GetRoot();

			this->barProgress->Maximum = Root->GetCount() - 1;

			for(DWORD i = 0; i < Root->GetCount(); i++)
			{
				HLLib::CDirectoryFile *File = static_cast<HLLib::CDirectoryFile *>(Root->GetItem(i));

				String *sVTFName = new String(File->GetName());
				sVTFName = sVTFName->Substring(0, sVTFName->LastIndexOf('.'));
				String *sVTFFile = String::Concat(this->txtOutputFolder->Text, S"\\", sVTFName, S".vtf");
				String *sVMTFile = String::Concat(this->txtOutputFolder->Text, S"\\", sVTFName, S".vmt");

				this->Log(String::Concat(S"Processing ", sVTFName, S"..."), System::Drawing::Color::Gray);

				hlUInt dwPaletteSize, dwPixelSize, dwWidth, dwHeight;
				if(WADFile.GetImageSize(File, dwPaletteSize, dwPixelSize))
				{
					hlByte *lpPaletteData = new hlByte[dwPaletteSize];
					hlByte *lpPixelData = new hlByte[dwPixelSize];

					if(WADFile.GetImageData(File, dwWidth, dwHeight, lpPaletteData, lpPixelData))
					{
						bool bHasAlpha = false;

						vlByte *lpImageData = new vlByte[VTFFile.ComputeImageSize(dwWidth, dwHeight, 1, IMAGE_FORMAT_RGBA8888)];

						// Populate image data.
						for(DWORD i = 0; i < dwWidth; i++)
						{
							for(DWORD j = 0; j < dwHeight; j++)
							{
								DWORD dwPixelIndex = i + j * dwWidth;
								DWORD dwPaletteIndex = lpPixelData[dwPixelIndex];

								dwPixelIndex *= 4;
								dwPaletteIndex *= 3;

								// Populate RGB values.
								for(DWORD k = 0; k < 3; k++)
								{
									lpImageData[dwPixelIndex + k] = lpPaletteData[dwPaletteIndex + k];
								}

								// If we have a transparent texture, compute A value.
								if(sVTFName->get_Chars(0) != '{')
								{
									lpImageData[dwPixelIndex + 3] = 255;
								}
								else
								{
									bHasAlpha = true;
									lpImageData[dwPixelIndex + 3] = dwPaletteIndex / 3 == 255 ? 0 : 255;
								}
							}
						}

						// Create alpha channel for transparent textures.  Assume 0 0 255 is transparent color.
						/*if(sVTFName->get_Chars(0) == '{')
						{
							bHasAlpha = true;

							for(vlByte *lpStart = lpImageData, *lpEnd = lpImageData + VTFFile.ComputeImageSize(dwWidth, dwHeight, IMAGE_FORMAT_RGBA8888); lpStart < lpEnd; lpStart += 4)
							{
								if(lpStart[0] == 0 && lpStart[1] == 0 && lpStart[2] == 255)
								{
									lpStart[3] = 0;
								}
							}
						}*/

						VTFCreateOptions.ImageFormat = bHasAlpha ? Options->AlphaFormat : Options->NormalFormat;

						if(VTFFile.Create(dwWidth, dwHeight, lpImageData, VTFCreateOptions) != vlFalse && CVTFFileUtility::CreateResources(Options, &VTFFile))
						{
							char *cVTFFile = (char *)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sVTFFile)).ToPointer();
							if(VTFFile.Save(cVTFFile))
							{
								this->Log(String::Concat(S"Wrote ", sVTFFile, S"."), System::Drawing::Color::Green);
								if(this->chkCreateVMTFiles->Checked && CVMTFileUtility::CreateDefaultMaterial(sVTFFile, S"LightmappedGeneric", bHasAlpha))
								{
									this->Log(String::Concat(S"Wrote ", sVMTFile, S"."), System::Drawing::Color::Green);
								}
							}
							else
							{
								this->Log(String::Concat(S"Error writing ", sVTFName, S".", (new String(vlGetLastError()))->Replace(S"\n", S" ")), System::Drawing::Color::Red);
							}
							System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cVTFFile);
						}
						else
						{
							this->Log(String::Concat(S"Error creating ", sVTFName, S".", (new String(vlGetLastError()))->Replace(S"\n", S" ")), System::Drawing::Color::Red);
						}

						delete []lpImageData;
					}
					else
					{
						this->Log(String::Concat(S"Error processing ", sVTFName, S":\n\n", (new String(hlGetString(HL_ERROR_LONG_FORMATED)))->Replace(S"\n", S" ")), System::Drawing::Color::Red);
					}

					delete []lpPaletteData;
					delete []lpPixelData;
				}
				else
				{
					this->Log(String::Concat(S"Error processing ", sVTFName, S":\n\n", (new String(hlGetString(HL_ERROR_LONG_FORMATED)))->Replace(S"\n", S" ")), System::Drawing::Color::Red);
				}

				this->Log(String::Concat(sVTFName, S" processed."), System::Drawing::Color::Gray);

				this->barProgress->Value = i;
				this->barProgress->Refresh();
			}

			WADFile.Close();

			this->Cursor = System::Windows::Forms::Cursors::Default;
		}

		private: System::Void btnClose_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		}

		private: System::Void btnOptions_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->Options->ShowDialog();
		}

		private: void Log(String *sString, System::Drawing::Color cColor)
		{
			this->txtLog->Focus();
			this->txtLog->SelectionStart = this->txtLog->TextLength;
			this->txtLog->SelectionColor = cColor;
			this->txtLog->AppendText(String::Concat(sString, S"\n"));
			this->txtLog->Refresh();
		}
	};
}