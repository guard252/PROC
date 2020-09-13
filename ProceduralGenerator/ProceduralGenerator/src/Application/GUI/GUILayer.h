#pragma once
#include "Application/Layer/Layer.h"
#include "DLLHeader.h"
class PROC_API GUILayer : public Layer
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
	~GUILayer() {}
};

