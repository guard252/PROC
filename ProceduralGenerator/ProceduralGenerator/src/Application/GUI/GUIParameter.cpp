#include "GUIParameter.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"



template<>
void SimpleSlider<int>::ShowSlider() const
{
	ImGui::SliderInt(m_name.c_str(), &m_manipulated_value, m_min, m_max);
}

template<>
void SimpleSlider<float>::ShowSlider() const
{
	ImGui::SliderFloat(m_name.c_str(), &m_manipulated_value, m_min, m_max);
}

template<>
void VectorSlider<float, 2>::ShowSlider() const
{
	ImGui::SliderFloat2(m_name.c_str(), glm::value_ptr(m_manipulated_value), m_min, m_max);
}

template<>
void VectorSlider<float, 3>::ShowSlider() const
{
	ImGui::SliderFloat3(m_name.c_str(), glm::value_ptr(m_manipulated_value), m_min, m_max);
}

template<>
void VectorSlider<float, 4>::ShowSlider() const
{
	ImGui::SliderFloat4(m_name.c_str(), glm::value_ptr(m_manipulated_value), m_min, m_max);
}

template<>
void VectorSlider<int, 2>::ShowSlider() const
{
	ImGui::SliderInt2(m_name.c_str(), glm::value_ptr(m_manipulated_value), m_min, m_max);
}

template<>
void VectorSlider<int, 3>::ShowSlider() const
{
	ImGui::SliderInt3(m_name.c_str(), glm::value_ptr(m_manipulated_value), m_min, m_max);
}

template<>
void VectorSlider<int, 4>::ShowSlider() const
{
	ImGui::SliderInt4(m_name.c_str(), glm::value_ptr(m_manipulated_value), m_min, m_max);
}

template<class T, size_t size>
void VectorSlider<T, size>::ShowSlider() const
{
	static_assert(false);
}

template<class T>
void SimpleSlider<T>::ShowSlider() const
{
	static_assert(false);
}


