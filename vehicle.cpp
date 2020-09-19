// vehicle.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace vehicle;
using namespace System;

[STAThreadAttribute]
int main(cli::array<System::String^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	vehicle::Form1 f1;
	f1.ShowDialog();
	//Application::Run(gcnew Form1());
	return 0;
}
