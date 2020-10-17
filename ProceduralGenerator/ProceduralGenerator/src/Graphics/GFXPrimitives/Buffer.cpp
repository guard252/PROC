#include "Buffer.h"

namespace GFX
{
	VertexBuffer::VertexBuffer(void* data, size_t size)
	{
		glCreateBuffers(1, &m_renderer_ID);
		glNamedBufferData(m_renderer_ID, size, data, GL_STATIC_DRAW);
		//glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_renderer_ID);
	}


	IndexBuffer::IndexBuffer(GLuint* indices, GLuint count)
	{
		glCreateBuffers(1, &m_renderer_ID);
		glNamedBufferData(m_renderer_ID, count * sizeof(GLuint), indices, GL_STATIC_DRAW);
	}
	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_renderer_ID);
	}
}