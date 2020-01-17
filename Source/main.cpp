#include "Application.h"
#include <iostream>
#include "Event/InputEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"
#include "Event/EventHandler.h"

LPCWSTR title = TEXT("tile-game");

#ifdef _DEBUG
#include "Debug/Debug.h"

class Scene
{
public:
	EventHandler<MouseEvent>* onMousePressed;
	void SetOnMousePressed(EventHandler<MouseEvent>* me)
	{
		onMousePressed = me;
	}
};



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

	struct A : EventHandler<KeyEvent>
	{
		void handle(KeyEvent* e) override
		{
			Debug::Log("Custom EventHandler<KeyEvent>");
		}
	}_A;
	KeyEvent ke;
	_A.handle(&ke);

	

	Scene scene1;
	scene1.SetOnMousePressed([]()->EventHandler<MouseEvent>*
	{
		struct B : EventHandler<MouseEvent>
		{
			void handle(MouseEvent* e) override
			{
				Debug::Log("Custom EventHandler From ANONYMOUS FUNCTION Lambda<MouseEvent>");
			}
		};
		return new B;
	}());
	MouseEvent me;
	scene1.onMousePressed->handle(&me);

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