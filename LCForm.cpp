#include "LCForm.h"
#include <Windows.h>

using namespace AKLumCalc; // Название проекта

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew LCForm);
	return 0;
}

