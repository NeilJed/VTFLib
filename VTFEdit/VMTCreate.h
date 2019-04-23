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

#include "VMTFileUtility.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace VTFEdit
{
	public __gc class CVMTCreate : public System::Windows::Forms::Form
	{
	public: 
		CVMTCreate(void)
		{
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

	private: System::Windows::Forms::OpenFileDialog *  dlgOpenVTFFile;
	private: System::Windows::Forms::GroupBox *  grpTextures;
	private: System::Windows::Forms::Button *  btnBaseTexture1;
	private: System::Windows::Forms::TextBox *  txtBaseTexture1;
	private: System::Windows::Forms::Label *  lblBaseTexture1;
	private: System::Windows::Forms::TabControl *  tabMain;
	private: System::Windows::Forms::TabPage *  tabTextures;
	private: System::Windows::Forms::Button *  btnBumpTexture1;
	private: System::Windows::Forms::TextBox *  txtBumpTexture1;
	private: System::Windows::Forms::Label *  lblBumpTexture1;
	private: System::Windows::Forms::Button *  btnEnviromentTexture;
	private: System::Windows::Forms::TextBox *  txtEnviromentTexture;
	private: System::Windows::Forms::Label *  lblEnviromentTexture;
	private: System::Windows::Forms::Button *  btnEnviromentMaskTexture;
	private: System::Windows::Forms::TextBox *  txtEnviromentMaskTexture;
	private: System::Windows::Forms::Label *  lblEnviromentMaskTexture;
	private: System::Windows::Forms::Button *  btnDetailTexture;
	private: System::Windows::Forms::TextBox *  txtDetailTexture;
	private: System::Windows::Forms::Label *  lblDetailTexture;
	private: System::Windows::Forms::ToolTip *  tipMain;
	private: System::Windows::Forms::Button *  btnClose;
	private: System::Windows::Forms::Button *  btnCreate;
	private: System::Windows::Forms::Button *  btnToolTexture;
	private: System::Windows::Forms::TextBox *  txtToolTexture;
	private: System::Windows::Forms::Label *  lblToolTexture;
	private: System::Windows::Forms::Button *  btnBumpTexture2;
	private: System::Windows::Forms::TextBox *  txtBumpTexture2;
	private: System::Windows::Forms::Label *  lblBumpTexture2;
	private: System::Windows::Forms::Label *  lblBaseTexture2;
	private: System::Windows::Forms::Button *  btnNormalTexture;
	private: System::Windows::Forms::TextBox *  txtNormalTexture;
	private: System::Windows::Forms::Label *  lblNormalTexture;
	private: System::Windows::Forms::Button *  btnDuDvTexture;
	private: System::Windows::Forms::TextBox *  txtDuDvTexture;
	private: System::Windows::Forms::Label *  lblDuDvTexture;
	private: System::Windows::Forms::Button *  btnBaseTexture2;
	private: System::Windows::Forms::TextBox *  txtBaseTexture2;
	private: System::Windows::Forms::TabPage *  tabOptions;
	private: System::Windows::Forms::GroupBox *  grpOptions;
	private: System::Windows::Forms::Button *  btnClear;
	private: System::Windows::Forms::SaveFileDialog *  dlgSaveVMTFile;
	private: System::Windows::Forms::Label *  lblShader;
	private: System::Windows::Forms::ComboBox *  cboShader;
	private: System::Windows::Forms::ComboBox *  cboSurface1;
	private: System::Windows::Forms::Label *  lblSurface1;
	private: System::Windows::Forms::ComboBox *  cboSurface2;
	private: System::Windows::Forms::Label *  lblSurface2;
	private: System::Windows::Forms::Label *  lblKeywords;
	private: System::Windows::Forms::TextBox *  txtKeywords;
	private: System::Windows::Forms::CheckBox *  chkTranslucent;
	private: System::Windows::Forms::CheckBox *  chkAdditive;
	private: System::Windows::Forms::CheckBox *  chkEnviromentMapContrast;
	private: System::Windows::Forms::CheckBox *  chkEnviromentMapSaturation;
	private: System::Windows::Forms::CheckBox *  chkNoCull;
	private: System::Windows::Forms::CheckBox *  chkAlphaTest;
	private: System::Windows::Forms::CheckBox *  chkNoLOD;
	private: System::Windows::Forms::CheckBox *  chkNoDecal;
	private: System::Windows::Forms::CheckBox *  chkVertexColor;
	private: System::Windows::Forms::CheckBox *  chkVertexAlpha;
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
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(VTFEdit::CVMTCreate));
			this->grpTextures = new System::Windows::Forms::GroupBox();
			this->btnNormalTexture = new System::Windows::Forms::Button();
			this->txtNormalTexture = new System::Windows::Forms::TextBox();
			this->lblNormalTexture = new System::Windows::Forms::Label();
			this->btnDuDvTexture = new System::Windows::Forms::Button();
			this->txtDuDvTexture = new System::Windows::Forms::TextBox();
			this->lblDuDvTexture = new System::Windows::Forms::Label();
			this->btnBumpTexture2 = new System::Windows::Forms::Button();
			this->txtBumpTexture2 = new System::Windows::Forms::TextBox();
			this->lblBumpTexture2 = new System::Windows::Forms::Label();
			this->btnBaseTexture2 = new System::Windows::Forms::Button();
			this->txtBaseTexture2 = new System::Windows::Forms::TextBox();
			this->lblBaseTexture2 = new System::Windows::Forms::Label();
			this->btnToolTexture = new System::Windows::Forms::Button();
			this->txtToolTexture = new System::Windows::Forms::TextBox();
			this->lblToolTexture = new System::Windows::Forms::Label();
			this->btnDetailTexture = new System::Windows::Forms::Button();
			this->txtDetailTexture = new System::Windows::Forms::TextBox();
			this->lblDetailTexture = new System::Windows::Forms::Label();
			this->btnEnviromentMaskTexture = new System::Windows::Forms::Button();
			this->txtEnviromentMaskTexture = new System::Windows::Forms::TextBox();
			this->lblEnviromentMaskTexture = new System::Windows::Forms::Label();
			this->btnEnviromentTexture = new System::Windows::Forms::Button();
			this->txtEnviromentTexture = new System::Windows::Forms::TextBox();
			this->lblEnviromentTexture = new System::Windows::Forms::Label();
			this->btnBumpTexture1 = new System::Windows::Forms::Button();
			this->txtBumpTexture1 = new System::Windows::Forms::TextBox();
			this->lblBumpTexture1 = new System::Windows::Forms::Label();
			this->btnBaseTexture1 = new System::Windows::Forms::Button();
			this->txtBaseTexture1 = new System::Windows::Forms::TextBox();
			this->lblBaseTexture1 = new System::Windows::Forms::Label();
			this->dlgOpenVTFFile = new System::Windows::Forms::OpenFileDialog();
			this->tabMain = new System::Windows::Forms::TabControl();
			this->tabTextures = new System::Windows::Forms::TabPage();
			this->tabOptions = new System::Windows::Forms::TabPage();
			this->grpOptions = new System::Windows::Forms::GroupBox();
			this->chkVertexAlpha = new System::Windows::Forms::CheckBox();
			this->chkVertexColor = new System::Windows::Forms::CheckBox();
			this->chkNoDecal = new System::Windows::Forms::CheckBox();
			this->chkNoLOD = new System::Windows::Forms::CheckBox();
			this->chkAlphaTest = new System::Windows::Forms::CheckBox();
			this->chkNoCull = new System::Windows::Forms::CheckBox();
			this->chkEnviromentMapSaturation = new System::Windows::Forms::CheckBox();
			this->chkEnviromentMapContrast = new System::Windows::Forms::CheckBox();
			this->chkAdditive = new System::Windows::Forms::CheckBox();
			this->chkTranslucent = new System::Windows::Forms::CheckBox();
			this->txtKeywords = new System::Windows::Forms::TextBox();
			this->lblKeywords = new System::Windows::Forms::Label();
			this->cboSurface2 = new System::Windows::Forms::ComboBox();
			this->lblSurface2 = new System::Windows::Forms::Label();
			this->cboSurface1 = new System::Windows::Forms::ComboBox();
			this->lblSurface1 = new System::Windows::Forms::Label();
			this->cboShader = new System::Windows::Forms::ComboBox();
			this->lblShader = new System::Windows::Forms::Label();
			this->tipMain = new System::Windows::Forms::ToolTip(this->components);
			this->btnClose = new System::Windows::Forms::Button();
			this->btnCreate = new System::Windows::Forms::Button();
			this->btnClear = new System::Windows::Forms::Button();
			this->dlgSaveVMTFile = new System::Windows::Forms::SaveFileDialog();
			this->grpTextures->SuspendLayout();
			this->tabMain->SuspendLayout();
			this->tabTextures->SuspendLayout();
			this->tabOptions->SuspendLayout();
			this->grpOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpTextures
			// 
			this->grpTextures->Controls->Add(this->btnNormalTexture);
			this->grpTextures->Controls->Add(this->txtNormalTexture);
			this->grpTextures->Controls->Add(this->lblNormalTexture);
			this->grpTextures->Controls->Add(this->btnDuDvTexture);
			this->grpTextures->Controls->Add(this->txtDuDvTexture);
			this->grpTextures->Controls->Add(this->lblDuDvTexture);
			this->grpTextures->Controls->Add(this->btnBumpTexture2);
			this->grpTextures->Controls->Add(this->txtBumpTexture2);
			this->grpTextures->Controls->Add(this->lblBumpTexture2);
			this->grpTextures->Controls->Add(this->btnBaseTexture2);
			this->grpTextures->Controls->Add(this->txtBaseTexture2);
			this->grpTextures->Controls->Add(this->lblBaseTexture2);
			this->grpTextures->Controls->Add(this->btnToolTexture);
			this->grpTextures->Controls->Add(this->txtToolTexture);
			this->grpTextures->Controls->Add(this->lblToolTexture);
			this->grpTextures->Controls->Add(this->btnDetailTexture);
			this->grpTextures->Controls->Add(this->txtDetailTexture);
			this->grpTextures->Controls->Add(this->lblDetailTexture);
			this->grpTextures->Controls->Add(this->btnEnviromentMaskTexture);
			this->grpTextures->Controls->Add(this->txtEnviromentMaskTexture);
			this->grpTextures->Controls->Add(this->lblEnviromentMaskTexture);
			this->grpTextures->Controls->Add(this->btnEnviromentTexture);
			this->grpTextures->Controls->Add(this->txtEnviromentTexture);
			this->grpTextures->Controls->Add(this->lblEnviromentTexture);
			this->grpTextures->Controls->Add(this->btnBumpTexture1);
			this->grpTextures->Controls->Add(this->txtBumpTexture1);
			this->grpTextures->Controls->Add(this->lblBumpTexture1);
			this->grpTextures->Controls->Add(this->btnBaseTexture1);
			this->grpTextures->Controls->Add(this->txtBaseTexture1);
			this->grpTextures->Controls->Add(this->lblBaseTexture1);
			this->grpTextures->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->grpTextures->Location = System::Drawing::Point(8, 8);
			this->grpTextures->Name = S"grpTextures";
			this->grpTextures->Size = System::Drawing::Size(336, 264);
			this->grpTextures->TabIndex = 0;
			this->grpTextures->TabStop = false;
			this->grpTextures->Text = S"Textures:";
			// 
			// btnNormalTexture
			// 
			this->btnNormalTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnNormalTexture->Location = System::Drawing::Point(304, 208);
			this->btnNormalTexture->Name = S"btnNormalTexture";
			this->btnNormalTexture->Size = System::Drawing::Size(20, 20);
			this->btnNormalTexture->TabIndex = 26;
			this->btnNormalTexture->Text = S"...";
			this->btnNormalTexture->Click += new System::EventHandler(this, &CVMTCreate::btnNormalTexture_Click);
			// 
			// txtNormalTexture
			// 
			this->txtNormalTexture->Location = System::Drawing::Point(96, 208);
			this->txtNormalTexture->Name = S"txtNormalTexture";
			this->txtNormalTexture->Size = System::Drawing::Size(200, 20);
			this->txtNormalTexture->TabIndex = 25;
			this->txtNormalTexture->Text = S"";
			this->tipMain->SetToolTip(this->txtNormalTexture, S"$normalmap");
			this->txtNormalTexture->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblNormalTexture
			// 
			this->lblNormalTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblNormalTexture->Location = System::Drawing::Point(8, 208);
			this->lblNormalTexture->Name = S"lblNormalTexture";
			this->lblNormalTexture->Size = System::Drawing::Size(88, 23);
			this->lblNormalTexture->TabIndex = 24;
			this->lblNormalTexture->Text = S"Normal Map:";
			// 
			// btnDuDvTexture
			// 
			this->btnDuDvTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnDuDvTexture->Location = System::Drawing::Point(304, 232);
			this->btnDuDvTexture->Name = S"btnDuDvTexture";
			this->btnDuDvTexture->Size = System::Drawing::Size(20, 20);
			this->btnDuDvTexture->TabIndex = 29;
			this->btnDuDvTexture->Text = S"...";
			this->btnDuDvTexture->Click += new System::EventHandler(this, &CVMTCreate::btnDuDvTexture_Click);
			// 
			// txtDuDvTexture
			// 
			this->txtDuDvTexture->Location = System::Drawing::Point(96, 232);
			this->txtDuDvTexture->Name = S"txtDuDvTexture";
			this->txtDuDvTexture->Size = System::Drawing::Size(200, 20);
			this->txtDuDvTexture->TabIndex = 28;
			this->txtDuDvTexture->Text = S"";
			this->tipMain->SetToolTip(this->txtDuDvTexture, S"$dudvmap");
			this->txtDuDvTexture->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblDuDvTexture
			// 
			this->lblDuDvTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblDuDvTexture->Location = System::Drawing::Point(8, 232);
			this->lblDuDvTexture->Name = S"lblDuDvTexture";
			this->lblDuDvTexture->Size = System::Drawing::Size(88, 23);
			this->lblDuDvTexture->TabIndex = 27;
			this->lblDuDvTexture->Text = S"DuDv Map:";
			// 
			// btnBumpTexture2
			// 
			this->btnBumpTexture2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBumpTexture2->Location = System::Drawing::Point(304, 88);
			this->btnBumpTexture2->Name = S"btnBumpTexture2";
			this->btnBumpTexture2->Size = System::Drawing::Size(20, 20);
			this->btnBumpTexture2->TabIndex = 11;
			this->btnBumpTexture2->Text = S"...";
			this->btnBumpTexture2->Click += new System::EventHandler(this, &CVMTCreate::btnBumpTexture2_Click);
			// 
			// txtBumpTexture2
			// 
			this->txtBumpTexture2->Location = System::Drawing::Point(96, 88);
			this->txtBumpTexture2->Name = S"txtBumpTexture2";
			this->txtBumpTexture2->Size = System::Drawing::Size(200, 20);
			this->txtBumpTexture2->TabIndex = 10;
			this->txtBumpTexture2->Text = S"";
			this->tipMain->SetToolTip(this->txtBumpTexture2, S"$bumpmap2");
			this->txtBumpTexture2->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblBumpTexture2
			// 
			this->lblBumpTexture2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblBumpTexture2->Location = System::Drawing::Point(8, 88);
			this->lblBumpTexture2->Name = S"lblBumpTexture2";
			this->lblBumpTexture2->Size = System::Drawing::Size(88, 23);
			this->lblBumpTexture2->TabIndex = 9;
			this->lblBumpTexture2->Text = S"Bump Map 2:";
			// 
			// btnBaseTexture2
			// 
			this->btnBaseTexture2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBaseTexture2->Location = System::Drawing::Point(304, 64);
			this->btnBaseTexture2->Name = S"btnBaseTexture2";
			this->btnBaseTexture2->Size = System::Drawing::Size(20, 20);
			this->btnBaseTexture2->TabIndex = 8;
			this->btnBaseTexture2->Text = S"...";
			this->btnBaseTexture2->Click += new System::EventHandler(this, &CVMTCreate::btnBaseTexture2_Click);
			// 
			// txtBaseTexture2
			// 
			this->txtBaseTexture2->Location = System::Drawing::Point(96, 64);
			this->txtBaseTexture2->Name = S"txtBaseTexture2";
			this->txtBaseTexture2->Size = System::Drawing::Size(200, 20);
			this->txtBaseTexture2->TabIndex = 7;
			this->txtBaseTexture2->Text = S"";
			this->tipMain->SetToolTip(this->txtBaseTexture2, S"$basetexture2");
			this->txtBaseTexture2->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblBaseTexture2
			// 
			this->lblBaseTexture2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblBaseTexture2->Location = System::Drawing::Point(8, 64);
			this->lblBaseTexture2->Name = S"lblBaseTexture2";
			this->lblBaseTexture2->Size = System::Drawing::Size(88, 23);
			this->lblBaseTexture2->TabIndex = 6;
			this->lblBaseTexture2->Text = S"Base Texture 2:";
			// 
			// btnToolTexture
			// 
			this->btnToolTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnToolTexture->Location = System::Drawing::Point(304, 184);
			this->btnToolTexture->Name = S"btnToolTexture";
			this->btnToolTexture->Size = System::Drawing::Size(20, 20);
			this->btnToolTexture->TabIndex = 23;
			this->btnToolTexture->Text = S"...";
			this->btnToolTexture->Click += new System::EventHandler(this, &CVMTCreate::btnToolTexture_Click);
			// 
			// txtToolTexture
			// 
			this->txtToolTexture->Location = System::Drawing::Point(96, 184);
			this->txtToolTexture->Name = S"txtToolTexture";
			this->txtToolTexture->Size = System::Drawing::Size(200, 20);
			this->txtToolTexture->TabIndex = 22;
			this->txtToolTexture->Text = S"";
			this->tipMain->SetToolTip(this->txtToolTexture, S"%tooltexture");
			this->txtToolTexture->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblToolTexture
			// 
			this->lblToolTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblToolTexture->Location = System::Drawing::Point(8, 184);
			this->lblToolTexture->Name = S"lblToolTexture";
			this->lblToolTexture->Size = System::Drawing::Size(88, 23);
			this->lblToolTexture->TabIndex = 21;
			this->lblToolTexture->Text = S"Tool Texture:";
			// 
			// btnDetailTexture
			// 
			this->btnDetailTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnDetailTexture->Location = System::Drawing::Point(304, 160);
			this->btnDetailTexture->Name = S"btnDetailTexture";
			this->btnDetailTexture->Size = System::Drawing::Size(20, 20);
			this->btnDetailTexture->TabIndex = 20;
			this->btnDetailTexture->Text = S"...";
			this->btnDetailTexture->Click += new System::EventHandler(this, &CVMTCreate::btnDetailTexture_Click);
			// 
			// txtDetailTexture
			// 
			this->txtDetailTexture->Location = System::Drawing::Point(96, 160);
			this->txtDetailTexture->Name = S"txtDetailTexture";
			this->txtDetailTexture->Size = System::Drawing::Size(200, 20);
			this->txtDetailTexture->TabIndex = 19;
			this->txtDetailTexture->Text = S"";
			this->tipMain->SetToolTip(this->txtDetailTexture, S"$detail");
			this->txtDetailTexture->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblDetailTexture
			// 
			this->lblDetailTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblDetailTexture->Location = System::Drawing::Point(8, 160);
			this->lblDetailTexture->Name = S"lblDetailTexture";
			this->lblDetailTexture->Size = System::Drawing::Size(88, 23);
			this->lblDetailTexture->TabIndex = 18;
			this->lblDetailTexture->Text = S"Detail Texture:";
			// 
			// btnEnviromentMaskTexture
			// 
			this->btnEnviromentMaskTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnEnviromentMaskTexture->Location = System::Drawing::Point(304, 136);
			this->btnEnviromentMaskTexture->Name = S"btnEnviromentMaskTexture";
			this->btnEnviromentMaskTexture->Size = System::Drawing::Size(20, 20);
			this->btnEnviromentMaskTexture->TabIndex = 17;
			this->btnEnviromentMaskTexture->Text = S"...";
			this->btnEnviromentMaskTexture->Click += new System::EventHandler(this, &CVMTCreate::btnEnviromentMaskTexture_Click);
			// 
			// txtEnviromentMaskTexture
			// 
			this->txtEnviromentMaskTexture->Location = System::Drawing::Point(96, 136);
			this->txtEnviromentMaskTexture->Name = S"txtEnviromentMaskTexture";
			this->txtEnviromentMaskTexture->Size = System::Drawing::Size(200, 20);
			this->txtEnviromentMaskTexture->TabIndex = 16;
			this->txtEnviromentMaskTexture->Text = S"";
			this->tipMain->SetToolTip(this->txtEnviromentMaskTexture, S"$envmapmask");
			this->txtEnviromentMaskTexture->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblEnviromentMaskTexture
			// 
			this->lblEnviromentMaskTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblEnviromentMaskTexture->Location = System::Drawing::Point(8, 136);
			this->lblEnviromentMaskTexture->Name = S"lblEnviromentMaskTexture";
			this->lblEnviromentMaskTexture->Size = System::Drawing::Size(88, 23);
			this->lblEnviromentMaskTexture->TabIndex = 15;
			this->lblEnviromentMaskTexture->Text = S"Enviroment Mask:";
			// 
			// btnEnviromentTexture
			// 
			this->btnEnviromentTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnEnviromentTexture->Location = System::Drawing::Point(304, 112);
			this->btnEnviromentTexture->Name = S"btnEnviromentTexture";
			this->btnEnviromentTexture->Size = System::Drawing::Size(20, 20);
			this->btnEnviromentTexture->TabIndex = 14;
			this->btnEnviromentTexture->Text = S"...";
			this->btnEnviromentTexture->Click += new System::EventHandler(this, &CVMTCreate::btnEnviromentTexture_Click);
			// 
			// txtEnviromentTexture
			// 
			this->txtEnviromentTexture->Location = System::Drawing::Point(96, 112);
			this->txtEnviromentTexture->Name = S"txtEnviromentTexture";
			this->txtEnviromentTexture->Size = System::Drawing::Size(200, 20);
			this->txtEnviromentTexture->TabIndex = 13;
			this->txtEnviromentTexture->Text = S"";
			this->tipMain->SetToolTip(this->txtEnviromentTexture, S"$envmap");
			this->txtEnviromentTexture->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblEnviromentTexture
			// 
			this->lblEnviromentTexture->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblEnviromentTexture->Location = System::Drawing::Point(8, 112);
			this->lblEnviromentTexture->Name = S"lblEnviromentTexture";
			this->lblEnviromentTexture->Size = System::Drawing::Size(88, 23);
			this->lblEnviromentTexture->TabIndex = 12;
			this->lblEnviromentTexture->Text = S"Enviroment:";
			// 
			// btnBumpTexture1
			// 
			this->btnBumpTexture1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBumpTexture1->Location = System::Drawing::Point(304, 40);
			this->btnBumpTexture1->Name = S"btnBumpTexture1";
			this->btnBumpTexture1->Size = System::Drawing::Size(20, 20);
			this->btnBumpTexture1->TabIndex = 5;
			this->btnBumpTexture1->Text = S"...";
			this->btnBumpTexture1->Click += new System::EventHandler(this, &CVMTCreate::btnBumpTexture1_Click);
			// 
			// txtBumpTexture1
			// 
			this->txtBumpTexture1->Location = System::Drawing::Point(96, 40);
			this->txtBumpTexture1->Name = S"txtBumpTexture1";
			this->txtBumpTexture1->Size = System::Drawing::Size(200, 20);
			this->txtBumpTexture1->TabIndex = 4;
			this->txtBumpTexture1->Text = S"";
			this->tipMain->SetToolTip(this->txtBumpTexture1, S"$bumpmap");
			this->txtBumpTexture1->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblBumpTexture1
			// 
			this->lblBumpTexture1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblBumpTexture1->Location = System::Drawing::Point(8, 40);
			this->lblBumpTexture1->Name = S"lblBumpTexture1";
			this->lblBumpTexture1->Size = System::Drawing::Size(88, 23);
			this->lblBumpTexture1->TabIndex = 3;
			this->lblBumpTexture1->Text = S"Bump Map 1:";
			// 
			// btnBaseTexture1
			// 
			this->btnBaseTexture1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBaseTexture1->Location = System::Drawing::Point(304, 16);
			this->btnBaseTexture1->Name = S"btnBaseTexture1";
			this->btnBaseTexture1->Size = System::Drawing::Size(20, 20);
			this->btnBaseTexture1->TabIndex = 2;
			this->btnBaseTexture1->Text = S"...";
			this->btnBaseTexture1->Click += new System::EventHandler(this, &CVMTCreate::btnBaseTexture1_Click);
			// 
			// txtBaseTexture1
			// 
			this->txtBaseTexture1->Location = System::Drawing::Point(96, 16);
			this->txtBaseTexture1->Name = S"txtBaseTexture1";
			this->txtBaseTexture1->Size = System::Drawing::Size(200, 20);
			this->txtBaseTexture1->TabIndex = 1;
			this->txtBaseTexture1->Text = S"";
			this->tipMain->SetToolTip(this->txtBaseTexture1, S"$basetexture");
			this->txtBaseTexture1->TextChanged += new System::EventHandler(this, &CVMTCreate::txtBaseTexture1_TextChanged);
			this->txtBaseTexture1->Leave += new System::EventHandler(this, &CVMTCreate::txtTexture_Leave);
			// 
			// lblBaseTexture1
			// 
			this->lblBaseTexture1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblBaseTexture1->Location = System::Drawing::Point(8, 16);
			this->lblBaseTexture1->Name = S"lblBaseTexture1";
			this->lblBaseTexture1->Size = System::Drawing::Size(88, 23);
			this->lblBaseTexture1->TabIndex = 0;
			this->lblBaseTexture1->Text = S"Base Texture 1:";
			// 
			// dlgOpenVTFFile
			// 
			this->dlgOpenVTFFile->Filter = S"VTF Files (*.vtf)|*.vtf";
			this->dlgOpenVTFFile->Title = S"Open VTF File";
			// 
			// tabMain
			// 
			this->tabMain->Controls->Add(this->tabTextures);
			this->tabMain->Controls->Add(this->tabOptions);
			this->tabMain->Location = System::Drawing::Point(8, 8);
			this->tabMain->Name = S"tabMain";
			this->tabMain->SelectedIndex = 0;
			this->tabMain->Size = System::Drawing::Size(360, 304);
			this->tabMain->TabIndex = 0;
			// 
			// tabTextures
			// 
			this->tabTextures->Controls->Add(this->grpTextures);
			this->tabTextures->Location = System::Drawing::Point(4, 22);
			this->tabTextures->Name = S"tabTextures";
			this->tabTextures->Size = System::Drawing::Size(352, 278);
			this->tabTextures->TabIndex = 0;
			this->tabTextures->Text = S"Textures";
			// 
			// tabOptions
			// 
			this->tabOptions->Controls->Add(this->grpOptions);
			this->tabOptions->Location = System::Drawing::Point(4, 22);
			this->tabOptions->Name = S"tabOptions";
			this->tabOptions->Size = System::Drawing::Size(352, 278);
			this->tabOptions->TabIndex = 1;
			this->tabOptions->Text = S"Options";
			// 
			// grpOptions
			// 
			this->grpOptions->Controls->Add(this->chkVertexAlpha);
			this->grpOptions->Controls->Add(this->chkVertexColor);
			this->grpOptions->Controls->Add(this->chkNoDecal);
			this->grpOptions->Controls->Add(this->chkNoLOD);
			this->grpOptions->Controls->Add(this->chkAlphaTest);
			this->grpOptions->Controls->Add(this->chkNoCull);
			this->grpOptions->Controls->Add(this->chkEnviromentMapSaturation);
			this->grpOptions->Controls->Add(this->chkEnviromentMapContrast);
			this->grpOptions->Controls->Add(this->chkAdditive);
			this->grpOptions->Controls->Add(this->chkTranslucent);
			this->grpOptions->Controls->Add(this->txtKeywords);
			this->grpOptions->Controls->Add(this->lblKeywords);
			this->grpOptions->Controls->Add(this->cboSurface2);
			this->grpOptions->Controls->Add(this->lblSurface2);
			this->grpOptions->Controls->Add(this->cboSurface1);
			this->grpOptions->Controls->Add(this->lblSurface1);
			this->grpOptions->Controls->Add(this->cboShader);
			this->grpOptions->Controls->Add(this->lblShader);
			this->grpOptions->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->grpOptions->Location = System::Drawing::Point(8, 8);
			this->grpOptions->Name = S"grpOptions";
			this->grpOptions->Size = System::Drawing::Size(336, 264);
			this->grpOptions->TabIndex = 0;
			this->grpOptions->TabStop = false;
			this->grpOptions->Text = S"Options:";
			// 
			// chkVertexAlpha
			// 
			this->chkVertexAlpha->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkVertexAlpha->Location = System::Drawing::Point(168, 160);
			this->chkVertexAlpha->Name = S"chkVertexAlpha";
			this->chkVertexAlpha->Size = System::Drawing::Size(160, 24);
			this->chkVertexAlpha->TabIndex = 16;
			this->chkVertexAlpha->Text = S"Vertex Alpha";
			this->tipMain->SetToolTip(this->chkVertexAlpha, S"$vertexalpha");
			// 
			// chkVertexColor
			// 
			this->chkVertexColor->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkVertexColor->Location = System::Drawing::Point(168, 184);
			this->chkVertexColor->Name = S"chkVertexColor";
			this->chkVertexColor->Size = System::Drawing::Size(160, 24);
			this->chkVertexColor->TabIndex = 17;
			this->chkVertexColor->Text = S"Vertex Color";
			this->tipMain->SetToolTip(this->chkVertexColor, S"$vertexcolor");
			// 
			// chkNoDecal
			// 
			this->chkNoDecal->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkNoDecal->Location = System::Drawing::Point(8, 232);
			this->chkNoDecal->Name = S"chkNoDecal";
			this->chkNoDecal->Size = System::Drawing::Size(160, 24);
			this->chkNoDecal->TabIndex = 13;
			this->chkNoDecal->Text = S"No Decal";
			this->tipMain->SetToolTip(this->chkNoDecal, S"$nodecal");
			// 
			// chkNoLOD
			// 
			this->chkNoLOD->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkNoLOD->Location = System::Drawing::Point(168, 112);
			this->chkNoLOD->Name = S"chkNoLOD";
			this->chkNoLOD->Size = System::Drawing::Size(160, 24);
			this->chkNoLOD->TabIndex = 14;
			this->chkNoLOD->Text = S"No LOD";
			this->tipMain->SetToolTip(this->chkNoLOD, S"$nolod");
			// 
			// chkAlphaTest
			// 
			this->chkAlphaTest->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkAlphaTest->Location = System::Drawing::Point(8, 136);
			this->chkAlphaTest->Name = S"chkAlphaTest";
			this->chkAlphaTest->Size = System::Drawing::Size(160, 24);
			this->chkAlphaTest->TabIndex = 9;
			this->chkAlphaTest->Text = S"Alpha Test";
			this->tipMain->SetToolTip(this->chkAlphaTest, S"$alphatest");
			// 
			// chkNoCull
			// 
			this->chkNoCull->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkNoCull->Location = System::Drawing::Point(8, 208);
			this->chkNoCull->Name = S"chkNoCull";
			this->chkNoCull->Size = System::Drawing::Size(160, 24);
			this->chkNoCull->TabIndex = 12;
			this->chkNoCull->Text = S"No Cull";
			this->tipMain->SetToolTip(this->chkNoCull, S"$nocull");
			// 
			// chkEnviromentMapSaturation
			// 
			this->chkEnviromentMapSaturation->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkEnviromentMapSaturation->Location = System::Drawing::Point(8, 184);
			this->chkEnviromentMapSaturation->Name = S"chkEnviromentMapSaturation";
			this->chkEnviromentMapSaturation->Size = System::Drawing::Size(160, 24);
			this->chkEnviromentMapSaturation->TabIndex = 11;
			this->chkEnviromentMapSaturation->Text = S"Enviroment Map Saturation";
			this->tipMain->SetToolTip(this->chkEnviromentMapSaturation, S"$envmapsaturation");
			// 
			// chkEnviromentMapContrast
			// 
			this->chkEnviromentMapContrast->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkEnviromentMapContrast->Location = System::Drawing::Point(8, 160);
			this->chkEnviromentMapContrast->Name = S"chkEnviromentMapContrast";
			this->chkEnviromentMapContrast->Size = System::Drawing::Size(160, 24);
			this->chkEnviromentMapContrast->TabIndex = 10;
			this->chkEnviromentMapContrast->Text = S"Enviroment Map Contrast";
			this->tipMain->SetToolTip(this->chkEnviromentMapContrast, S"$envmapcontrast");
			// 
			// chkAdditive
			// 
			this->chkAdditive->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkAdditive->Location = System::Drawing::Point(8, 112);
			this->chkAdditive->Name = S"chkAdditive";
			this->chkAdditive->Size = System::Drawing::Size(160, 24);
			this->chkAdditive->TabIndex = 8;
			this->chkAdditive->Text = S"Additive";
			this->tipMain->SetToolTip(this->chkAdditive, S"$additive");
			// 
			// chkTranslucent
			// 
			this->chkTranslucent->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chkTranslucent->Location = System::Drawing::Point(168, 136);
			this->chkTranslucent->Name = S"chkTranslucent";
			this->chkTranslucent->Size = System::Drawing::Size(160, 24);
			this->chkTranslucent->TabIndex = 15;
			this->chkTranslucent->Text = S"Translucent";
			this->tipMain->SetToolTip(this->chkTranslucent, S"$translucent");
			// 
			// txtKeywords
			// 
			this->txtKeywords->Location = System::Drawing::Point(96, 88);
			this->txtKeywords->Name = S"txtKeywords";
			this->txtKeywords->Size = System::Drawing::Size(232, 20);
			this->txtKeywords->TabIndex = 7;
			this->txtKeywords->Text = S"";
			this->tipMain->SetToolTip(this->txtKeywords, S"%keywords");
			// 
			// lblKeywords
			// 
			this->lblKeywords->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblKeywords->Location = System::Drawing::Point(8, 88);
			this->lblKeywords->Name = S"lblKeywords";
			this->lblKeywords->Size = System::Drawing::Size(88, 23);
			this->lblKeywords->TabIndex = 6;
			this->lblKeywords->Text = S"Keywords:";
			// 
			// cboSurface2
			// 
			System::Object* __mcTemp__1[] = new System::Object*[42];
			__mcTemp__1[0] = S"AlienFlesh";
			__mcTemp__1[1] = S"ArmorFlesh";
			__mcTemp__1[2] = S"BloodyFlesh";
			__mcTemp__1[3] = S"Boulder";
			__mcTemp__1[4] = S"Brick";
			__mcTemp__1[5] = S"Chain";
			__mcTemp__1[6] = S"Chainlink";
			__mcTemp__1[7] = S"Computer";
			__mcTemp__1[8] = S"Concrete";
			__mcTemp__1[9] = S"Concrete_Block";
			__mcTemp__1[10] = S"Default";
			__mcTemp__1[11] = S"Dirt";
			__mcTemp__1[12] = S"Flesh";
			__mcTemp__1[13] = S"Glass";
			__mcTemp__1[14] = S"Grass";
			__mcTemp__1[15] = S"Gravel";
			__mcTemp__1[16] = S"Ice";
			__mcTemp__1[17] = S"Ladder";
			__mcTemp__1[18] = S"Metal_Box";
			__mcTemp__1[19] = S"Metal";
			__mcTemp__1[20] = S"MetalGrate";
			__mcTemp__1[21] = S"MetalPanel";
			__mcTemp__1[22] = S"MetalVent";
			__mcTemp__1[23] = S"MudSlipperySlime";
			__mcTemp__1[24] = S"Porcelain";
			__mcTemp__1[25] = S"Quicksand";
			__mcTemp__1[26] = S"Rock";
			__mcTemp__1[27] = S"Slime";
			__mcTemp__1[28] = S"SlipperyMetal";
			__mcTemp__1[29] = S"Snow";
			__mcTemp__1[30] = S"SolidMetal";
			__mcTemp__1[31] = S"Tile";
			__mcTemp__1[32] = S"Wade";
			__mcTemp__1[33] = S"Water";
			__mcTemp__1[34] = S"Watermelon";
			__mcTemp__1[35] = S"Wood_Box";
			__mcTemp__1[36] = S"Wood_Crate";
			__mcTemp__1[37] = S"Wood_Furniture";
			__mcTemp__1[38] = S"Wood_Panel";
			__mcTemp__1[39] = S"Wood_Plank";
			__mcTemp__1[40] = S"Wood_Solid";
			__mcTemp__1[41] = S"WoodWood_Lowdensity";
			this->cboSurface2->Items->AddRange(__mcTemp__1);
			this->cboSurface2->Location = System::Drawing::Point(96, 64);
			this->cboSurface2->Name = S"cboSurface2";
			this->cboSurface2->Size = System::Drawing::Size(232, 21);
			this->cboSurface2->TabIndex = 5;
			this->tipMain->SetToolTip(this->cboSurface2, S"$surfaceprop2");
			// 
			// lblSurface2
			// 
			this->lblSurface2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblSurface2->Location = System::Drawing::Point(8, 64);
			this->lblSurface2->Name = S"lblSurface2";
			this->lblSurface2->Size = System::Drawing::Size(88, 23);
			this->lblSurface2->TabIndex = 4;
			this->lblSurface2->Text = S"Surface 2:";
			// 
			// cboSurface1
			// 
			System::Object* __mcTemp__2[] = new System::Object*[42];
			__mcTemp__2[0] = S"AlienFlesh";
			__mcTemp__2[1] = S"ArmorFlesh";
			__mcTemp__2[2] = S"BloodyFlesh";
			__mcTemp__2[3] = S"Boulder";
			__mcTemp__2[4] = S"Brick";
			__mcTemp__2[5] = S"Chain";
			__mcTemp__2[6] = S"Chainlink";
			__mcTemp__2[7] = S"Computer";
			__mcTemp__2[8] = S"Concrete";
			__mcTemp__2[9] = S"Concrete_Block";
			__mcTemp__2[10] = S"Default";
			__mcTemp__2[11] = S"Dirt";
			__mcTemp__2[12] = S"Flesh";
			__mcTemp__2[13] = S"Glass";
			__mcTemp__2[14] = S"Grass";
			__mcTemp__2[15] = S"Gravel";
			__mcTemp__2[16] = S"Ice";
			__mcTemp__2[17] = S"Ladder";
			__mcTemp__2[18] = S"Metal_Box";
			__mcTemp__2[19] = S"Metal";
			__mcTemp__2[20] = S"MetalGrate";
			__mcTemp__2[21] = S"MetalPanel";
			__mcTemp__2[22] = S"MetalVent";
			__mcTemp__2[23] = S"MudSlipperySlime";
			__mcTemp__2[24] = S"Porcelain";
			__mcTemp__2[25] = S"Quicksand";
			__mcTemp__2[26] = S"Rock";
			__mcTemp__2[27] = S"Slime";
			__mcTemp__2[28] = S"SlipperyMetal";
			__mcTemp__2[29] = S"Snow";
			__mcTemp__2[30] = S"SolidMetal";
			__mcTemp__2[31] = S"Tile";
			__mcTemp__2[32] = S"Wade";
			__mcTemp__2[33] = S"Water";
			__mcTemp__2[34] = S"Watermelon";
			__mcTemp__2[35] = S"Wood_Box";
			__mcTemp__2[36] = S"Wood_Crate";
			__mcTemp__2[37] = S"Wood_Furniture";
			__mcTemp__2[38] = S"Wood_Panel";
			__mcTemp__2[39] = S"Wood_Plank";
			__mcTemp__2[40] = S"Wood_Solid";
			__mcTemp__2[41] = S"WoodWood_Lowdensity";
			this->cboSurface1->Items->AddRange(__mcTemp__2);
			this->cboSurface1->Location = System::Drawing::Point(96, 40);
			this->cboSurface1->Name = S"cboSurface1";
			this->cboSurface1->Size = System::Drawing::Size(232, 21);
			this->cboSurface1->TabIndex = 3;
			this->tipMain->SetToolTip(this->cboSurface1, S"$surfaceprop");
			// 
			// lblSurface1
			// 
			this->lblSurface1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblSurface1->Location = System::Drawing::Point(8, 40);
			this->lblSurface1->Name = S"lblSurface1";
			this->lblSurface1->Size = System::Drawing::Size(88, 23);
			this->lblSurface1->TabIndex = 2;
			this->lblSurface1->Text = S"Surface 1:";
			// 
			// cboShader
			// 
			System::Object* __mcTemp__3[] = new System::Object*[13];
			__mcTemp__3[0] = S"Cable";
			__mcTemp__3[1] = S"Decal";
			__mcTemp__3[2] = S"DecalModulate";
			__mcTemp__3[3] = S"LightmappedGeneric";
			__mcTemp__3[4] = S"Modulate";
			__mcTemp__3[5] = S"MonitorScreen";
			__mcTemp__3[6] = S"Predator";
			__mcTemp__3[7] = S"Refract";
			__mcTemp__3[8] = S"ShatteredGlass";
			__mcTemp__3[9] = S"Sprite";
			__mcTemp__3[10] = S"UnlitGeneric";
			__mcTemp__3[11] = S"VertexlitGeneric";
			__mcTemp__3[12] = S"Water";
			this->cboShader->Items->AddRange(__mcTemp__3);
			this->cboShader->Location = System::Drawing::Point(96, 16);
			this->cboShader->Name = S"cboShader";
			this->cboShader->Size = System::Drawing::Size(232, 21);
			this->cboShader->TabIndex = 1;
			this->cboShader->Text = S"LightmappedGeneric";
			this->cboShader->TextChanged += new System::EventHandler(this, &CVMTCreate::cboShader_TextChanged);
			// 
			// lblShader
			// 
			this->lblShader->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lblShader->Location = System::Drawing::Point(8, 16);
			this->lblShader->Name = S"lblShader";
			this->lblShader->Size = System::Drawing::Size(88, 23);
			this->lblShader->TabIndex = 0;
			this->lblShader->Text = S"Shader:";
			// 
			// btnClose
			// 
			this->btnClose->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnClose->Location = System::Drawing::Point(288, 320);
			this->btnClose->Name = S"btnClose";
			this->btnClose->Size = System::Drawing::Size(80, 23);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = S"&Close";
			this->btnClose->Click += new System::EventHandler(this, &CVMTCreate::btnClose_Click);
			// 
			// btnCreate
			// 
			this->btnCreate->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnCreate->Location = System::Drawing::Point(200, 320);
			this->btnCreate->Name = S"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(80, 23);
			this->btnCreate->TabIndex = 1;
			this->btnCreate->Text = S"C&reate";
			this->btnCreate->Click += new System::EventHandler(this, &CVMTCreate::btnCreate_Click);
			// 
			// btnClear
			// 
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnClear->Location = System::Drawing::Point(8, 320);
			this->btnClear->Name = S"btnClear";
			this->btnClear->Size = System::Drawing::Size(80, 23);
			this->btnClear->TabIndex = 3;
			this->btnClear->Text = S"C&lear";
			this->btnClear->Click += new System::EventHandler(this, &CVMTCreate::btnClear_Click);
			// 
			// dlgSaveVMTFile
			// 
			this->dlgSaveVMTFile->Filter = S"VMT Files (*.vmt)|*.vmt";
			this->dlgSaveVMTFile->Title = S"Save VMT File";
			// 
			// CVMTCreate
			// 
			this->AcceptButton = this->btnCreate;
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->CancelButton = this->btnClose;
			this->ClientSize = System::Drawing::Size(378, 352);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->tabMain);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = S"CVMTCreate";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = S"Create VMT File";
			this->grpTextures->ResumeLayout(false);
			this->tabMain->ResumeLayout(false);
			this->tabTextures->ResumeLayout(false);
			this->tabOptions->ResumeLayout(false);
			this->grpOptions->ResumeLayout(false);
			this->ResumeLayout(false);

		}		
		private: System::Void GetTexture(System::Windows::Forms::TextBox *oTextBox)
		{
			if(this->dlgOpenVTFFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				oTextBox->Text = CVMTFileUtility::GetTexturePathFromSystemPath(this->dlgOpenVTFFile->FileName);
			}
		}

		public: System::Void Create(System::String *sFileName, VTFLib::CVTFFile &VTFFile)
		{
			this->txtBaseTexture1->Text = CVMTFileUtility::GetTexturePathFromSystemPath(sFileName);
			this->chkAlphaTest->Checked = VTFFile.GetFlag(TEXTUREFLAGS_ONEBITALPHA) != 0;
			this->chkTranslucent->Checked = VTFFile.GetFlag(TEXTUREFLAGS_EIGHTBITALPHA) != 0;
		}

		private: System::Void Clear()
		{
			this->txtBaseTexture1->Clear();
			this->txtBumpTexture1->Clear();
			this->txtBaseTexture2->Clear();
			this->txtBumpTexture2->Clear();
			this->txtEnviromentTexture->Clear();
			this->txtEnviromentMaskTexture->Clear();
			this->txtDetailTexture->Clear();
			this->txtToolTexture->Clear();
			this->txtNormalTexture->Clear();
			this->txtDuDvTexture->Clear();

			this->cboShader->Text = S"LightmappedGeneric";
			this->cboSurface1->Text = S"";
			this->cboSurface2->Text = S"";

			this->txtKeywords->Clear();

			this->chkAdditive->Checked = false;
			this->chkAlphaTest->Checked = false;
			this->chkEnviromentMapContrast->Checked = false;
			this->chkEnviromentMapSaturation->Checked = false;
			this->chkNoCull->Checked = false;
			this->chkNoDecal->Checked = false;
			this->chkNoLOD->Checked = false;
			this->chkTranslucent->Checked = false;
			this->chkVertexAlpha->Checked = false;
			this->chkVertexColor->Checked = false;
		}

		private: System::Void txtTexture_Leave(System::Object *  sender, System::EventArgs *  e)
		{
			static_cast<System::Windows::Forms::TextBox *>(sender)->Text = CVMTFileUtility::GetTexturePathFromSystemPath(static_cast<System::Windows::Forms::TextBox *>(sender)->Text);
		}

		private: System::Void txtBaseTexture1_TextChanged(System::Object *  sender, System::EventArgs *  e)
		{
			//this->btnCreate->Enabled = this->GetTexturePath(txtBaseTexture1->Text)->Length != 0 && this->cboShader->Text->Length != 0;
		}

		private: System::Void cboShader_TextChanged(System::Object *  sender, System::EventArgs *  e)
		{
			this->btnCreate->Enabled =/* this->GetTexturePath(txtBaseTexture1->Text)->Length != 0 && */this->cboShader->Text->Length != 0;
		}

		private: System::Void btnBaseTexture1_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtBaseTexture1);
		}

		private: System::Void btnBumpTexture1_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtBumpTexture1);
		}

		private: System::Void btnBaseTexture2_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtBaseTexture2);
		}
		private: System::Void btnBumpTexture2_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtBumpTexture2);
		}

		private: System::Void btnEnviromentTexture_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtEnviromentTexture);
		}

		private: System::Void btnEnviromentMaskTexture_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtEnviromentMaskTexture);
		}

		private: System::Void btnDetailTexture_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtDetailTexture);
		}

		private: System::Void btnToolTexture_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtToolTexture);
		}

		private: System::Void btnNormalTexture_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtNormalTexture);
		}

		private: System::Void btnDuDvTexture_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->GetTexture(this->txtDuDvTexture);
		}

		private: System::Void btnClear_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->Clear();
		}

		private: System::Void AddVMTStringNode(VTFLib::CVMTFile &VMTFile, System::String *sName, System::String *sValue)
		{
			if(sValue->Length == 0)
				return;

			char *cName = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sName).ToPointer();
			char *cValue = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sValue).ToPointer();
			VMTFile.GetRoot()->AddStringNode(cName, cValue);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cValue);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cName);
		}

		private: System::Void AddVMTIntegerNode(VTFLib::CVMTFile &VMTFile, System::String *sName, int iValue)
		{
			char *cName = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sName).ToPointer();
			VMTFile.GetRoot()->AddIntegerNode(cName, iValue);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cName);
		}

		private: System::Void AddVMTSingleNode(VTFLib::CVMTFile &VMTFile, System::String *sName, float fValue)
		{
			char *cName = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sName).ToPointer();
			VMTFile.GetRoot()->AddSingleNode(cName, fValue);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cName);
		}

		private: System::Void AddVMTBooleanNode(VTFLib::CVMTFile &VMTFile, System::String *sName, bool bValue, bool bDefault)
		{
			if(bValue == bDefault)
				return;

			char *cName = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sName).ToPointer();
			VMTFile.GetRoot()->AddIntegerNode(cName, bValue ? 1 : 0);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cName);
		}

		private: System::Void btnCreate_Click(System::Object *  sender, System::EventArgs *  e)
		{
			System::String *sVMTFile = this->txtBaseTexture1->Text;

			int iIndex = sVMTFile->LastIndexOf(S"/");
			if(iIndex != -1)
			{
				sVMTFile = sVMTFile->Substring(iIndex + 1);
			}

			this->dlgSaveVMTFile->FileName = sVMTFile;
			if(this->dlgSaveVMTFile->ShowDialog() != System::Windows::Forms::DialogResult::OK)
				return;

			char *cTemp;
			VTFLib::CVMTFile VMTFile;

			cTemp = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->cboShader->Text).ToPointer();
			VMTFile.Create(cTemp);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp);

			this->AddVMTStringNode(VMTFile, "$basetexture", this->txtBaseTexture1->Text);
			this->AddVMTStringNode(VMTFile, "$bumpmap", this->txtBumpTexture1->Text);
			this->AddVMTStringNode(VMTFile, "$basetexture2", this->txtBaseTexture2->Text);
			this->AddVMTStringNode(VMTFile, "$bumpmap2", this->txtBumpTexture2->Text);
			this->AddVMTStringNode(VMTFile, "$envmap", this->txtEnviromentTexture->Text);
			this->AddVMTStringNode(VMTFile, "$envmapmask", this->txtEnviromentMaskTexture->Text);
			this->AddVMTStringNode(VMTFile, "$detail", this->txtDetailTexture->Text);
			this->AddVMTStringNode(VMTFile, "%tooltexture", this->txtToolTexture->Text);
			this->AddVMTStringNode(VMTFile, "$normalmap", this->txtNormalTexture->Text);
			this->AddVMTStringNode(VMTFile, "$dudvmap", this->txtDuDvTexture->Text);

			this->AddVMTStringNode(VMTFile, "$surfaceprop", this->cboSurface1->Text);
			this->AddVMTStringNode(VMTFile, "$surfaceprop2", this->cboSurface2->Text);

			this->AddVMTStringNode(VMTFile, "%keywords", this->txtKeywords->Text);

			this->AddVMTBooleanNode(VMTFile, "$additive", this->chkAdditive->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$alphatest", this->chkAlphaTest->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$envmapcontrast", this->chkEnviromentMapContrast->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$envmapsaturation", this->chkEnviromentMapSaturation->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$nocull", this->chkNoCull->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$nodecal", this->chkNoDecal->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$nolod", this->chkNoLOD->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$translucent", this->chkTranslucent->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$vertexalpha", this->chkVertexAlpha->Checked, false);
			this->AddVMTBooleanNode(VMTFile, "$vertexcolor", this->chkVertexColor->Checked, false);

			cTemp = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->dlgSaveVMTFile->FileName).ToPointer();
			VMTFile.Save(cTemp);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)cTemp);
		}

		private: System::Void btnClose_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	};
}