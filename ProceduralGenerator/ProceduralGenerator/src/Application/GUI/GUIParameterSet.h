#pragma once
#include "DLLHeader.h"
#include "GUILayer.h"
#include "GUIParameter.h"

class PROC_API GUIParameterSet : public GUILayer
{
    std::vector<GUIParameter*> m_parameters;
public:
    void AddParameter(GUIParameter* new_param);
    virtual void OnGUIRender() override;
    ~GUIParameterSet() {}
};

