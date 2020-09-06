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

class MouseClickEvent : public Event
{
private:
	float m_x, m_y;
	
public:
	enum struct ClickType
	{
		PRESSED, 
		RELEASED
	} m_click_type;
	MouseClickEvent(float x, float y, ClickType t) : m_x{ x }, m_y{ y }, m_click_type{ t } {};
	DECLARE_EVENT_METHODS(PressedMouse);
	DECLARE_EVENT_CATEGORY(EventCategoryMouse);

	virtual std::string ToString() const
	{
		return std::string("Mouse ") + (m_click_type == ClickType::PRESSED ? "pressed" : "released") + 
			" at X: " + std::to_string(m_x) + " Y: " + std::to_string(m_y);
	}
};

