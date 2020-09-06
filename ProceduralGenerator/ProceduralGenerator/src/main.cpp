#include <iostream>

#include "Application/Application.h"
#include "Application/GUI/GUILayer.h"
#include "Logger/Logger.h"


int main()
{
    Logger::Init("Test");
    Application& procedural_generator = Application::Get();
    procedural_generator.PushLayer(new GUILayer);
    procedural_generator.Run();

}