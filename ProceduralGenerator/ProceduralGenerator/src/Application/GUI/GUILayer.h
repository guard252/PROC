#pragma once
#include "Application/Layer/Layer.h"
class GUILayer : public Layer
{
public:
	GUILayer();
	virtual void OnEvent(Event& e) override;
	virtual void OnUpdate() override;
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnGUIRender();
	void Begin() ;
	void End();
};

