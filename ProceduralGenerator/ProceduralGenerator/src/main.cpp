#include <iostream>

#include "Application/Application.h"
#include "Logger/Logger.h"
class Test : public Layer
{
    void OnUpdate() override { LOGT("TEST"); }
};

int main()
{
    Logger::Init();

    Application procedural_generator("Procedural generator");
    procedural_generator.PushLayer(new Test);
    procedural_generator.Run();
}