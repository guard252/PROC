#pragma once
#include <glew/glew.h>

namespace GFX
{
	enum struct TextureWrapMode
	{
		REPEAT,
		MIRRORED_REPEAT,
		CLAMP_TO_EDGE,
		CLAMP_TO_BORDER
	};
	
	enum struct TextureMinFilterMode
	{
		NEAREST,
		LINEAR,
		NEAREST_MIPMAP_NEAREST,
		NEAREST_MIPMAP_LINEAR,
		LINEAR_MIPMAP_NEAREST,
		LINEAR_MIPMAP_LINEAR
	};

	enum struct TextureMagFilterMode
	{
		NEAREST,
		LINEAR,
	};

	enum struct PixelFormat
	{
		R,
		RG,
		RGB,
		BGR,
		RGBA,
		BGRA,
		DEPTH_CONPONENT,
		STENCIL_INDEX,
	};

	enum struct TextureInternalFormat
	{
		R8,
		RG8,
		RGB8,
		RGBA8,
		R16,
		RG16,
		RGB16,
		RGBA16,
		R16F,
		RG16F,
		RGB16F,
		RGBA16F,
	};

	constexpr unsigned ApiWrapMode(TextureWrapMode mode);
	constexpr unsigned ApiMinFilterMode(TextureMinFilterMode mode);
	constexpr unsigned ApiMagFilterMode(TextureMagFilterMode mode);
	constexpr unsigned ApiTextureInternalFormat(TextureInternalFormat format);
	constexpr unsigned ApiPixelFormat(PixelFormat format);
}