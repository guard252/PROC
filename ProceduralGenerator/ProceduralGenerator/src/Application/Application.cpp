#include "pch.h"
#include "Application.h"

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

Application::Application(std::string name)
{
	m_window = Window::Create(name);
	m_window->SetEventCallback(BIND_EVENT(OnEvent));
	LOGI("Application started");
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_is_running = false;
	LOGI("Window closed.");
	return true;
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
	static Application instance("app");
	return instance;
}

void Application::Run()
{
	glClearColor(0.2, 0.3, 0.5, 1);
	float data[] = { -0.5, -0.5,
					  0,    0.8,
					  0.5, -0.5 };
	GFX::VertexBuffer buff(data, sizeof data);
	GFX::VertexArray vao;
	GFX::VertexLayout layout;
	layout.Push<float>(2);
	vao.AddBuffer(buff, layout);
	GFX::VertexShader vert("src/shaders/vertex.glsl");
	GFX::FragmentShader frag("src/shaders/fragment.glsl");
	vert.CreateShader();
	frag.CreateShader();

	GFX::ShaderProgram<GFX::VertexShader, GFX::FragmentShader> program(vert, frag);
	program.Bind();
	program.SetUniform4f("u_color", glm::vec4(0, 0, 1, 1));

	while (m_is_running)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));

		for (Layer* layer : m_layer_stack)
		{
			layer->OnUpdate();
		}


		m_window->OnUpdate();
	}
}



