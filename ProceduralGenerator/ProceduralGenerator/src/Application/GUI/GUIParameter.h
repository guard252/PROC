#pragma once


#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/detail/qualifier.hpp"
#include <string_view>
#include <string>
#include "DLLHeader.h"



class GUIParameter
{
protected:
	std::string m_name;
public:
	GUIParameter(const std::string_view name) : m_name{ name } {}
	virtual void Show() const = 0;
	virtual ~GUIParameter() {}

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




