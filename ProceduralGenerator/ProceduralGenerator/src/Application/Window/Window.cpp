#include "pch.h"
#include "Window.h"


void Window::Init()
{
	if (!glfwInit())
	{
		LOGE("Unable to initialize glfw context")
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

	m_window = glfwCreateWindow(m_window_data.size.x, m_window_data.size.y, m_window_data.name.c_str(), m_monitor, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		LOGE("Unable to create window");
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &m_window_data);
	SetCallbacks();

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		glfwTerminate();
		LOGE("Unable to init GLEW");
	}
}

void Window::Shutdown()
{
	glfwDestroyWindow(m_window);
	LOGI("Application terminated");
}

void Window::SetCallbacks()
{
	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
		WindowMainData& data = *(WindowMainData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		data.callback(event);
		});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowMainData& data = *(WindowMainData*)glfwGetWindowUserPointer(window);
			MouseMoveEvent event((float)xPos, (float)yPos);
			data.callback(event);
		});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int)
		{
			WindowMainData& data = *(WindowMainData*)glfwGetWindowUserPointer(window);
			MouseClickEvent::ClickType click_type;
			switch (action)
			{
			case GLFW_PRESS:
			{
				click_type = MouseClickEvent::ClickType::PRESSED;
			}
			break;
			case GLFW_RELEASE:
			{
				click_type = MouseClickEvent::ClickType::RELEASED;
			}
			break;
			default: return;
			}
			double x, y;
			glfwGetCursorPos(window, &x, &y);
			MouseClickEvent e(x, y, click_type);
			LOGI(e.ToString());
			data.callback(e);


		});
}

void Window::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
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
