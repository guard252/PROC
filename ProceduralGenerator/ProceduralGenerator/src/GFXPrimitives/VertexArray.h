#pragma once
#include "VertexBuffer.h"
#include "VertexLayout.h"
namespace GFX
{
	class VertexArray : public IBindable
	{
		GLuint m_renderer_ID;
	public:
		VertexArray();
		~VertexArray();
		virtual void Bind() const override { GLCall(glBindVertexArray(m_renderer_ID)); }
		virtual void UnBind() const override { GLCall(glBindVertexArray(0)); }
		void AddBuffer(const VertexBuffer& buffer, const VertexLayout& layout);
	};
}
