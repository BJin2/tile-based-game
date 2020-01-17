#include "Application.h"
#include "Event/KeyEvent.h"
#include "Scene.h"

LPCWSTR title = TEXT("tile-game");

#ifdef _DEBUG
#include "Debug/Debug.h"
int main()
{
	AllocConsole();
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	Application app(hInstance);
	Debug::Log("Initializing window");
	if (!app.CreateAppWindow(title, CW_USEDEFAULT, CW_USEDEFAULT, 256, 256))
	{
		MessageBox(app.GetHWND(), TEXT("Creating window failed"), TEXT("Window Error"), 0);
		return -1;
	}
	//register scene
	Scene scene1;
	scene1.SetOnKeyPressed([](const KeyEvent* e)->void
	{
			std::cout << "Window1.onKEYpressed" << std::endl;
			std::cout << "Key Pressed : " << Debug::KeyCodeToString(e->GetKeyCode());
	});

	app.SetScene(scene1);

	return static_cast<int>(app.Run());
}
#endif
#ifdef NDEBUG
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpszCmdParam);

	Application app(hInstance);
	if (!app.CreateAppWindow(title, CW_USEDEFAULT, CW_USEDEFAULT, 256, 256))
	{
		MessageBox(app.GetHWND(), TEXT("Creating window failed"), TEXT("Window Error"), 0);
		return -1;
	}

	return static_cast<int>(app.Run());
}
#endif