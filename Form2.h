#pragma once

#include "stdafx.h"
#include<cstdio>
#include<cstdlib>

//#include "testing.h"
#include "Form3.h"
#include "Form4.h"
#include "Form5.h"

namespace vehicle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::ComponentModel::IContainer^ components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>


		

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// splitter1
			// 
			this->splitter1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->splitter1->Location = System::Drawing::Point(10, 10);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(380, 713);
			this->splitter1->TabIndex = 0;
			this->splitter1->TabStop = false;
			this->splitter1->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Form2::splitter1_SplitterMoved);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 175);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);
			this->label1->Size = System::Drawing::Size(283, 46);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Say \'Car\' or \'Bikes\' or \'End\'";
			this->label1->Click += gcnew System::EventHandler(this, &Form2::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(110, 309);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Car";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(110, 385);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 33);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Bikes";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(110, 468);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 33);
			this->button3->TabIndex = 4;
			this->button3->Text = L"End";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(608, 192);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(647, 408);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(387, 13);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1189, 808);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form2::pictureBox2_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1354, 733);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->splitter1);
			this->MinimizeBox = false;
			this->Name = L"Form2";
			this->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);
			this->Text = L"Options";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->Shown += gcnew System::EventHandler(this, &Form2::Form2_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//public: Form2^ f2 = gcnew Form2();

	private: System::Void splitter1_SplitterMoved(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				  //system("Recording_Module.exe 3 input_file.wav input_file.txt");

			 //vehicle::testing tt;
		     //tt.Test();

			 //this->Hide();
			 Form3^ f3 = gcnew Form3();
			 f3->ShowDialog();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 //this->Hide();
			 Form4^ f4 = gcnew Form4();
			 f4->ShowDialog();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			 /*this->Hide();
			 Form5^ f5 = gcnew Form5();
			 f5->ShowDialog();
			 */
			this->Close();
			this->SendToBack();
			//this->Refresh();
		 }

private: System::Void Form2_Shown(System::Object^  sender, System::EventArgs^  e) {
	//system("Recording_Module.exe 3 input_file.wav input_file.txt");

	this->Refresh();
	label1->Text = "Wait .... Recording will start in a moment";
	this->Refresh();
	System::Threading::Thread::Sleep(4000);
	label1->Text = "say 'car' or 'bike' or 'end' to proceed ";
	Refresh();
	//System::Threading::Thread::Sleep(1000);
	//Refresh();

	string x;
	int chance = 4;

	do {

		vehicle::testing tt;
		string x = tt.Test(1, "car", "utkarsh");

		//label1->Text = x;
		//System::Windows::Forms::Label::Text pp;

		if (x == "car") {
			//label1->Text = "ffdfd";
			//this->Hide();
			Form3^ f3 = gcnew Form3();
			f3->ShowDialog();
			label1->Text = "Wait .... Recording will start in a moment";
			this->Refresh();
			System::Threading::Thread::Sleep(5000);
			label1->Text = "say 'car' or 'bike' or 'end' to proceed ";
			this->Refresh();

			//this->Refresh();
		}
		else
			if (x == "bike") {
				//label1->Text = "ffdfd";
				//this->Hide();
				Form4^ f4 = gcnew Form4();
				f4->ShowDialog();
				label1->Text = "Wait .... Recording will start in a moment";
				this->Refresh();
				System::Threading::Thread::Sleep(5000);
				label1->Text = "say 'car' or 'bike' or 'end' to proceed ";
				this->Refresh();

				//this->Refresh();
			}
			else if (x == "end") {
				//label1->Text = "ffdfd";
				this->Close();
				this->SendToBack();
				
			}
			else {
				// nothing recognized
				
				label1->Text = "Wait .... Recording will start in a moment";
				this->Refresh();
				System::Threading::Thread::Sleep(3000);
				label1->Text = "say 'car' or 'bike' or 'end' to proceed ";
				this->Refresh();
			}
		

	} while (chance-- && x != "end");

		 }
private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
