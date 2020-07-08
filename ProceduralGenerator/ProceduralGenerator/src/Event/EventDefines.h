#pragma once
#include <functional>

#define BIT(x) (1 << (x))

#define IS_IN_CATEGORY(x, cat) ((x) & static_cast<int>(cat))

#define DECLARE_EVENT_METHODS(type) static EventType GetStaticType() { return EventType::type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }

#define DECLARE_EVENT_CATEGORY(cat) virtual int GetCategoryFlags() const override { return static_cast<int>(EventCategory::cat); }

#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)