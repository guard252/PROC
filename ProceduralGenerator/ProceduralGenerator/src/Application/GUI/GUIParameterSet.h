#pragma once
#include "GUILayer.h"
#include "GUIParameter.h"

class GUIParameterSet : public GUILayer
{
    std::vector<GUIParameter*> m_parameters;
public:
    void AddParameter(GUIParameter* new_param);
    virtual void OnGUIRender() override;
    ~GUIParameterSet() {}
};

