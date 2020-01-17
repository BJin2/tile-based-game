#include "Application.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpszCmdParam);

	Application app(hInstance);

	if (!app.InitializeWindow())
	{
		MessageBox(app.GetHWND(), TEXT("Window initialize failed"), TEXT("Initialize Error"), 0);
		return -1;
	}

	return static_cast<int>(app.Run());
}