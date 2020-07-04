#pragma once
#include <string>

#include <glew/glew.h>
#include <glfw3.h>

class Window
{
    GLFWwindow* m_window;

    struct WindowMainData
    {
        std::string name;
        uint32_t width;
        uint32_t height;
    };
    WindowMainData m_window_data;
private:
    void Init();
    void OnUpdate();
public:
    Window(uint32_t width, uint32_t height, std::string name);
    Window(std::string name); // Fullscreen window 
    ~Window();



    WindowMainData get_data() const { return m_window_data; }
};

