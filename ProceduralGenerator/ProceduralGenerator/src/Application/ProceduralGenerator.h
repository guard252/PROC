#pragma once
#include "Application.h"

class ProceduralGenerator :	public Application
{
protected: 
	virtual void OnUpdate() override
	{

	}
public:
	ProceduralGenerator() : Application("Procedural generator") {}
};

