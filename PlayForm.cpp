#include "PlayForm.h"
#include <Windows.h>

using namespace Курсовая; // Название проекта

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PlayForm);
	return 0;
}
 