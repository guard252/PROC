#include "GUIParameterSet.h"

void GUIParameterSet::AddParameter(GUIParameter* new_param)
{
    m_parameters.emplace_back(new_param);
}

void GUIParameterSet::OnGUIRender()
{
    for (auto* param : m_parameters)
    {
        param->Show();
    }
}