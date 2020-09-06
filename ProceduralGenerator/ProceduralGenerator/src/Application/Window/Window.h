#pragma once
#include <string>
#include <functional>

#include <glew/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include "../Event/Event.h"

class Window
{
    using EventCallback = std::function<void(Event&)>;

    GLFWwindow* m_window = nullptr;
    GLFWmonitor* m_monitor = nullptr;

    struct WindowMainData
    {
        glm::uvec2 size = { 1280, 720 };
        std::string name;
        EventCallback callback;
    };
    WindowMainData m_window_data;
private:
    void Init();
    void Shutdown();
    void SetCallbacks();
public:
    Window(uint32_t width, uint32_t height, std::string name);
    Window(std::string name);
    ~Window();
    
    virtual void OnUpdate();
    
    static Window* Create(std::string name);

    void SetEventCallback(const EventCallback& callback) { m_window_data.callback = callback; }

    glm::uvec2 GetSize() const { return m_window_data.size; }
    uint32_t GetWidth() const { return m_window_data.size.x; }
    uint32_t GetHeight() const { return m_window_data.size.y; }
    std::string GetName() const { return m_window_data.name; }

    GLFWwindow* GetRawWindow() const { return m_window; }

};

