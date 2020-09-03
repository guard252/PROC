#pragma once

#include "EventDefines.h"

enum class EventType
{
	None = 0, 
	ClosedWindow, 
	ResizedWindow, 
	FocusedWindow, 
	UnfocusedWindow, 
	PressedKey,
	ReleasedKey,
	PressedMouse,
	ReleasedMouse,
	MovedMouse,
	ScrolledMouse
};

enum class EventCategory
{
	None = 0, 
	EventCategoryApplication = BIT(0),
	EventCategoryKeyboard =    BIT(1),
	EventCategoryMouse =       BIT(2),
	EventCategoryMouseButton = BIT(3)
};