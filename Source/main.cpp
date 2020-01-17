#include "Application.h"
#include <iostream>

#ifdef _DEBUG
int main()
{
	AllocConsole();
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	Application app(hInstance);
	std::cout << "Initializing window" << std::endl;
	if (!app.CreateAppWindow(TEXT("tilegame"), CW_USEDEFAULT, CW_USEDEFAULT, 256, 256))
	{
		MessageBox(app.GetHWND(), TEXT("Creating window failed"), TEXT("Window Error"), 0);
		return -1;
	}

	return static_cast<int>(app.Run());
}
#else
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpszCmdParam);

	Application app(hInstance);
	std::cout << "Initializing window" << std::endl;
	if (!app.CreateAppWindow(TEXT("tilegame"), CW_USEDEFAULT, CW_USEDEFAULT, 256, 256))
	{
		MessageBox(app.GetHWND(), TEXT("Creating window failed"), TEXT("Window Error"), 0);
		return -1;
	}

	return static_cast<int>(app.Run());
}
#endif