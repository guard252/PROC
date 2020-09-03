#pragma once

#include "EventEnums.h"

#include <string>

class Event
{
public:
	bool m_is_handled;

	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual int GetCategoryFlags() const = 0;
	virtual std::string ToString() const { return GetName(); }

	bool IsInCategory(EventCategory category)
	{
		return IS_IN_CATEGORY(GetCategoryFlags(), category);
	}
};

class EventHandler
{
private:
	Event& m_event;
public: 
	EventHandler(Event& event) : m_event(event) {}

	template<class T, class F> bool Handle(const F& func)
	{
		if (m_event.GetEventType() == T::GetStaticType())
		{
			m_event.m_is_handled = func(static_cast<T&>(m_event));
			return true;
		}
		return false;
	}
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	os << e.ToString();
	return os;
}

