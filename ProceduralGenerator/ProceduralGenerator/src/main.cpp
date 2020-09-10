#include <iostream>

#include "Application/Application.h"
#include "Application/GUI/GUILayer.h"
#include "Logger/Logger.h"
#include "Application/GUI/GUIParameterSet.h"
#include "Application/GUI/GUIParameter.h"



int main()
{
    int a = 0;
    float b = 0;
    glm::vec2 vec = { 0.1, 0.2 };
    Logger::Init("Test");
    Application& procedural_generator = Application::Get();
    GUIParameterSet* params = new GUIParameterSet;
    params->AddParameter(new VectorSlider<float, 2>("Vec", 0, 1, vec));
    params->AddParameter(new SimpleSlider<int>("IntSlider", 0, 1, a));
    procedural_generator.PushLayer(params);
    procedural_generator.Run();

}