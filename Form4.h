#include<cstdio>
#include<cstdlib>
#include "Form3.h"


#pragma once

namespace vehicle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form4
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:
		Form4(void)
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
		~Form4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;


	protected: 

	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form4::typeid));
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// splitter1
			// 
			this->splitter1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(342, 679);
			this->splitter1->TabIndex = 0;
			this->splitter1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(103, 121);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Pulsar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form4::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(103, 228);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Passion";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form4::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(103, 344);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 33);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Activa";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form4::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(103, 446);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(87, 32);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Apache";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form4::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(627, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 21);
			this->label1->TabIndex = 5;
			this->label1->Text = L"PULSAR";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &Form4::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(348, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(691, 84);
			this->label2->TabIndex = 6;
			this->label2->Text = resources->GetString(L"label2.Text");
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(649, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 21);
			this->label3->TabIndex = 7;
			this->label3->Text = L"PASSION";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(627, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 21);
			this->label4->TabIndex = 8;
			this->label4->Text = L"APACHE";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(631, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 21);
			this->label5->TabIndex = 9;
			this->label5->Text = L"ACTIVA";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(348, 57);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(713, 84);
			this->label6->TabIndex = 10;
			this->label6->Text = resources->GetString(L"label6.Text");
			this->label6->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(348, 57);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(1082, 84);
			this->label7->TabIndex = 11;
			this->label7->Text = resources->GetString(L"label7.Text");
			this->label7->Visible = false;
			this->label7->Click += gcnew System::EventHandler(this, &Form4::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(348, 53);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(693, 84);
			this->label8->TabIndex = 12;
			this->label8->Text = resources->GetString(L"label8.Text");
			this->label8->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(439, 162);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 400);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(452, 162);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1024, 768);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form4::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(452, 162);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(500, 375);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(402, 162);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(872, 578);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox4->TabIndex = 16;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(6, 31);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(327, 26);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Say any of the following Bike names";
			this->label9->Click += gcnew System::EventHandler(this, &Form4::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(103, 569);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(75, 26);
			this->label10->TabIndex = 22;
			this->label10->Text = L"  End   ";
			this->label10->Click += gcnew System::EventHandler(this, &Form4::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(660, 305);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(354, 72);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Nothing has been detected.\r\nPlease, Say again ....\r\n";
			this->label11->Visible = false;
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1327, 679);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->splitter1);
			this->Name = L"Form4";
			this->Text = L"Bikes";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Shown += gcnew System::EventHandler(this, &Form4::Form4_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox1->Visible = true;
	label1->Visible = true;
	label2->Visible = true;

	// make others false
	pictureBox2->Visible = false;
	label8->Visible = false;
	label3->Visible = false;
	pictureBox3->Visible = false;
	label5->Visible = false;
	label6->Visible = false;
	pictureBox4->Visible = false;
	label4->Visible = false;
	label7->Visible = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Visible = true;
	label8->Visible = true;
	label3->Visible = true;


	// make others false
	pictureBox3->Visible = false;
	label5->Visible = false;
	label6->Visible = false;
	pictureBox4->Visible = false;
	label4->Visible = false;
	label7->Visible = false;
	pictureBox1->Visible = false;
	label1->Visible = false;
	label2->Visible = false;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox3->Visible = true;
	label5->Visible = true;
	label6->Visible = true;


	// make others false
	pictureBox2->Visible = false;
	label8->Visible = false;
	label3->Visible = false;
	pictureBox4->Visible = false;
	label4->Visible = false;
	label7->Visible = false;
	pictureBox1->Visible = false;
	label1->Visible = false;
	label2->Visible = false;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox4->Visible = true;
	label4->Visible = true;
	label7->Visible = true;


	// make others false
	pictureBox2->Visible = false;
	label8->Visible = false;
	label3->Visible = false;
	pictureBox3->Visible = false;
	label5->Visible = false;
	label6->Visible = false;
	pictureBox1->Visible = false;
	label1->Visible = false;
	label2->Visible = false;

}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Form4_Shown(System::Object^ sender, System::EventArgs^ e) {
	//system("Recording_Module.exe 3 input_file.wav input_file.txt");

	this->Refresh();
	label9->Text = "Wait ....\n Recording will start in a moment";
	this->Refresh();
	System::Threading::Thread::Sleep(4000);
	label9->Text = "say following bikes \nto see info";
	Refresh();
	//System::Threading::Thread::Sleep(1000);
	//Refresh();
	string x;
	int chance = 4;

	do {

		vehicle::testing tt;
		x = tt.Test(3, "pulsar", "utkarsh");

		//label1->Text = x;
		//System::Windows::Forms::Label::Text pp;

		if (x == "pulsar") {
			pictureBox1->Visible = true;
			label1->Visible = true;
			label2->Visible = true;

			// make others false
			pictureBox2->Visible = false;
			label8->Visible = false;
			label3->Visible = false;
			pictureBox3->Visible = false;
			label5->Visible = false;
			label6->Visible = false;
			pictureBox4->Visible = false;
			label4->Visible = false;
			label7->Visible = false;
			this->Refresh();
			System::Threading::Thread::Sleep(5000);

		}
		else
			if (x == "passion") {
				pictureBox2->Visible = true;
				label8->Visible = true;
				label3->Visible = true;


				// make others false
				pictureBox3->Visible = false;
				label5->Visible = false;
				label6->Visible = false;
				pictureBox4->Visible = false;
				label4->Visible = false;
				label7->Visible = false;
				pictureBox1->Visible = false;
				label1->Visible = false;
				label2->Visible = false;
				this->Refresh();
				System::Threading::Thread::Sleep(5000);


			}
			else if (x == "activa") {
				pictureBox3->Visible = true;
				label5->Visible = true;
				label6->Visible = true;


				// make others false
				pictureBox2->Visible = false;
				label8->Visible = false;
				label3->Visible = false;
				pictureBox4->Visible = false;
				label4->Visible = false;
				label7->Visible = false;
				pictureBox1->Visible = false;
				label1->Visible = false;
				label2->Visible = false;
				this->Refresh();
				System::Threading::Thread::Sleep(5000);


			}
			else if (x == "apache") {
				pictureBox4->Visible = true;
				label4->Visible = true;
				label7->Visible = true;


				// make others false
				pictureBox2->Visible = false;
				label8->Visible = false;
				label3->Visible = false;
				pictureBox3->Visible = false;
				label5->Visible = false;
				label6->Visible = false;
				pictureBox1->Visible = false;
				label1->Visible = false;
				label2->Visible = false;
				this->Refresh();
				System::Threading::Thread::Sleep(5000);

			}
			else if (x == "end") {
				this->Close();
				this->SendToBack();
				//Form2^ f2 = gcnew Form2();
				//f2->ShowDialog();
			}
			else
			{
				// nothing recognized
				

				label9->Text = "Wait .... Recording will start in a moment";
				label11->Visible = true;
				this->Refresh();
				System::Threading::Thread::Sleep(5000);
				label9->Text = "say following bikes to see info";
				Refresh();
			}

		pictureBox1->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		pictureBox2->Visible = false;
		label8->Visible = false;
		label3->Visible = false;
		pictureBox3->Visible = false;
		label5->Visible = false;
		label6->Visible = false;
		pictureBox4->Visible = false;
		label4->Visible = false;
		label7->Visible = false;
		label11->Visible = false;
		this->Refresh();

	} while (chance-- && x != "end");

}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	this->SendToBack();
	//Form2^ f2 = gcnew Form2();
	//f2->ShowDialog();

}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
