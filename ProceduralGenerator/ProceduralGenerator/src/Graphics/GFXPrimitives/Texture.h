#pragma once
//#include <glew/glew.h>
#include "../Constants.h"
#include "Graphics/Image.h"
#include "../Types.h"
namespace GFX
{
	class Texture2D
	{
		GLuint m_renderer_ID;
		size_t width{ 0 };
		size_t height{ 0 };
	public:
		Texture2D(TextureWrapMode wrap_s = TextureWrapMode::CLAMP_TO_EDGE,
				  TextureWrapMode wrap_t = TextureWrapMode::CLAMP_TO_EDGE,
				  TextureMinFilterMode min_filter = TextureMinFilterMode::LINEAR,
				  TextureMagFilterMode mag_filter = TextureMagFilterMode::LINEAR);
		~Texture2D();

		void BindToSlot(GLuint slot = 0);

		void SetWrapSMode(TextureWrapMode mode);
		void SetWrapTMode(TextureWrapMode mode);
		void SetMinFilter(TextureMinFilterMode mode);
		void SetMagFilter(TextureMagFilterMode mode);

		template <Fundamental T, size_t C>
		void SetImageData(Image<T, C> image, size_t mipmap_levels = 1, PixelFormat format = PixelFormat::RGBA);

		GLuint GetID() { return m_renderer_ID; }
	};

	

	template void Texture2D::SetImageData<unsigned char, 1>(Image<unsigned char, 1>, size_t, PixelFormat);
	template void Texture2D::SetImageData<unsigned char, 2>(Image<unsigned char, 2>, size_t, PixelFormat);
	template void Texture2D::SetImageData<unsigned char, 3>(Image<unsigned char, 3>, size_t, PixelFormat);
	template void Texture2D::SetImageData<unsigned char, 4>(Image<unsigned char, 4>, size_t, PixelFormat);

	template void Texture2D::SetImageData<unsigned short, 1>(Image<unsigned short, 1>, size_t, PixelFormat);
	template void Texture2D::SetImageData<unsigned short, 2>(Image<unsigned short, 2>, size_t, PixelFormat);
	template void Texture2D::SetImageData<unsigned short, 3>(Image<unsigned short, 3>, size_t, PixelFormat);
	template void Texture2D::SetImageData<unsigned short, 4>(Image<unsigned short, 4>, size_t, PixelFormat);

	template void Texture2D::SetImageData<float, 1>(Image<float, 1>, size_t, PixelFormat);
	template void Texture2D::SetImageData<float, 2>(Image<float, 2>, size_t, PixelFormat);
	template void Texture2D::SetImageData<float, 3>(Image<float, 3>, size_t, PixelFormat);
	template void Texture2D::SetImageData<float, 4>(Image<float, 4>, size_t, PixelFormat);


}
