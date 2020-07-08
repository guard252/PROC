#pragma once

#include <memory>
#include "../Window/Window.h"
#include "../Event/Event.h"
#include "../Event/WindowsEvent.h"

class Application
{
	std::unique_ptr<Window> m_window;
	bool m_is_running = true;
	
protected:
	virtual void OnUpdate() = 0;
	void OnEvent(Event& e);
	bool OnWindowClose(WindowCloseEvent& e);

public: 
	Application(std::string name);
	virtual ~Application() = default;

	void Run();
	

};