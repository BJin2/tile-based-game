#pragma once

class IEvent;
class KeyEvent;
class MouseEvent;

namespace EventConverter
{
	const KeyEvent* ToKeyEvent(const IEvent* e);
	MouseEvent* ToMouseEvent(IEvent* e);
}