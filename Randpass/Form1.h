#pragma once

#include<fstream>
#include<iostream>
#include<vcclr.h>

namespace Randpass {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum LettersMode {Ucase, Lcase, Mixed, None};

	struct Options {
		Decimal length;
		LettersMode letters;
		bool numbers;
		bool symbols;
		bool custom;
		wchar_t customChars[256];
	};

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			if (System::IO::File::Exists(L"default.rpd"))
				loadOptions(L"default.rpd");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bGenerate;
	private: System::Windows::Forms::TextBox^  tbNewPass;
	protected: 

	protected: 


	private: System::Windows::Forms::GroupBox^  gbOptions;
	private: System::Windows::Forms::ListBox^  lbPasswords;
	private: System::Windows::Forms::RadioButton^  rbMixed;
	private: System::Windows::Forms::RadioButton^  rbUppercase;


	private: System::Windows::Forms::RadioButton^  rbLowercase;
	private: System::Windows::Forms::CheckBox^  cbNumbers;
	private: System::Windows::Forms::CheckBox^  cbSymbols;

	private: System::Windows::Forms::CheckBox^  cbCustom;
	private: System::Windows::Forms::NumericUpDown^  numPassLen;

	private: System::Windows::Forms::Label^  label1;
    private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

    private: System::Windows::Forms::TabControl^  tabControl1;
    private: System::Windows::Forms::TabPage^  tabPage1;
    private: System::Windows::Forms::TabPage^  tabPage2;
    private: System::Windows::Forms::TextBox^  tbAddChar;

    private: System::Windows::Forms::ListBox^  lbChars;
    private: System::Windows::Forms::Button^  bAddChar;
    private: System::Windows::Forms::Button^  bRemove;

    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::RadioButton^  rbNoLetters;
	private: System::Windows::Forms::GroupBox^  gbSaveOptions;
	private: System::Windows::Forms::Button^  bLoad;
	private: System::Windows::Forms::Button^  bSaveOptions;
	private: System::Windows::Forms::GroupBox^  gbSaveList;
	private: System::Windows::Forms::Button^  bLoadList;
	private: System::Windows::Forms::Button^  bSaveList;
	private: System::Windows::Forms::SaveFileDialog^  saveOptionsDialog;
	private: System::Windows::Forms::OpenFileDialog^  openOptionsDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveListDialog;
	private: System::Windows::Forms::OpenFileDialog^  openListDialog;

	private: System::Windows::Forms::ImageList^  imageList1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->bGenerate = (gcnew System::Windows::Forms::Button());
			this->tbNewPass = (gcnew System::Windows::Forms::TextBox());
			this->lbPasswords = (gcnew System::Windows::Forms::ListBox());
			this->gbOptions = (gcnew System::Windows::Forms::GroupBox());
			this->rbNoLetters = (gcnew System::Windows::Forms::RadioButton());
			this->rbMixed = (gcnew System::Windows::Forms::RadioButton());
			this->rbUppercase = (gcnew System::Windows::Forms::RadioButton());
			this->rbLowercase = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numPassLen = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbCustom = (gcnew System::Windows::Forms::CheckBox());
			this->cbSymbols = (gcnew System::Windows::Forms::CheckBox());
			this->cbNumbers = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->bRemove = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bAddChar = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->tbAddChar = (gcnew System::Windows::Forms::TextBox());
			this->lbChars = (gcnew System::Windows::Forms::ListBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->gbSaveList = (gcnew System::Windows::Forms::GroupBox());
			this->bLoadList = (gcnew System::Windows::Forms::Button());
			this->bSaveList = (gcnew System::Windows::Forms::Button());
			this->gbSaveOptions = (gcnew System::Windows::Forms::GroupBox());
			this->bLoad = (gcnew System::Windows::Forms::Button());
			this->bSaveOptions = (gcnew System::Windows::Forms::Button());
			this->saveOptionsDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openOptionsDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveListDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openListDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->gbOptions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPassLen))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->gbSaveList->SuspendLayout();
			this->gbSaveOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// bGenerate
			// 
			this->bGenerate->Location = System::Drawing::Point(168, 330);
			this->bGenerate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bGenerate->Name = L"bGenerate";
			this->bGenerate->Size = System::Drawing::Size(100, 28);
			this->bGenerate->TabIndex = 0;
			this->bGenerate->Text = L"Generate";
			this->bGenerate->UseVisualStyleBackColor = true;
			this->bGenerate->Click += gcnew System::EventHandler(this, &Form1::bGenerate_Click);
			// 
			// tbNewPass
			// 
			this->tbNewPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbNewPass->BackColor = System::Drawing::SystemColors::Window;
			this->tbNewPass->Location = System::Drawing::Point(49, 299);
			this->tbNewPass->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbNewPass->Name = L"tbNewPass";
			this->tbNewPass->ReadOnly = true;
			this->tbNewPass->Size = System::Drawing::Size(365, 22);
			this->tbNewPass->TabIndex = 1;
			// 
			// lbPasswords
			// 
			this->lbPasswords->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbPasswords->FormattingEnabled = true;
			this->lbPasswords->ItemHeight = 16;
			this->lbPasswords->Location = System::Drawing::Point(16, 15);
			this->lbPasswords->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->lbPasswords->Name = L"lbPasswords";
			this->lbPasswords->Size = System::Drawing::Size(433, 276);
			this->lbPasswords->TabIndex = 2;
			this->lbPasswords->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::lbPasswords_SelectedIndexChanged);
			// 
			// gbOptions
			// 
			this->gbOptions->Controls->Add(this->rbNoLetters);
			this->gbOptions->Controls->Add(this->rbMixed);
			this->gbOptions->Controls->Add(this->rbUppercase);
			this->gbOptions->Controls->Add(this->rbLowercase);
			this->gbOptions->Location = System::Drawing::Point(8, 7);
			this->gbOptions->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->gbOptions->Name = L"gbOptions";
			this->gbOptions->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->gbOptions->Size = System::Drawing::Size(405, 123);
			this->gbOptions->TabIndex = 3;
			this->gbOptions->TabStop = false;
			this->gbOptions->Text = L"Letters";
			// 
			// rbNoLetters
			// 
			this->rbNoLetters->AutoSize = true;
			this->rbNoLetters->Location = System::Drawing::Point(216, 25);
			this->rbNoLetters->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rbNoLetters->Name = L"rbNoLetters";
			this->rbNoLetters->Size = System::Drawing::Size(132, 21);
			this->rbNoLetters->TabIndex = 3;
			this->rbNoLetters->TabStop = true;
			this->rbNoLetters->Text = L"Don\'t use letters";
			this->rbNoLetters->UseVisualStyleBackColor = true;
			// 
			// rbMixed
			// 
			this->rbMixed->AutoSize = true;
			this->rbMixed->Checked = true;
			this->rbMixed->Location = System::Drawing::Point(9, 84);
			this->rbMixed->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rbMixed->Name = L"rbMixed";
			this->rbMixed->Size = System::Drawing::Size(198, 21);
			this->rbMixed->TabIndex = 2;
			this->rbMixed->TabStop = true;
			this->rbMixed->Text = L"Mix lower and upper letters";
			this->rbMixed->UseVisualStyleBackColor = true;
			// 
			// rbUppercase
			// 
			this->rbUppercase->AutoSize = true;
			this->rbUppercase->Location = System::Drawing::Point(9, 54);
			this->rbUppercase->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rbUppercase->Name = L"rbUppercase";
			this->rbUppercase->Size = System::Drawing::Size(141, 21);
			this->rbUppercase->TabIndex = 1;
			this->rbUppercase->Text = L"Uppercase letters";
			this->rbUppercase->UseVisualStyleBackColor = true;
			// 
			// rbLowercase
			// 
			this->rbLowercase->AutoSize = true;
			this->rbLowercase->Location = System::Drawing::Point(9, 25);
			this->rbLowercase->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rbLowercase->Name = L"rbLowercase";
			this->rbLowercase->Size = System::Drawing::Size(140, 21);
			this->rbLowercase->TabIndex = 0;
			this->rbLowercase->Text = L"Lowercase letters";
			this->rbLowercase->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 146);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Password length:";
			// 
			// numPassLen
			// 
			this->numPassLen->Location = System::Drawing::Point(133, 144);
			this->numPassLen->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->numPassLen->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->numPassLen->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numPassLen->Name = L"numPassLen";
			this->numPassLen->Size = System::Drawing::Size(69, 22);
			this->numPassLen->TabIndex = 7;
			this->numPassLen->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// cbCustom
			// 
			this->cbCustom->AutoSize = true;
			this->cbCustom->Enabled = false;
			this->cbCustom->Location = System::Drawing::Point(8, 233);
			this->cbCustom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cbCustom->Name = L"cbCustom";
			this->cbCustom->Size = System::Drawing::Size(189, 21);
			this->cbCustom->TabIndex = 5;
			this->cbCustom->Text = L"Use custom character list";
			this->cbCustom->UseVisualStyleBackColor = true;
			// 
			// cbSymbols
			// 
			this->cbSymbols->AutoSize = true;
			this->cbSymbols->Location = System::Drawing::Point(8, 204);
			this->cbSymbols->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cbSymbols->Name = L"cbSymbols";
			this->cbSymbols->Size = System::Drawing::Size(110, 21);
			this->cbSymbols->TabIndex = 4;
			this->cbSymbols->Text = L"Use symbols";
			this->cbSymbols->UseVisualStyleBackColor = true;
			// 
			// cbNumbers
			// 
			this->cbNumbers->AutoSize = true;
			this->cbNumbers->Location = System::Drawing::Point(8, 176);
			this->cbNumbers->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cbNumbers->Name = L"cbNumbers";
			this->cbNumbers->Size = System::Drawing::Size(114, 21);
			this->cbNumbers->TabIndex = 3;
			this->cbNumbers->Text = L"Use numbers";
			this->cbNumbers->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 366);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(435, 293);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->numPassLen);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->gbOptions);
			this->tabPage1->Controls->Add(this->cbCustom);
			this->tabPage1->Controls->Add(this->cbNumbers);
			this->tabPage1->Controls->Add(this->cbSymbols);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(427, 264);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Options";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->bRemove);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->bAddChar);
			this->tabPage2->Controls->Add(this->tbAddChar);
			this->tabPage2->Controls->Add(this->lbChars);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(427, 264);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Custom characters";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// bRemove
			// 
			this->bRemove->Enabled = false;
			this->bRemove->Location = System::Drawing::Point(313, 228);
			this->bRemove->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bRemove->Name = L"bRemove";
			this->bRemove->Size = System::Drawing::Size(100, 28);
			this->bRemove->TabIndex = 4;
			this->bRemove->Text = L"Remove";
			this->bRemove->UseVisualStyleBackColor = true;
			this->bRemove->Click += gcnew System::EventHandler(this, &Form1::bRemove_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 100);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Type the character(s) you would like to add:";
			// 
			// bAddChar
			// 
			this->bAddChar->Enabled = false;
			this->bAddChar->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->bAddChar->ImageKey = L"arrow_right.bmp";
			this->bAddChar->ImageList = this->imageList1;
			this->bAddChar->Location = System::Drawing::Point(195, 151);
			this->bAddChar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bAddChar->Name = L"bAddChar";
			this->bAddChar->Size = System::Drawing::Size(100, 28);
			this->bAddChar->TabIndex = 2;
			this->bAddChar->Text = L"Add";
			this->bAddChar->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->bAddChar->UseVisualStyleBackColor = true;
			this->bAddChar->Click += gcnew System::EventHandler(this, &Form1::bAddChar_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::White;
			this->imageList1->Images->SetKeyName(0, L"arrow_right.bmp");
			this->imageList1->Images->SetKeyName(1, L"app.ico");
			// 
			// tbAddChar
			// 
			this->tbAddChar->Location = System::Drawing::Point(13, 119);
			this->tbAddChar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbAddChar->Name = L"tbAddChar";
			this->tbAddChar->Size = System::Drawing::Size(280, 22);
			this->tbAddChar->TabIndex = 1;
			this->tbAddChar->TextChanged += gcnew System::EventHandler(this, &Form1::tbAddChar_TextChanged);
			// 
			// lbChars
			// 
			this->lbChars->FormattingEnabled = true;
			this->lbChars->ItemHeight = 16;
			this->lbChars->Location = System::Drawing::Point(313, 7);
			this->lbChars->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->lbChars->Name = L"lbChars";
			this->lbChars->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->lbChars->Size = System::Drawing::Size(99, 212);
			this->lbChars->TabIndex = 0;
			this->lbChars->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::lbChars_SelectedIndexChanged);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->gbSaveList);
			this->tabPage3->Controls->Add(this->gbSaveOptions);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Size = System::Drawing::Size(427, 264);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Save/Load";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// gbSaveList
			// 
			this->gbSaveList->Controls->Add(this->bLoadList);
			this->gbSaveList->Controls->Add(this->bSaveList);
			this->gbSaveList->Location = System::Drawing::Point(9, 135);
			this->gbSaveList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->gbSaveList->Name = L"gbSaveList";
			this->gbSaveList->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->gbSaveList->Size = System::Drawing::Size(407, 118);
			this->gbSaveList->TabIndex = 1;
			this->gbSaveList->TabStop = false;
			this->gbSaveList->Text = L"Password list";
			// 
			// bLoadList
			// 
			this->bLoadList->Location = System::Drawing::Point(224, 53);
			this->bLoadList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bLoadList->Name = L"bLoadList";
			this->bLoadList->Size = System::Drawing::Size(100, 28);
			this->bLoadList->TabIndex = 1;
			this->bLoadList->Text = L"Load...";
			this->bLoadList->UseVisualStyleBackColor = true;
			this->bLoadList->Click += gcnew System::EventHandler(this, &Form1::bLoadList_Click);
			// 
			// bSaveList
			// 
			this->bSaveList->Location = System::Drawing::Point(69, 53);
			this->bSaveList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bSaveList->Name = L"bSaveList";
			this->bSaveList->Size = System::Drawing::Size(100, 28);
			this->bSaveList->TabIndex = 0;
			this->bSaveList->Text = L"Save...";
			this->bSaveList->UseVisualStyleBackColor = true;
			this->bSaveList->Click += gcnew System::EventHandler(this, &Form1::bSaveList_Click);
			// 
			// gbSaveOptions
			// 
			this->gbSaveOptions->Controls->Add(this->bLoad);
			this->gbSaveOptions->Controls->Add(this->bSaveOptions);
			this->gbSaveOptions->Location = System::Drawing::Point(9, 9);
			this->gbSaveOptions->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->gbSaveOptions->Name = L"gbSaveOptions";
			this->gbSaveOptions->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->gbSaveOptions->Size = System::Drawing::Size(407, 119);
			this->gbSaveOptions->TabIndex = 0;
			this->gbSaveOptions->TabStop = false;
			this->gbSaveOptions->Text = L"Options";
			// 
			// bLoad
			// 
			this->bLoad->Location = System::Drawing::Point(224, 47);
			this->bLoad->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bLoad->Name = L"bLoad";
			this->bLoad->Size = System::Drawing::Size(100, 28);
			this->bLoad->TabIndex = 1;
			this->bLoad->Text = L"Load...";
			this->bLoad->UseVisualStyleBackColor = true;
			this->bLoad->Click += gcnew System::EventHandler(this, &Form1::bLoad_Click);
			// 
			// bSaveOptions
			// 
			this->bSaveOptions->Location = System::Drawing::Point(69, 47);
			this->bSaveOptions->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bSaveOptions->Name = L"bSaveOptions";
			this->bSaveOptions->Size = System::Drawing::Size(100, 28);
			this->bSaveOptions->TabIndex = 0;
			this->bSaveOptions->Text = L"Save...";
			this->bSaveOptions->UseVisualStyleBackColor = true;
			this->bSaveOptions->Click += gcnew System::EventHandler(this, &Form1::bSaveOptions_Click);
			// 
			// saveOptionsDialog
			// 
			this->saveOptionsDialog->DefaultExt = L"rpd";
			this->saveOptionsDialog->Filter = L"Options files|*.rpd|All files|*.*";
			this->saveOptionsDialog->RestoreDirectory = true;
			this->saveOptionsDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveOptionsDialog_FileOk);
			// 
			// openOptionsDialog
			// 
			this->openOptionsDialog->DefaultExt = L"rpd";
			this->openOptionsDialog->Filter = L"Options files|*.rpd|All files|*.*";
			this->openOptionsDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openOptionsDialog_FileOk);
			// 
			// saveListDialog
			// 
			this->saveListDialog->DefaultExt = L"txt";
			this->saveListDialog->Filter = L"Password lists|*.txt|All files|*.*";
			this->saveListDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveListDialog_FileOk);
			// 
			// openListDialog
			// 
			this->openListDialog->DefaultExt = L"txt";
			this->openListDialog->Filter = L"Password lists|*.txt|All files|*.*";
			this->openListDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openListDialog_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 687);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->lbPasswords);
			this->Controls->Add(this->tbNewPass);
			this->Controls->Add(this->bGenerate);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Random Password Generator";
			this->gbOptions->ResumeLayout(false);
			this->gbOptions->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPassLen))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->gbSaveList->ResumeLayout(false);
			this->gbSaveOptions->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void loadOptions(const wchar_t *filename);
private: System::Void saveOptions(const wchar_t *filename);
private: System::Void loadPasswords(String^ filename);
private: System::Void savePasswords(String^ filename);
private: System::String^ addCustomChars(System::String^ charStr);
private: System::Void bGenerate_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void lbPasswords_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
             tbNewPass->Text = (System::String^)lbPasswords->SelectedItem;
         }
private: System::Void bAddChar_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void tbAddChar_TextChanged(System::Object^  sender, System::EventArgs^  e) {
             bAddChar->Enabled = !System::String::IsNullOrEmpty(tbAddChar->Text);
         }
private: System::Void bRemove_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void lbChars_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
             bRemove->Enabled = (lbChars->SelectedItems->Count > 0);
         }
private: System::Void bSaveOptions_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Select a file to write to
			 saveOptionsDialog->ShowDialog(this);
		 }
private: System::Void bLoad_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Select a file to open
			 openOptionsDialog->ShowDialog(this);
		 }
private: System::Void saveOptionsDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
private: System::Void openOptionsDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
private: System::Void bSaveList_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveListDialog->ShowDialog(this);
		 }
private: System::Void bLoadList_Click(System::Object^  sender, System::EventArgs^  e) {
			 openListDialog->ShowDialog(this);
		 }
private: System::Void saveListDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e); 
private: System::Void openListDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e); 
};
}

