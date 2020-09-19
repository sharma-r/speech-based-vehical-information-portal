#pragma once
#include "stdafx.h"
#include<cstdio>
//#include<iostream>
#include<cstdlib>
//#include "testing.h"
#include "Form2.h"
//#include "Form5.h"
#include <cstring>
#include <thread>


namespace vehicle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private: 


	private: System::Windows::Forms::Label^  Vehicles;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Splitter^  splitter2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Vehicles = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Vehicles
			// 
			this->Vehicles->AutoSize = true;
			this->Vehicles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Vehicles->ForeColor = System::Drawing::Color::DarkBlue;
			this->Vehicles->Location = System::Drawing::Point(620, 151);
			this->Vehicles->Name = L"Vehicles";
			this->Vehicles->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);
			this->Vehicles->Size = System::Drawing::Size(543, 53);
			this->Vehicles->TabIndex = 1;
			this->Vehicles->Text = L"Welcome to Vehicles Information portal";
			this->Vehicles->Click += gcnew System::EventHandler(this, &Form1::Vehicles_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(423, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1541, 1022);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 733);
			this->splitter1->TabIndex = 3;
			this->splitter1->TabStop = false;
			// 
			// splitter2
			// 
			this->splitter2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->splitter2->Location = System::Drawing::Point(3, 0);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(423, 733);
			this->splitter2->TabIndex = 4;
			this->splitter2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(102, 238);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);
			this->label1->Size = System::Drawing::Size(191, 46);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Say Begin to start";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(156, 569);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);
			this->label2->Size = System::Drawing::Size(65, 46);
			this->label2->TabIndex = 6;
			this->label2->Text = L"End";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(123, 406);
			this->label3->Name = L"label3";
			this->label3->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);
			this->label3->Size = System::Drawing::Size(141, 46);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Live Training";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1037, 733);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->Vehicles);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Vehicle Tutorial";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Vehicles_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	//private: void MyTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	//{
	//	//MessageBox.Show("The form will now be closed.", "Time Elapsed");
	//	//this.Close();
	//}

	private: System::Void Form1_Shown(System::Object^ sender, System::EventArgs^ e) {


		// system("Recording_Module.exe 3 input_file.wav input_file.txt");
////this->Show();
//		System.Windows.Forms.Timer MyTimer = new System.Windows.Forms.Timer();
//		MyTimer.Interval = (45 * 60 * 1000); // 45 mins
//		MyTimer.Tick += new EventHandler(MyTimer_Tick);
//		MyTimer.Start();


		this->Refresh();
		label1->Text = "Wait ....\nRecording will start in a moment";
		this->Refresh();
		System::Threading::Thread::Sleep(4000);
		label1->Text = "say Begin to start ";
		Refresh();
		System::Threading::Thread::Sleep(2000);
		//Refresh();
		string x;
		int chance = 0;

		do {

			vehicle::testing tt;
			x = tt.Test(0, "begin", "utkarsh");

			//label1->Text = x;
			//System::Windows::Forms::Label::Text pp;

			if (x == "begin") {
				//label1->Text = "ffdfd";
				//this->Hide();
				Form2^ f2 = gcnew Form2();
				f2->ShowDialog();
			}
			else if (x == "end") {
				this->Close();
				this->SendToBack();
			}
			else
			{
				// do nothing
				label1->Text = "Wait ....\nRecording will start in a moment";
				this->Refresh();
				System::Threading::Thread::Sleep(5000);
				label1->Text = "say Begin to start ";
				Refresh();
			}

			

		} while (chance-- && x != "end");
	}

		   

		  

private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	

	//vehicle::testing tt;
	//tt.Test(0, "begin", "avikash");
	
			 //this->Hide();
			 Form2^ f2 = gcnew Form2();
			 f2->ShowDialog();
		 }
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	this->SendToBack();
}


private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {

	//this->Hide();
	Form5^ f5 = gcnew Form5();
	f5->ShowDialog();
}
};
}

