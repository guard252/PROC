#pragma once
#include <memory>

#include "Buffer.h"
namespace GFX
{
	class VertexArray
	{
		GLuint m_renderer_ID;
		GLuint m_last_index{ 0 };
	public:
		VertexArray();
		~VertexArray();
		virtual void Bind() const { glBindVertexArray(m_renderer_ID); }
		virtual void UnBind() const { glBindVertexArray(0); }

		void AddBuffer(const std::shared_ptr<VertexBuffer>& buffer)
		{
			assert(buffer->HasLayout());
			Bind();
			buffer->Bind();
			const BufferLayout& layout = buffer->GetLayout();
			const std::vector<LayoutElement>& elements = layout.GetElements();
			for (const LayoutElement& element : elements)
			{
				glEnableVertexAttribArray(m_last_index);
				glVertexAttribPointer(m_last_index, 
					element.m_size, 
					ApiShaderDataType(element.m_type),
					GL_FALSE,
					layout.GetStride(),
					(const void*)element.m_offset);
					m_last_index++;
			}
		}

		[[nodiscard]] constexpr GLuint GetID() const { return m_renderer_ID; }
	};

}
