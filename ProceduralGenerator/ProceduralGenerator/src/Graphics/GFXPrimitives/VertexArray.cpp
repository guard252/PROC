#include "pch.h"
#include "VertexArray.h"


namespace GFX
{
	VertexArray::VertexArray()
	{
		GLCall(glCreateVertexArrays(1, &m_renderer_ID));
	}

	VertexArray::~VertexArray()
	{
		GLCall(glDeleteVertexArrays(1, &m_renderer_ID));
	}
	
}