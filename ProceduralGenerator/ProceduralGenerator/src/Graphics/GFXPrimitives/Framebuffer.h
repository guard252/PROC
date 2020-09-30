#pragma once

namespace GFX
{
	class Framebuffer
	{
		GLuint m_renderer_ID;	
	public:
		Framebuffer();
		~Framebuffer();
		
		GLuint GetID() { return m_renderer_ID; }

	};
}

