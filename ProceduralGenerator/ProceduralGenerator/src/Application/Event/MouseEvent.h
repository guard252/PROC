#pragma once
#include "Event.h"

class MouseMoveEvent : public Event
{
private:
	float m_x, m_y;
public:
	MouseMoveEvent(float x, float y) : m_x{ x }, m_y{ y }{};
	DECLARE_EVENT_METHODS(MovedMouse);
	DECLARE_EVENT_CATEGORY(EventCategoryMouse);

	virtual std::string ToString() const 
	{
		return "Mouse move at X: " + std::to_string(m_x) + " Y: " + std::to_string(m_y);
	}


};