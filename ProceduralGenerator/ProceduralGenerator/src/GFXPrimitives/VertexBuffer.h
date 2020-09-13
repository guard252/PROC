#pragma once
namespace GFX
{
	class PROC_API VertexBuffer : public IBindable
	{
	private:
		GLuint m_renderer_ID;
	public:
		VertexBuffer(float* data, GLuint size);
		~VertexBuffer();
		void Bind() const override
		{
			GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderer_ID));
		}
		void UnBind() const override
		{
			GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		}

	};
}

