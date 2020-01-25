#include"EventConverter.h"
#include"Event.h"
#include"KeyEvent.h"
#include"MouseEvent.h"

const KeyEvent* EventConverter::ToKeyEvent(const IEvent* e)
{
	IEventData* ied = e->GetData();
	KeyEventData* ked = static_cast<KeyEventData*>(ied);
	IEvent* temp = const_cast<IEvent*>(e);
	KeyEvent* ke = static_cast<KeyEvent*>(temp);
	ke->SetData(ked);
	return ke;
}
