#pragma once
#include "GUILayer.h"
#include "GUIParameter.h"
class GUIParameterSet :
    public GUILayer
{
public:
    void AddParameter(GUIParameter* new_param)
    {
        m_parameters.emplace_back(new_param);
    }
private:
    std::vector<GUIParameter*> m_parameters;
    virtual void OnGUIRender() override
    {
        for (auto* param : m_parameters)
        {
            param->Show();
        }
    }
};

