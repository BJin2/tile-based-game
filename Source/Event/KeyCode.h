#pragma once
enum class EventType: __int8 {NO_TYPE, KeyEvent, MouseEvent};
enum class KeyCode : __int8 {
	NO_CODE, A, B, C, D, E, F, G, H, I, J, K, L, M, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	Mouse_0, Mouse_1, Mouse_2,
	Num_0, Num_1, Num_2, Num_3, Num_4, Num_5, Num_6, Num_7, Num_8, Num_9,
	Numpad_0, Numpad_1, Numpad_2, Numpad_3, Numpad_4, Numpad_5, Numpad_6, Numpad_7, Numpad_8, Numpad_9,
	Escape, LCtrl, LShift, LAlt, LSystem,
	RCtrl, RShift, RAlt, RSystem, Menu,
	LBracket, RBracket, Semicolon, Comma, Period, Quote, Slash, Backslash,
	Tilde, Equal, Hyphen,
	Space, Enter, Backspace, Tab,
	PageUp, PageDown, End, Home, Insert, Delete,
	Add, Subtract, Multiply, Divide,
	Left, Right, Up, Down,
	F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
	Pause,
	KeyCount,

	//Deprecated values
	Dash = Hyphen,
	BackSpace = Backspace,
	BackSlash = Backslash,
	SemiColon = Semicolon,
	Return = Enter
};