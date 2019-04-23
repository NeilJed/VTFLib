/*
 * VTFEdit
 * Copyright (C) 2005-2011 Neil Jedrzejewski & Ryan Gregg
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

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace VTFEdit
{
	public __gc class CAbout : public System::Windows::Forms::Form
	{
	public: 
		CAbout(void)
		{
			this->InitializeComponent();

			this->lblVTFLibVersion->Text = String::Concat(S"VTFLib Version: ", new String(vlGetVersionString()));
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
	private: System::Windows::Forms::Button *  btnOK;
	private: System::Windows::Forms::GroupBox *  grpAbout;
	private: System::Windows::Forms::Label *  lblLines;
	private: System::Windows::Forms::Label *  lblLanguage;
	private: System::Windows::Forms::Label *  lblDate;
	private: System::Windows::Forms::Label *  lblAuthor;
	private: System::Windows::Forms::LinkLabel *  lnkNemsTools;
	private: System::Windows::Forms::PictureBox *  picIcon;
	private: System::Windows::Forms::LinkLabel *  lnkWunderboy;
	private: System::Windows::Forms::Label *  lblVTFLibVersion;
	private: System::Windows::Forms::Label *  lblVTFEditVersion;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container* components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(VTFEdit::CAbout));
			this->btnOK = new System::Windows::Forms::Button();
			this->grpAbout = new System::Windows::Forms::GroupBox();
			this->lblVTFLibVersion = new System::Windows::Forms::Label();
			this->lnkWunderboy = new System::Windows::Forms::LinkLabel();
			this->lblLines = new System::Windows::Forms::Label();
			this->lblLanguage = new System::Windows::Forms::Label();
			this->lblDate = new System::Windows::Forms::Label();
			this->lblAuthor = new System::Windows::Forms::Label();
			this->lblVTFEditVersion = new System::Windows::Forms::Label();
			this->lnkNemsTools = new System::Windows::Forms::LinkLabel();
			this->picIcon = new System::Windows::Forms::PictureBox();
			this->grpAbout->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOK->Location = System::Drawing::Point(104, 200);
			this->btnOK->Name = S"btnOK";
			this->btnOK->Size = System::Drawing::Size(80, 23);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = S"&OK";
			this->btnOK->Click += new System::EventHandler(this, &CAbout::btnOK_Click);
			// 
			// grpAbout
			// 
			this->grpAbout->Controls->Add(this->lblVTFLibVersion);
			this->grpAbout->Controls->Add(this->lnkWunderboy);
			this->grpAbout->Controls->Add(this->lblLines);
			this->grpAbout->Controls->Add(this->lblLanguage);
			this->grpAbout->Controls->Add(this->lblDate);
			this->grpAbout->Controls->Add(this->lblAuthor);
			this->grpAbout->Controls->Add(this->lblVTFEditVersion);
			this->grpAbout->Controls->Add(this->lnkNemsTools);
			this->grpAbout->Controls->Add(this->picIcon);
			this->grpAbout->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->grpAbout->Location = System::Drawing::Point(8, 8);
			this->grpAbout->Name = S"grpAbout";
			this->grpAbout->Size = System::Drawing::Size(272, 184);
			this->grpAbout->TabIndex = 1;
			this->grpAbout->TabStop = false;
			// 
			// lblVTFLibVersion
			// 
			this->lblVTFLibVersion->Location = System::Drawing::Point(68, 40);
			this->lblVTFLibVersion->Name = S"lblVTFLibVersion";
			this->lblVTFLibVersion->Size = System::Drawing::Size(136, 16);
			this->lblVTFLibVersion->TabIndex = 0;
			// 
			// lnkWunderboy
			// 
			this->lnkWunderboy->LinkColor = System::Drawing::Color::Black;
			this->lnkWunderboy->Location = System::Drawing::Point(16, 160);
			this->lnkWunderboy->Name = S"lnkWunderboy";
			this->lnkWunderboy->Size = System::Drawing::Size(88, 16);
			this->lnkWunderboy->TabIndex = 6;
			this->lnkWunderboy->TabStop = true;
			this->lnkWunderboy->Text = S"wunderboy.org";
			this->lnkWunderboy->VisitedLinkColor = System::Drawing::Color::Black;
			this->lnkWunderboy->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &CAbout::lnkWunderboy_LinkClicked);
			// 
			// lblLines
			// 
			this->lblLines->Location = System::Drawing::Point(68, 136);
			this->lblLines->Name = S"lblLines";
			this->lblLines->Size = System::Drawing::Size(136, 16);
			this->lblLines->TabIndex = 5;
			this->lblLines->Text = S"Lines: 9,003";
			// 
			// lblLanguage
			// 
			this->lblLanguage->Location = System::Drawing::Point(68, 120);
			this->lblLanguage->Name = S"lblLanguage";
			this->lblLanguage->Size = System::Drawing::Size(136, 16);
			this->lblLanguage->TabIndex = 4;
			this->lblLanguage->Text = S"Written In: C++";
			// 
			// lblDate
			// 
			this->lblDate->Location = System::Drawing::Point(68, 104);
			this->lblDate->Name = S"lblDate";
			this->lblDate->Size = System::Drawing::Size(136, 16);
			this->lblDate->TabIndex = 3;
			this->lblDate->Text = S"Date: July 25, 2011";
			// 
			// lblAuthor
			// 
			this->lblAuthor->Location = System::Drawing::Point(68, 72);
			this->lblAuthor->Name = S"lblAuthor";
			this->lblAuthor->Size = System::Drawing::Size(136, 32);
			this->lblAuthor->TabIndex = 2;
			this->lblAuthor->Text = S"Author: Neil Jedrzejewski && Ryan Gregg";
			// 
			// lblVTFEditVersion
			// 
			this->lblVTFEditVersion->Location = System::Drawing::Point(68, 56);
			this->lblVTFEditVersion->Name = S"lblVTFEditVersion";
			this->lblVTFEditVersion->Size = System::Drawing::Size(136, 16);
			this->lblVTFEditVersion->TabIndex = 1;
			this->lblVTFEditVersion->Text = S"VTFEdit Version: 1.3.3";
			// 
			// lnkNemsTools
			// 
			this->lnkNemsTools->LinkColor = System::Drawing::Color::Black;
			this->lnkNemsTools->Location = System::Drawing::Point(176, 160);
			this->lnkNemsTools->Name = S"lnkNemsTools";
			this->lnkNemsTools->Size = System::Drawing::Size(88, 16);
			this->lnkNemsTools->TabIndex = 7;
			this->lnkNemsTools->TabStop = true;
			this->lnkNemsTools->Text = S"nemesis.twl.net";
			this->lnkNemsTools->VisitedLinkColor = System::Drawing::Color::Black;
			this->lnkNemsTools->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &CAbout::lnkNemsTools_LinkClicked);
			// 
			// picIcon
			// 
			this->picIcon->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"picIcon.Image")));
			this->picIcon->Location = System::Drawing::Point(8, 16);
			this->picIcon->Name = S"picIcon";
			this->picIcon->Size = System::Drawing::Size(32, 32);
			this->picIcon->TabIndex = 0;
			this->picIcon->TabStop = false;
			// 
			// CAbout
			// 
			this->AcceptButton = this->btnOK;
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(288, 232);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->grpAbout);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = S"CAbout";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = S"About VTFEdit";
			this->grpAbout->ResumeLayout(false);
			this->ResumeLayout(false);

		}		

		private: System::Void lnkWunderboy_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		{
			try
			{
				System::Diagnostics::Process::Start(S"http://www.wunderboy.org/");
			}
			catch(Exception *)
			{

			}
		}

		private: System::Void lnkNemsTools_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		{
			try
			{
				System::Diagnostics::Process::Start(S"http://nemesis.thewavelength.net/");
			}
			catch(Exception *)
			{

			}
		}

		private: System::Void btnOK_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->Close();
		}
	};
}