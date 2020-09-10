#pragma once

#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/detail/qualifier.hpp"
#include <string_view>

class GUIParameter
{
protected:
	std::string m_name;
public:
	GUIParameter(const std::string_view name) : m_name{ name } {}
	virtual void Show() const = 0;
	virtual ~GUIParameter() = default;

};

template<class T>
class SimpleSlider : public GUIParameter
{
	T& m_manipulated_value;
	T m_min, m_max;
public:
	SimpleSlider(const std::string_view name, 
				 const T& start, 
				 const T& end,
				 T& var_to_change) : GUIParameter(name), m_min{ start }, 
									 m_max{ end }, m_manipulated_value{ var_to_change }{}
	void ShowSlider() const;
	virtual void Show() const override { ShowSlider(); }
};

template<class T, size_t size>
class VectorSlider : public GUIParameter
{
	glm::vec<size, T, glm::qualifier::defaultp>& m_manipulated_value;
	T m_min, m_max;
public:
	VectorSlider(const std::string_view name,
		const T& start,
		const T& end,
		glm::vec<size, T, glm::qualifier::defaultp>& var_to_change) : GUIParameter(name), m_min{ start },
		m_max{ end }, m_manipulated_value{ var_to_change }{}
	void ShowSlider() const;
	virtual void Show() const override { ShowSlider(); }
};


template<>
void SimpleSlider<int>::ShowSlider() const
{
	ImGui::SliderInt(m_name.c_str(), &m_manipulated_value,  m_min, m_max);
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





