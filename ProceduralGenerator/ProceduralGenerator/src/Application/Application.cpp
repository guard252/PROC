#include "Application.h"

Application::Application(std::string name)
{
	m_window = std::unique_ptr<Window>(Window::Create(name));
}

void Application::Run()
{
	while (m_is_running)
	{

	}
}
