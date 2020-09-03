#pragma once
#include "../Event/Event.h"
class Layer
{
	std::string m_name;
public:
	Layer(std::string name = "") : m_name{ name } {}

	virtual void OnEvent(Event& e) {};
	virtual void OnUpdate() {};
	virtual void OnAttach() {};
	virtual void OnDetach() {};

	virtual ~Layer() = default;
};

