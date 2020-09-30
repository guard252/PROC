#include "pch.h"
#include "Texture.h"
#include <glew/glew.h>

namespace GFX
{
	Texture2D::Texture2D(TextureWrapMode wrap_s, TextureWrapMode wrap_t, TextureMinFilterMode min_filter, TextureMagFilterMode mag_filter)
	{
		GLCall(glCreateTextures(GL_TEXTURE_2D, 1, &m_renderer_ID));

		SetWrapSMode(wrap_s);
		SetWrapTMode(wrap_t);
		SetMinFilter(min_filter);
		SetMagFilter(mag_filter);
	}
	Texture2D::~Texture2D()
	{
		GLCall(glDeleteTextures(1, &m_renderer_ID));
	}
	void Texture2D::BindToSlot(GLuint slot)
	{
		glBindTextureUnit(slot, m_renderer_ID);
	}
	void Texture2D::SetWrapSMode(TextureWrapMode mode)
	{
		glTextureParameteri(m_renderer_ID, GL_TEXTURE_WRAP_S, ApiWrapMode(mode));
	}
	void Texture2D::SetWrapTMode(TextureWrapMode mode)
	{
		glTextureParameteri(m_renderer_ID, GL_TEXTURE_WRAP_T, ApiWrapMode(mode));
	}
	void Texture2D::SetMinFilter(TextureMinFilterMode mode)
	{
		GLCall(glTextureParameteri(m_renderer_ID, GL_TEXTURE_MIN_FILTER, ApiMinFilterMode(mode)));
	}
	void Texture2D::SetMagFilter(TextureMagFilterMode mode)
	{
		GLCall(glTextureParameteri(m_renderer_ID, GL_TEXTURE_MAG_FILTER, ApiMagFilterMode(mode)));
	}

	template <Fundamental T, size_t C>
	void Texture2D::SetImageData(Image<T, C> image, size_t mipmap_levels, PixelFormat format)
	{
		glTextureStorage2D(m_renderer_ID,
			mipmap_levels,
			ApiTextureInternalFormat(GetInternalFormat<T, C>()),
			image.GetWidth(),
			image.GetHeight());
		glTextureSubImage2D(m_renderer_ID,
			0,
			0,
			0,
			image.GetWidth(),
			image.GetHeight(),
			ApiPixelFormat(format),
			ApiType<T>(),
			static_cast<const void*>(image.GetRawData().get()));
	}
}