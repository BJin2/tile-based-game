#ifdef _DEBUG
	#include "Debug/Debug.h"
#endif

#include "Application.h"
#include "Input/RawInput.h"
#include "Event/EventManager.h"

Application::Application(HINSTANCE _hInstance)
{
	hInstance = _hInstance;
	hWnd = 0;
	className = TEXT("");
	msg = MSG();
	mapper = new EventMapper();
}

bool Application::InitializeWindow()
{
	WNDCLASS wc;

	//Set windows class
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = RawInput::WndProc;
	wc.lpszClassName = className;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//Register windows class
	if (!RegisterClass(&wc))
		return false;

	Debug::Log("Initialized window");

	return true;
}

bool Application::CreateAppWindow(LPCWSTR title, int x, int y, int width, int height)
{
	className = title;
	if (!InitializeWindow())
		return false;

	//Create windows
	this->hWnd = CreateWindow(className, className, WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, (HMENU)NULL, hInstance, NULL);
	if (!this->hWnd)
		return false;

	ShowWindow(this->hWnd, SW_SHOW);
	UpdateWindow(this->hWnd);

	Debug::Log("Created window");

	EventManager::Instance()->RegisterMapper(hWnd, mapper);
	mapper->SetOnEvent([](const IEvent* e)->void
		{
			//KeyEvent* k = const_cast<KeyEvent*>(e);
			Debug::Log("Window1 key pressed");
			//std::cout << "Key Pressed : " << Debug::KeyCodeToString(e->GetKeyCode()) << std::endl;
		}, KeyEventData::type);

	return true;
}

WPARAM Application::Run()
{
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}