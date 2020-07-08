#include "Application.h"
void Application::OnEvent(Event& e)
{
	EventHandler handler(e);
	handler.Handle<WindowCloseEvent>(BIND_EVENT(OnWindowClose));
}

Application::Application(std::string name)
{
	m_window = std::unique_ptr<Window>(Window::Create(name));
	m_window->SetEventCallback(BIND_EVENT(OnEvent));
}

void Application::Run()
{
	while (m_is_running)
	{

		m_window->OnUpdate();
	}
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_is_running = false;
	return true;
}