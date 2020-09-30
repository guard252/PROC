#pragma once
#include "VertexBuffer.h"
#include "VertexLayout.h"
namespace GFX
{
	class VertexArray
	{
		GLuint m_renderer_ID;
	public:
		VertexArray();
		~VertexArray();
		virtual void Bind() const { glBindVertexArray(m_renderer_ID); }
		virtual void UnBind() const { glBindVertexArray(0); }
		void AddBuffer(const VertexBuffer& buffer, const VertexLayout& layout);

		GLuint GetID() { return m_renderer_ID; }
	};
}
