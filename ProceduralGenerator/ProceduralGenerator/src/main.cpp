#include <iostream>

#include "Application/Application.h"
#include "Logger/Logger.h"
int main()
{
    Logger::Init();

    Application procedural_generator("Procedural generator");
    procedural_generator.Run();
}