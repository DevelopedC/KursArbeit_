#include "PlayForm.h"
#include <Windows.h>

using namespace ��������; // �������� �������

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PlayForm);
	return 0;
}
 