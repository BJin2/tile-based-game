#pragma once

template <class T>
class EventHandler
{
private : 

public : 
	virtual void handle(T* e) = 0;
};

