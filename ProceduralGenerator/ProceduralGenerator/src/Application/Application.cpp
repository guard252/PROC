#include "pch.h"
#include "Application.h"

Application* Application::s_instance = nullptr;

void Application::OnEvent(Event& e)
{
	EventHandler handler(e);
	handler.Handle<WindowCloseEvent>(BIND_EVENT(OnWindowClose));
	for (auto it = m_layer_stack.end(); it != m_layer_stack.begin();)
	{
		(*--it)->OnEvent(e);
		if (e.m_is_handled) break;
	}
}

Application::Application(const std::string_view name)
{
	LOGI("Application started");
	m_window = Window::Create(name);
	m_window->SetEventCallback(BIND_EVENT(OnEvent));
	s_instance = this;
}

Application::~Application()
{
	OnTerminate();
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_is_running = false;
	return true;
}

void Application::OnTerminate()
{
	LOGI("Application terminated");
}


void Application::PushLayer(Layer* l)
{
	m_layer_stack.PushLayer(l);
	l->OnAttach();
}

void Application::PushOverlay(Layer* l)
{
	m_layer_stack.PushOverlay(l);
	l->OnAttach();
}

Application& Application::Get()
{
	return *s_instance;
}

void Application::Run()
{


	while (m_is_running)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		for (Layer* layer : m_layer_stack)
		{
			layer->OnUpdate();
		}
		m_window->OnUpdate();
	}
}



