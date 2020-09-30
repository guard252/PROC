#pragma once
namespace GFX
{
	class VertexBuffer
	{
	private:
		GLuint m_renderer_ID;
	public:
		VertexBuffer(float* data, GLuint size);
		~VertexBuffer();
		void Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_renderer_ID);
		}
		void UnBind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint GetID() { return m_renderer_ID; }

	};
}

