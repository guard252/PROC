#pragma once

#include <memory>
#include "../Window/Window.h"

class Application
{
	std::unique_ptr<Window> m_window;
	bool m_is_running = true;
	
protected:
	virtual void OnUpdate() = 0;
public: 
	Application(std::string name);
	virtual ~Application() = default;

	void Run();
	

};