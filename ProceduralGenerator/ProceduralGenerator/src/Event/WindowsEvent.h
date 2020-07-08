#pragma once
#include "Event.h"

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	DECLARE_EVENT_METHODS(ClosedWindow);
	DECLARE_EVENT_CATEGORY(EventCategoryApplication);

};

