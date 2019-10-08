#pragma once
#include <opencv\cv.h>
#include <opencv\ml.h>
#include <opencv\highgui.h>
#include <opencv\cxcore.h>
#include <stdio.h>
#include "Main.h"
#include "AboutmeForm.h"

// Du lieu file text
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <msclr\marshal_cppstd.h>
#include <time.h>



namespace ANPR {

	using namespace System;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		/************************************************************************/
		/*                          Ảnh gốc                                     */
		/************************************************************************/
	private: IplImage *src;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
			if (src)
			{
				IplImage *temp = src;
				cvReleaseImage(&temp);
				src = NULL;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mởẢnhToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nhậnDạngToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lưuẢnhToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  thoátToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  thôngTinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tácGiảToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trangChủToolStripMenuItem;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::PictureBox^  Source_Image_PictureBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lblDuongdan;
	private: System::Windows::Forms::PictureBox^  Gray_Img_pictureBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  Close_Img;
	private: System::Windows::Forms::Button^  Open_Img;
	private: System::Windows::Forms::Button^  Exit;
	private: System::Windows::Forms::Button^  Recognise;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  Width_Label;
	private: System::Windows::Forms::Label^  Height_Label;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::PictureBox^  Plate_PictureBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button2;
			 /// <summary>
		/// Required designer variable.
		/// </summary>







































			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->mởẢnhToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->nhậnDạngToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->lưuẢnhToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->thoátToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->thôngTinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->tácGiảToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->trangChủToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				 this->Source_Image_PictureBox = (gcnew System::Windows::Forms::PictureBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->lblDuongdan = (gcnew System::Windows::Forms::Label());
				 this->Gray_Img_pictureBox = (gcnew System::Windows::Forms::PictureBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->Close_Img = (gcnew System::Windows::Forms::Button());
				 this->Open_Img = (gcnew System::Windows::Forms::Button());
				 this->Exit = (gcnew System::Windows::Forms::Button());
				 this->Recognise = (gcnew System::Windows::Forms::Button());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->Width_Label = (gcnew System::Windows::Forms::Label());
				 this->Height_Label = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
				 this->Plate_PictureBox = (gcnew System::Windows::Forms::PictureBox());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->menuStrip1->SuspendLayout();
				 this->groupBox2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Source_Image_PictureBox))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Gray_Img_pictureBox))->BeginInit();
				 this->groupBox1->SuspendLayout();
				 this->groupBox3->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Plate_PictureBox))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->fileToolStripMenuItem,
						 this->thôngTinToolStripMenuItem
				 });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(872, 27);
				 this->menuStrip1->TabIndex = 10;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // fileToolStripMenuItem
				 // 
				 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					 this->mởẢnhToolStripMenuItem,
						 this->nhậnDạngToolStripMenuItem, this->lưuẢnhToolStripMenuItem, this->thoátToolStripMenuItem
				 });
				 this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->fileToolStripMenuItem->ForeColor = System::Drawing::Color::Fuchsia;
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(53, 23);
				 this->fileToolStripMenuItem->Text = L"FILE";
				 // 
				 // mởẢnhToolStripMenuItem
				 // 
				 this->mởẢnhToolStripMenuItem->Name = L"mởẢnhToolStripMenuItem";
				 this->mởẢnhToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
				 this->mởẢnhToolStripMenuItem->Size = System::Drawing::Size(215, 24);
				 this->mởẢnhToolStripMenuItem->Text = L"OPEN";
				 this->mởẢnhToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mởẢnhToolStripMenuItem_Click);
				 // 
				 // nhậnDạngToolStripMenuItem
				 // 
				 this->nhậnDạngToolStripMenuItem->Name = L"nhậnDạngToolStripMenuItem";
				 this->nhậnDạngToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
				 this->nhậnDạngToolStripMenuItem->Size = System::Drawing::Size(215, 24);
				 this->nhậnDạngToolStripMenuItem->Text = L"RECOFNISE";
				 this->nhậnDạngToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nhậnDạngToolStripMenuItem_Click);
				 // 
				 // lưuẢnhToolStripMenuItem
				 // 
				 this->lưuẢnhToolStripMenuItem->Name = L"lưuẢnhToolStripMenuItem";
				 this->lưuẢnhToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
				 this->lưuẢnhToolStripMenuItem->Size = System::Drawing::Size(215, 24);
				 this->lưuẢnhToolStripMenuItem->Text = L"CLOSE";
				 this->lưuẢnhToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::đóngẢnhToolStripMenuItem_Click);
				 // 
				 // thoátToolStripMenuItem
				 // 
				 this->thoátToolStripMenuItem->Name = L"thoátToolStripMenuItem";
				 this->thoátToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F4;
				 this->thoátToolStripMenuItem->ShowShortcutKeys = false;
				 this->thoátToolStripMenuItem->Size = System::Drawing::Size(215, 24);
				 this->thoátToolStripMenuItem->Text = L"EXIT";
				 this->thoátToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::thoátToolStripMenuItem_Click);
				 // 
				 // thôngTinToolStripMenuItem
				 // 
				 this->thôngTinToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->tácGiảToolStripMenuItem,
						 this->trangChủToolStripMenuItem
				 });
				 this->thôngTinToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->thôngTinToolStripMenuItem->ForeColor = System::Drawing::Color::Fuchsia;
				 this->thôngTinToolStripMenuItem->Name = L"thôngTinToolStripMenuItem";
				 this->thôngTinToolStripMenuItem->Size = System::Drawing::Size(92, 23);
				 this->thôngTinToolStripMenuItem->Text = L"ABOUT US";
				 // 
				 // tácGiảToolStripMenuItem
				 // 
				 this->tácGiảToolStripMenuItem->Name = L"tácGiảToolStripMenuItem";
				 this->tácGiảToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::K));
				 this->tácGiảToolStripMenuItem->Size = System::Drawing::Size(193, 24);
				 this->tácGiảToolStripMenuItem->Text = L"WITTEN";
				 this->tácGiảToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::tácGiảToolStripMenuItem_Click);
				 // 
				 // trangChủToolStripMenuItem
				 // 
				 this->trangChủToolStripMenuItem->Name = L"trangChủToolStripMenuItem";
				 this->trangChủToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
				 this->trangChủToolStripMenuItem->Size = System::Drawing::Size(193, 24);
				 this->trangChủToolStripMenuItem->Text = L"HOME";
				 this->trangChủToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trangChủToolStripMenuItem_Click);
				 // 
				 // label7
				 // 
				 this->label7->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label7->AutoSize = true;
				 this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(163)));
				 this->label7->ForeColor = System::Drawing::Color::Blue;
				 this->label7->Location = System::Drawing::Point(19, 51);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(59, 19);
				 this->label7->TabIndex = 9;
				 this->label7->Text = L"Width :";
				 // 
				 // label6
				 // 
				 this->label6->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label6->ForeColor = System::Drawing::Color::Blue;
				 this->label6->Location = System::Drawing::Point(114, 51);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(17, 17);
				 this->label6->TabIndex = 11;
				 this->label6->Text = L"...";
				 // 
				 // label5
				 // 
				 this->label5->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label5->AutoSize = true;
				 this->label5->BackColor = System::Drawing::SystemColors::Control;
				 this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label5->ForeColor = System::Drawing::Color::Blue;
				 this->label5->Location = System::Drawing::Point(114, 29);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(17, 17);
				 this->label5->TabIndex = 10;
				 this->label5->Text = L"...";
				 // 
				 // label4
				 // 
				 this->label4->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(163)));
				 this->label4->ForeColor = System::Drawing::Color::Blue;
				 this->label4->Location = System::Drawing::Point(18, 28);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(62, 19);
				 this->label4->TabIndex = 8;
				 this->label4->Text = L"Height :";
				 // 
				 // groupBox2
				 // 
				 this->groupBox2->Controls->Add(this->label4);
				 this->groupBox2->Controls->Add(this->label5);
				 this->groupBox2->Controls->Add(this->label6);
				 this->groupBox2->Controls->Add(this->label7);
				 this->groupBox2->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->groupBox2->ForeColor = System::Drawing::Color::Red;
				 this->groupBox2->Location = System::Drawing::Point(12, 175);
				 this->groupBox2->Name = L"groupBox2";
				 this->groupBox2->Size = System::Drawing::Size(247, 79);
				 this->groupBox2->TabIndex = 16;
				 this->groupBox2->TabStop = false;
				 this->groupBox2->Text = L"LICENSE PLATE IMAGE";
				 // 
				 // Source_Image_PictureBox
				 // 
				 this->Source_Image_PictureBox->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Source_Image_PictureBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->Source_Image_PictureBox->Cursor = System::Windows::Forms::Cursors::Cross;
				 this->Source_Image_PictureBox->Location = System::Drawing::Point(279, 88);
				 this->Source_Image_PictureBox->Name = L"Source_Image_PictureBox";
				 this->Source_Image_PictureBox->Size = System::Drawing::Size(558, 482);
				 this->Source_Image_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->Source_Image_PictureBox->TabIndex = 12;
				 this->Source_Image_PictureBox->TabStop = false;
				 this->Source_Image_PictureBox->Click += gcnew System::EventHandler(this, &Form1::Source_Image_PictureBox_Click);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(163)));
				 this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(275, 56);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(65, 22);
				 this->label3->TabIndex = 13;
				 this->label3->Text = L"PATH: ";
				 // 
				 // lblDuongdan
				 // 
				 this->lblDuongdan->AutoSize = true;
				 this->lblDuongdan->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblDuongdan->Location = System::Drawing::Point(346, 56);
				 this->lblDuongdan->Name = L"lblDuongdan";
				 this->lblDuongdan->Size = System::Drawing::Size(18, 19);
				 this->lblDuongdan->TabIndex = 14;
				 this->lblDuongdan->Text = L"...";
				 // 
				 // Gray_Img_pictureBox
				 // 
				 this->Gray_Img_pictureBox->Location = System::Drawing::Point(893, 88);
				 this->Gray_Img_pictureBox->Name = L"Gray_Img_pictureBox";
				 this->Gray_Img_pictureBox->Size = System::Drawing::Size(438, 482);
				 this->Gray_Img_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->Gray_Img_pictureBox->TabIndex = 15;
				 this->Gray_Img_pictureBox->TabStop = false;
				 // 
				 // button1
				 // 
				 this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
				 this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->button1->Location = System::Drawing::Point(685, 591);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(149, 57);
				 this->button1->TabIndex = 16;
				 this->button1->Text = L"LICENSE PLATE ";
				 this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				 // 
				 // Close_Img
				 // 
				 this->Close_Img->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Close_Img->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->Close_Img->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->Close_Img->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Close_Img->ForeColor = System::Drawing::Color::Black;
				 this->Close_Img->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Close_Img.Image")));
				 this->Close_Img->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->Close_Img->Location = System::Drawing::Point(11, 252);
				 this->Close_Img->Name = L"Close_Img";
				 this->Close_Img->Size = System::Drawing::Size(103, 38);
				 this->Close_Img->TabIndex = 15;
				 this->Close_Img->Text = L"CLOSE";
				 this->Close_Img->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->Close_Img->UseVisualStyleBackColor = true;
				 this->Close_Img->Click += gcnew System::EventHandler(this, &Form1::Close_Img_Click);
				 // 
				 // Open_Img
				 // 
				 this->Open_Img->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Open_Img->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->Open_Img->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->Open_Img->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Open_Img->ForeColor = System::Drawing::Color::Black;
				 this->Open_Img->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Open_Img.Image")));
				 this->Open_Img->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->Open_Img->Location = System::Drawing::Point(11, 193);
				 this->Open_Img->Name = L"Open_Img";
				 this->Open_Img->Size = System::Drawing::Size(103, 40);
				 this->Open_Img->TabIndex = 14;
				 this->Open_Img->Text = L"OPEN";
				 this->Open_Img->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->Open_Img->UseVisualStyleBackColor = true;
				 this->Open_Img->Click += gcnew System::EventHandler(this, &Form1::Open_Img_Click);
				 // 
				 // Exit
				 // 
				 this->Exit->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Exit->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->Exit->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->Exit->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Exit->ForeColor = System::Drawing::Color::Black;
				 this->Exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Exit.Image")));
				 this->Exit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->Exit->Location = System::Drawing::Point(121, 252);
				 this->Exit->Name = L"Exit";
				 this->Exit->Size = System::Drawing::Size(110, 38);
				 this->Exit->TabIndex = 17;
				 this->Exit->Text = L"EXIT";
				 this->Exit->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->Exit->UseVisualStyleBackColor = true;
				 this->Exit->Click += gcnew System::EventHandler(this, &Form1::Exit_Click);
				 // 
				 // Recognise
				 // 
				 this->Recognise->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Recognise->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->Recognise->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->Recognise->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Recognise->ForeColor = System::Drawing::Color::Black;
				 this->Recognise->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Recognise.Image")));
				 this->Recognise->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->Recognise->Location = System::Drawing::Point(121, 192);
				 this->Recognise->Name = L"Recognise";
				 this->Recognise->Size = System::Drawing::Size(110, 41);
				 this->Recognise->TabIndex = 16;
				 this->Recognise->Text = L"RECOGNISE";
				 this->Recognise->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->Recognise->UseVisualStyleBackColor = true;
				 this->Recognise->Click += gcnew System::EventHandler(this, &Form1::Recognise_Click);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->checkBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->checkBox1->Location = System::Drawing::Point(11, 31);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(179, 23);
				 this->checkBox1->TabIndex = 18;
				 this->checkBox1->Text = L"Automatic recognition";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
				 // 
				 // radioButton1
				 // 
				 this->radioButton1->AutoSize = true;
				 this->radioButton1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->radioButton1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->radioButton1->Location = System::Drawing::Point(11, 64);
				 this->radioButton1->Name = L"radioButton1";
				 this->radioButton1->Size = System::Drawing::Size(228, 23);
				 this->radioButton1->TabIndex = 21;
				 this->radioButton1->Text = L"Show image during sea search";
				 this->radioButton1->UseVisualStyleBackColor = true;
				 // 
				 // radioButton2
				 // 
				 this->radioButton2->AllowDrop = true;
				 this->radioButton2->AutoSize = true;
				 this->radioButton2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->radioButton2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->radioButton2->Location = System::Drawing::Point(11, 100);
				 this->radioButton2->Name = L"radioButton2";
				 this->radioButton2->Size = System::Drawing::Size(367, 23);
				 this->radioButton2->TabIndex = 22;
				 this->radioButton2->Text = L"Show photo in the process of separating characters";
				 this->radioButton2->UseVisualStyleBackColor = true;
				 this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
				 // 
				 // radioButton3
				 // 
				 this->radioButton3->AutoSize = true;
				 this->radioButton3->Checked = true;
				 this->radioButton3->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->radioButton3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->radioButton3->Location = System::Drawing::Point(11, 134);
				 this->radioButton3->Name = L"radioButton3";
				 this->radioButton3->Size = System::Drawing::Size(79, 23);
				 this->radioButton3->TabIndex = 23;
				 this->radioButton3->TabStop = true;
				 this->radioButton3->Text = L"Not out";
				 this->radioButton3->UseVisualStyleBackColor = true;
				 this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->radioButton3);
				 this->groupBox1->Controls->Add(this->radioButton2);
				 this->groupBox1->Controls->Add(this->radioButton1);
				 this->groupBox1->Controls->Add(this->checkBox1);
				 this->groupBox1->Controls->Add(this->Recognise);
				 this->groupBox1->Controls->Add(this->Exit);
				 this->groupBox1->Controls->Add(this->Open_Img);
				 this->groupBox1->Controls->Add(this->Close_Img);
				 this->groupBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->groupBox1->ForeColor = System::Drawing::Color::Red;
				 this->groupBox1->Location = System::Drawing::Point(15, 267);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(244, 303);
				 this->groupBox1->TabIndex = 14;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"FUNCTION";
				 // 
				 // label2
				 // 
				 this->label2->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(163)));
				 this->label2->ForeColor = System::Drawing::Color::Blue;
				 this->label2->Location = System::Drawing::Point(18, 53);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(59, 19);
				 this->label2->TabIndex = 9;
				 this->label2->Text = L"Width :";
				 // 
				 // Width_Label
				 // 
				 this->Width_Label->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Width_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->Width_Label->AutoSize = true;
				 this->Width_Label->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Width_Label->ForeColor = System::Drawing::Color::Blue;
				 this->Width_Label->Location = System::Drawing::Point(114, 53);
				 this->Width_Label->Name = L"Width_Label";
				 this->Width_Label->Size = System::Drawing::Size(17, 17);
				 this->Width_Label->TabIndex = 11;
				 this->Width_Label->Text = L"...";
				 // 
				 // Height_Label
				 // 
				 this->Height_Label->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->Height_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->Height_Label->AutoSize = true;
				 this->Height_Label->BackColor = System::Drawing::SystemColors::Control;
				 this->Height_Label->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Height_Label->ForeColor = System::Drawing::Color::Blue;
				 this->Height_Label->Location = System::Drawing::Point(114, 30);
				 this->Height_Label->Name = L"Height_Label";
				 this->Height_Label->Size = System::Drawing::Size(17, 17);
				 this->Height_Label->TabIndex = 10;
				 this->Height_Label->Text = L"...";
				 // 
				 // label1
				 // 
				 this->label1->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
				 this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(163)));
				 this->label1->ForeColor = System::Drawing::Color::Blue;
				 this->label1->Location = System::Drawing::Point(18, 27);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(62, 19);
				 this->label1->TabIndex = 8;
				 this->label1->Text = L"Height :";
				 // 
				 // groupBox3
				 // 
				 this->groupBox3->Controls->Add(this->label1);
				 this->groupBox3->Controls->Add(this->Height_Label);
				 this->groupBox3->Controls->Add(this->Width_Label);
				 this->groupBox3->Controls->Add(this->label2);
				 this->groupBox3->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->groupBox3->ForeColor = System::Drawing::Color::Red;
				 this->groupBox3->Location = System::Drawing::Point(12, 81);
				 this->groupBox3->Name = L"groupBox3";
				 this->groupBox3->Size = System::Drawing::Size(247, 84);
				 this->groupBox3->TabIndex = 15;
				 this->groupBox3->TabStop = false;
				 this->groupBox3->Text = L"ORIGINAL IMAGE";
				 // 
				 // Plate_PictureBox
				 // 
				 this->Plate_PictureBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->Plate_PictureBox->Location = System::Drawing::Point(282, 593);
				 this->Plate_PictureBox->Name = L"Plate_PictureBox";
				 this->Plate_PictureBox->Size = System::Drawing::Size(231, 55);
				 this->Plate_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->Plate_PictureBox->TabIndex = 16;
				 this->Plate_PictureBox->TabStop = false;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(163)));
				 this->label8->Location = System::Drawing::Point(27, 611);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(2, 33);
				 this->label8->TabIndex = 17;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->label9->Location = System::Drawing::Point(376, 9);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(407, 32);
				 this->label9->TabIndex = 18;
				 this->label9->Text = L"ELECTRONIC TOLL COLLECTION";
				 // 
				 // button2
				 // 
				 this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button2->ForeColor = System::Drawing::Color::Purple;
				 this->button2->Location = System::Drawing::Point(551, 593);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(90, 55);
				 this->button2->TabIndex = 19;
				 this->button2->Text = L"CAPTURE";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->ClientSize = System::Drawing::Size(872, 660);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->label9);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->groupBox2);
				 this->Controls->Add(this->lblDuongdan);
				 this->Controls->Add(this->Plate_PictureBox);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->groupBox3);
				 this->Controls->Add(this->Source_Image_PictureBox);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->Gray_Img_pictureBox);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->MaximizeBox = false;
				 this->Name = L"Form1";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
				 this->Text = L"LICENSE PLATE RECOGNIZATION";
				 this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->groupBox2->ResumeLayout(false);
				 this->groupBox2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Source_Image_PictureBox))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Gray_Img_pictureBox))->EndInit();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->groupBox3->ResumeLayout(false);
				 this->groupBox3->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Plate_PictureBox))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

#pragma region Chức năng
			 //
			 // Convert Kiểu String sang Char* để dùng cho nút "Open Image"
			 // [Convert String to Char* to use for "Open Image" button]
	private: char* ConvertStringtoChar(System::String ^str){
				 char *str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
				 return str2;
	}

	private: Bitmap^ iplImage2Bitmap(IplImage *img)
	{

				 Bitmap ^bmp;

				 if (img->nChannels == 1)
				 {
					 bmp = gcnew Bitmap(img->width, img->height, Imaging::PixelFormat::Format8bppIndexed);

					 Imaging::ColorPalette ^plt = bmp->Palette;

					 for (int i = 0; i < 256; i++)
					 {
						 plt->Entries[i] = Color::FromArgb(i, i, i);

						 bmp->Palette = plt;
					 }
				 }
				 else
					 bmp = gcnew Bitmap(img->width, img->height, Imaging::PixelFormat::Format24bppRgb);

				 Imaging::BitmapData ^data = bmp->LockBits(Drawing::Rectangle(0, 0, bmp->Width, bmp->Height), Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);

				 memcpy(data->Scan0.ToPointer(), img->imageData, img->imageSize);
				 bmp->UnlockBits(data);

				 return bmp;
	}
			 //
			 // Nút OpenImage
			 // OpenImage Button
	private: System::Void Open_Img_Click(System::Object^  sender, System::EventArgs^  e) {


				 OpenFileDialog^ dlg = gcnew OpenFileDialog;

				 dlg->Filter = L"Chọn ảnh (*.bmp; *.jpg; *.jpeg; *.png) |*.bmp;*.jpg;*.jpeg;*.png|Tất cả các định dạng file (*.*)|*.*||";
				 if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)	return;
				 src = cvLoadImage(ConvertStringtoChar(dlg->FileName), CV_LOAD_IMAGE_ANYCOLOR);

				 Bitmap^ bmp = gcnew Bitmap(dlg->FileName);
				 Source_Image_PictureBox->Image = bmp;
				 Source_Image_PictureBox->Refresh();

				 Height_Label->Text = src->height + " pixels";
				 Width_Label->Text = src->width + " pixels";

				 lblDuongdan->Text = dlg->FileName;

				 /* Tự động nhận dạng sau khi mở ảnh*/
				 if (checkBox1->Checked == true)
				 {
					 Recognise_Click(sender, e);
				 }
	}
			 /*
			 *	Đóng ảnh
			 */
	private: System::Void Close_Img_Click(System::Object^  sender, System::EventArgs^  e) {

				 delete Source_Image_PictureBox->Image;
				 Source_Image_PictureBox->Image = nullptr;

				 delete Plate_PictureBox->Image;
				 Plate_PictureBox->Image = nullptr;

				 delete Gray_Img_pictureBox->Image;
				 Gray_Img_pictureBox->Image = nullptr;

				 IplImage *temp = src;
				 cvReleaseImage(&temp);
				 src = NULL;

				 cvDestroyAllWindows();

				 Height_Label->Text = "...";
				 Width_Label->Text = "...";
				 label5->Text = "...";
				 label6->Text = "...";
				 lblDuongdan->Text = "...";
	}
			 // Nhận dạng
	private: System::Void Recognise_Click(System::Object^  sender, System::EventArgs^  e) {

				 LPR_Main m;
				 System::Windows::Forms::DialogResult noImageLoaded;
				 System::Windows::Forms::DialogResult noRecognise;

				 if (!src)
				 {
					 noImageLoaded = MessageBox::Show(L"No image loaded.", L"Error",
						 MessageBoxButtons::OK, MessageBoxIcon::Error);
					 if (noImageLoaded == Windows::Forms::DialogResult::OK)
						 return;
				 }
				 else
				 {
					 IplImage *plate;

					 /* Tìm biển */
					 m.show_in_find_plate = radioButton1->Checked ? true : false;
					 plate = m.Crop_Plate(src);

					 if (!plate)  // Không tìm thấy
					 {
						 label8->Text = "";
						 cvDestroyAllWindows();

						 delete Plate_PictureBox->Image;
						 Plate_PictureBox->Image = nullptr;

						 delete Gray_Img_pictureBox->Image;
						 Gray_Img_pictureBox->Image = nullptr;

						 noRecognise = MessageBox::Show(L"Unable to recognize number plates. \n\rPlease try again with other pictures.", L"Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Stop);

						 if (noImageLoaded == Windows::Forms::DialogResult::OK)
						 {
							 cvReleaseImage(&plate);
							 return;
						 }
					 }
					 /* Tìm thấy -> Nhận dạng kí tự */
					 else
					 {
						 // HIện ảnh biển số và thông tin chi tiết
						 label5->Text = plate->height + " pixel";
						 label6->Text = plate->width + " pixel";

						 Bitmap^ plate_bmp = gcnew Bitmap(iplImage2Bitmap(plate));
						 Plate_PictureBox->Image = plate_bmp;
						 Plate_PictureBox->Refresh();

						 if (radioButton3->Checked)
						 {
							 cvDestroyAllWindows();
						 }

						 // Hiện ảnh xám có vẽ biển số
						 IplImage *gray_plate = m.Crop_Plate(src, 2);
						 Bitmap^ gray_bmp = gcnew Bitmap(iplImage2Bitmap(gray_plate));
						 Gray_Img_pictureBox->Image = gray_bmp;
						 Gray_Img_pictureBox->Refresh();

						 m.show_in_recognise = radioButton2->Checked ? true : false;

						 // Nhận dạng ký tự
						 string s = m.Recognise(plate);
						 System::String^ str = gcnew System::String(s.c_str());

						 // Chuyen doi du lieu string kieu system sang standard
						 msclr::interop::marshal_context context;
						 std::string standardString = context.marshal_as<std::string>(str);

						 ofstream FileDemo("FileLicensePlate.txt");
						 FileDemo << "Bien so:";
						 FileDemo << standardString;
						 FileDemo.close();

						 // Show ra textbox
						 if (str->Length < 7)
						 {
							 str = L"___-____";
						 }
						 else
						 {
							 str = str->Insert(3, "-");
							 if (str->Length == 9)
							 {
								 str = str->Insert(7, ".");
							 }
						 }

						 label8->Text = str;						
					 }

					 cvReleaseImage(&plate);
				 }
	}
			 // Exit 
	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::DialogResult result;
				 result = MessageBox::Show(L"Are you want to quit?", L"Exit",
					 MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
				 if (result == Windows::Forms::DialogResult::OK)
				 {
					 delete Source_Image_PictureBox->Image;
					 Source_Image_PictureBox->Image = nullptr;

					 delete Plate_PictureBox->Image;
					 Plate_PictureBox->Image = nullptr;

					 IplImage *temp = src;
					 cvReleaseImage(&temp);
					 src = NULL;
					 cvDestroyAllWindows();

					 this->Close();
				 }
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (button1->Text == ">>")
				 {
					 this->Size = System::Drawing::Size(1400, 700);
					 button1->Text = "<<";
				 }
				 else
				 {
					 this->Size = System::Drawing::Size(900, 700);
					 button1->Text = ">>";
				 }
				 this->Refresh();
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (checkBox1->Checked)
				 {
					 Recognise->Enabled = false;
				 }
				 else
					 Recognise->Enabled = true;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 Recognise_Click(sender, e);
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 Recognise_Click(sender, e);
	}

			 //URL
	private: System::Void trangChủToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 System::Diagnostics::Process::Start("http://fituct.org");
	}
			 // About me
	private: System::Void tácGiảToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 AboutmeForm f2;
				 f2.ShowDialog();
	}
	private: System::Void mởẢnhToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Open_Img_Click(sender, e);
	}

	private: System::Void nhậnDạngToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Recognise_Click(sender, e);
	}
	private: System::Void đóngẢnhToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close_Img_Click(sender, e);
	}

	private: System::Void thoátToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Exit_Click(sender, e);
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
				 AboutmeForm f2;
				 f2.ShowDialog();
	}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void Source_Image_PictureBox_Click(System::Object^  sender, System::EventArgs^  e) {
}
		 // Ham load anh len PictureBox
public:System::Void DrawCvImage(const cv::Mat& cvImage)
{
		   // only color images are supported
		   assert(cvImage.type() == CV_8UC3);

		   if ((Source_Image_PictureBox->Image == nullptr) || (Source_Image_PictureBox->Width != cvImage.cols) || (Source_Image_PictureBox->Height != cvImage.rows))
		   {
			   Source_Image_PictureBox->Width = cvImage.cols;
			   Source_Image_PictureBox->Height = cvImage.rows;
			   Source_Image_PictureBox->Image = gcnew System::Drawing::Bitmap(cvImage.cols, cvImage.rows);
		   }

		   // Create System::Drawing::Bitmap from cv::Mat
		   System::Drawing::Bitmap^ bmpImage = gcnew Bitmap(
			   cvImage.cols, cvImage.rows, cvImage.step,
			   System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			   System::IntPtr(cvImage.data)
			   );

		   // Draw Bitmap over a PictureBox
		   Graphics^ g = Graphics::FromImage(Source_Image_PictureBox->Image);

		   g->DrawImage(bmpImage, 0, 0, cvImage.cols, cvImage.rows);
		   Source_Image_PictureBox->Refresh();

		   delete g;
}
	   void wait(int seconds)
	   {
		   clock_t ew;
		   ew = clock() + seconds * CLOCKS_PER_SEC;
		   while (clock() < ew) {}
	   }
		 // CODE CAPTURE IMAGE
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			 CvCapture* capture = cvCaptureFromCAM(0);
			 if (!capture)
			 {
				 MessageBox::Show(L"Not Found", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }

			 cvNamedWindow("mywindow", CV_WINDOW_AUTOSIZE);
			 // Show the image captured from the camera in the window and repeat
			 while (1)
			 {
				 // Get one frame
				 IplImage* frame = cvQueryFrame(capture);
				 if (!frame)
				 {
					 MessageBox::Show(L"Not Found", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }

				 // Chú ý phần tăt phần show ảnh lên
				 //cvShowImage("mywindow", frame);
				 // Do not release the frame!
				 
				 int n;
				 bool kt = false;
				 for (n = 1; n>0; n++)
				 {
					 if (n < 2)
					 {
						 wait(1); // Delay 2 giây.
					 }
					 else
					 {
						 kt = true;
						 break;
					 }
				 }	

				 if (kt == true)
				 {
					 kt = false;
					 CvSize size = cvGetSize(frame);
					 IplImage* img = cvCreateImage(size, IPL_DEPTH_16S, 1);
					 img = frame;
					 cvSaveImage("bienso.jpg", img);
					 					 
					 //...............................................................................//
					 // load ra
					 cv::Mat cvImage = cv::imread("bienso.jpg");
					 if (cvImage.empty())
					 {
						 std::cout << "Cannot load image!" << std::endl;
						 return;
					 }
					 src = cvLoadImage("bienso.jpg");					 

					 // Luu anh da chup hien len man hinh
					 DrawCvImage(cvImage);

					 //Tien hanh nhan dang tu dong
					 LPR_Main m;
					 System::Windows::Forms::DialogResult noImageLoaded;
					 System::Windows::Forms::DialogResult noRecognise;

					 if (!src)
					 {
						 noImageLoaded = MessageBox::Show(L"No image loaded.", L"Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
						 if (noImageLoaded == Windows::Forms::DialogResult::OK)
							 return;
					 }
					 else
					 {
						 IplImage *plate;

						 /* Tìm biển */
						 m.show_in_find_plate = radioButton1->Checked ? true : false;
						 plate = m.Crop_Plate(src);

						 if (!plate)  // Không tìm thấy
						 {
							 label8->Text = "";
							 cvDestroyAllWindows();

							 delete Plate_PictureBox->Image;
							 Plate_PictureBox->Image = nullptr;

							 delete Gray_Img_pictureBox->Image;
							 Gray_Img_pictureBox->Image = nullptr;

							 /*noRecognise = MessageBox::Show(L"Unable to recognize number plates. \n\rPlease try again with other pictures.", L"Error",
								 MessageBoxButtons::OK, MessageBoxIcon::Stop);*/

							 if (noImageLoaded == Windows::Forms::DialogResult::OK)
							 {
								 cvReleaseImage(&plate);
								 return;
							 }
						 }
						 /* Tìm thấy -> Nhận dạng kí tự */
						 else
						 {
							 // HIện ảnh biển số và thông tin chi tiết
							 label5->Text = plate->height + " pixel";
							 label6->Text = plate->width + " pixel";

							 Bitmap^ plate_bmp = gcnew Bitmap(iplImage2Bitmap(plate));
							 Plate_PictureBox->Image = plate_bmp;
							 Plate_PictureBox->Refresh();

							 if (radioButton3->Checked)
							 {
								 cvDestroyAllWindows();
							 }

							 // Hiện ảnh xám có vẽ biển số
							 IplImage *gray_plate = m.Crop_Plate(src, 2);
							 Bitmap^ gray_bmp = gcnew Bitmap(iplImage2Bitmap(gray_plate));
							 Gray_Img_pictureBox->Image = gray_bmp;
							 Gray_Img_pictureBox->Refresh();

							 m.show_in_recognise = radioButton2->Checked ? true : false;

							 // Nhận dạng ký tự
							 string s = m.Recognise(plate);
							 System::String^ str = gcnew System::String(s.c_str());

							 // Chuyen doi du lieu string kieu system sang standard
							 msclr::interop::marshal_context context;
							 std::string standardString = context.marshal_as<std::string>(str);

							 ofstream FileDemo("FileLicensePlate.txt");
							 FileDemo << "Bien so:";
							 FileDemo << standardString;
							 FileDemo.close();

							 // Show ra textbox
							 if (str->Length < 7)
							 {
								 str = L"___-____";
							 }
							 else
							 {
								 str = str->Insert(3, "-");
								 if (str->Length == 9)
								 {
									 str = str->Insert(7, ".");
								 }
							 }

							 label8->Text = str;
						 }

						 cvReleaseImage(&plate);
					 }

					 //...............................................................................//
				 }
				 if ((cvWaitKey(10) & 255) == 27) break;
			 }
			 // Release the capture device housekeeping
			 cvReleaseCapture(&capture);
			 cvDestroyWindow("mywindow");

}
};
}