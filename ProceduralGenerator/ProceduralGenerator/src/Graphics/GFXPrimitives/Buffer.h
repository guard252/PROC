#pragma once
#include <vector>
#include "../Constants.h"
namespace GFX
{

	struct LayoutElement
	{
		ShaderDataType m_type;
		size_t m_size;
		size_t m_offset;

		explicit LayoutElement(ShaderDataType type, GLuint offset) : m_type{ type }, 
																	 m_size{ ShaderDataTypeElementCount(type) },
																	 m_offset{ offset } {}
	};

	class BufferLayout
	{
		std::vector<LayoutElement> m_elements;
		GLuint m_stride{ 0 };
	public:
		BufferLayout() = default;
		BufferLayout(std::initializer_list<ShaderDataType> elems)
		{
			m_elements.reserve(elems.size());
			for (const auto& el : elems)
			{
				m_elements.emplace_back(el, m_stride);
				m_stride += ShaderDataTypeSize(el);
			}
		}

		[[nodiscard]] constexpr const auto& GetElements() const { return m_elements; }
		[[nodiscard]] constexpr GLuint GetStride() const { return m_stride; }
	};

	class VertexBuffer
	{
	private:
		GLuint m_renderer_ID;
		BufferLayout m_layout;
		bool m_has_layout{ false };
	public:
		VertexBuffer(void* data, size_t size);
		~VertexBuffer();
		void SetLayout(const BufferLayout& layout)
		{
			m_layout = layout;
			m_has_layout = true;

		}
		void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_renderer_ID); }
		void UnBind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

		[[nodiscard]] constexpr const BufferLayout& GetLayout() const { return m_layout; }
		[[nodiscard]] constexpr GLuint GetID() const noexcept { return m_renderer_ID; }
		[[nodiscard]] constexpr bool HasLayout() const noexcept { return m_has_layout; }

	};

	class IndexBuffer
	{
	private:
		GLuint m_renderer_ID;
	public:
		IndexBuffer(GLuint* indices, GLuint count);
		~IndexBuffer();

		void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_ID); }
		void UnBind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }


		[[nodiscard]] constexpr GLuint GetID() const noexcept { return m_renderer_ID; }

	};

}

