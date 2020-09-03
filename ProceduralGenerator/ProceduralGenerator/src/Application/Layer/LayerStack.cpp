#include "pch.h"
#include "LayerStack.h"

void LayerStack::PushLayer(Layer* l)
{
	m_layers_end = m_layers.emplace(m_layers_end, l);
}

void LayerStack::PopLayer(Layer* l)
{
	auto it = std::find(begin(), end(), l);
	assert(it <= m_layers_end);
	if (it != end())
	{
		m_layers_end--;
		m_layers.erase(m_layers_end + 1);
	}
}

void LayerStack::PushOverlay(Layer* l)
{
	m_layers.emplace_back(l);
}

void LayerStack::PopOverlay(Layer* l)
{
	auto it = std::find(begin(), end(), l);
	assert(it > m_layers_end);
	if (it != end())
	{
		m_layers.erase(m_layers_end + 1);
	}
}

LayerStack::~LayerStack()
{
	for (auto* l : m_layers)
	{
		delete l;
	}
}
