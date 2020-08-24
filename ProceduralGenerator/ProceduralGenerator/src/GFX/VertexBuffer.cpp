#include "pch.h"
#include "VertexBuffer.h"
namespace GFX
{
	VertexBuffer::VertexBuffer(float* data, GLuint size)
	{
		GLCall(glGenBuffers(1, &m_renderer_ID));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderer_ID));
		GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	VertexBuffer::~VertexBuffer()
	{
		GLCall(glDeleteBuffers(1, &m_renderer_ID));
	}
}


