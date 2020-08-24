#include "pch.h"
#include "Application.h"
void Application::OnUpdate()
{
}
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
	glClearColor(0.2, 0.3, 0.5, 1);
	float data[] = { -0.5, -0.5,
					  0,    0.8,
					  0.5, -0.5 };
	GFX::VertexBuffer buff(data, sizeof data);
	GFX::VertexArray vao;
	GFX::VertexLayout layout;
	layout.Push<float>(2);
	vao.AddBuffer(buff, layout);
	GFX::VertexShader vert("shaders/vertex.glsl");
	GFX::FragmentShader frag("shaders/fragment.glsl");
	vert.CreateShader();
	frag.CreateShader();

	GFX::ShaderProgram<GFX::VertexShader, GFX::FragmentShader> program(vert, frag);
	program.Bind();
	while (m_is_running)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
		m_window->OnUpdate();
	}
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_is_running = false;
	return true;
}