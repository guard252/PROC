#pragma once
#include "Layer.h"
class LayerStack
{
private:
	std::vector<Layer*> m_layers;
	std::vector<Layer*>::iterator m_layers_end{ m_layers.begin() };
public:				 
	std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
	std::vector<Layer*>::iterator end() { return m_layers.end(); }

	void PushLayer(Layer* l);
	void PopLayer(Layer* l);
	void PushOverlay(Layer* l);
	void PopOverlay(Layer* l);

	~LayerStack();
};

