#pragma once
#include "../Event/Event.h"
#include <string>
class Layer
{
	std::string m_name;
public:
	Layer(const std::string& name = "") : m_name{ name } {}

	virtual void OnEvent(Event& e) {}
	virtual void OnUpdate() {}
	virtual void OnAttach() {}
	virtual void OnDetach() {}

	virtual ~Layer() {}
};

