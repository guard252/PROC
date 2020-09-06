#pragma once

#include <memory>
#include "Window/Window.h"
#include "Event/Event.h"
#include "Event/WindowsEvent.h"
#include "Layer/LayerStack.h"

class Application
{
	Window* m_window;
	bool m_is_running = true;
	LayerStack m_layer_stack;
protected:
	virtual void OnUpdate();
	void OnEvent(Event& e);
	bool OnWindowClose(WindowCloseEvent& e);

public: 
	Application(std::string name);
	virtual ~Application() = default;
	void PushLayer(Layer* l);
	void PushOverlay(Layer* l);

	void Run();

	static Application& Get()
	{
		static Application instance("app");
		return instance;
	}

	Window* GetWindow() const { return m_window; }

	

};