#include "pch.h"
#include "VertexArray.h"


namespace GFX
{
	VertexArray::VertexArray()
	{
		GLCall(glGenVertexArrays(1, &m_renderer_ID));
		GLCall(glBindVertexArray(m_renderer_ID));
	}

	VertexArray::~VertexArray()
	{
		GLCall(glDeleteVertexArrays(1, &m_renderer_ID));
	}
	void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexLayout& layout)
	{
		buffer.Bind();
		Bind();
		GLuint nextIndex{ 0 };
		GLuint offset{ 0 };
		const auto& els = layout.GetElements();
		for (int i = 0; i < els.size(); i++) {
			GLCall(glEnableVertexAttribArray(nextIndex));
			GLCall(glVertexAttribPointer(nextIndex, els[i].count, els[i].type,
				els[i].normalized, layout.GetStride(), (const void*)offset));
			offset += els[i].count * els[i].type_size;
			nextIndex++;
		}
	}
}