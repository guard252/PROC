#include "pch.h"
#include "Window.h"

#include "../Event/WindowsEvent.h"

void Window::Init()
{
	if (!glfwInit())
	{
		throw std::runtime_error("Unable to initialize glfw context");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	
	m_window = glfwCreateWindow(m_window_data.size.x, m_window_data.size.y, m_window_data.name.c_str(), m_monitor, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		throw std::runtime_error("Unable to create window");
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &m_window_data);
	SetCallbacks();
	
	
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		glfwTerminate();
		throw std::runtime_error("Unable to init GLEW");
	}
	EnableDebugOutput();
}

void Window::Shutdown()
{
	glfwDestroyWindow(m_window);
}

void Window::SetCallbacks()
{
	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
		WindowMainData& data = *(WindowMainData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		data.callback(event);
		});
}

void Window::OnUpdate()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

Window* Window::Create(std::string name)
{
	return new Window(name);
}

Window::Window(uint32_t width, uint32_t height, std::string name) :
	m_window_data{ {width, height}, name }
{
	Init();
}

Window::Window(std::string name)
{
	m_window_data.name = name;
	m_monitor = glfwGetPrimaryMonitor();

	Init();
}

Window::~Window()
{
	Shutdown();
}
