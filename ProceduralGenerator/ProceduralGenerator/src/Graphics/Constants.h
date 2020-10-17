#pragma once
#include <glew/glew.h>
#include "Concepts.h"
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

	enum struct ShaderDataType
	{
		Bool,
		Int,
		Int2,
		Int3,
		Int4,
		Float,
		Float2,
		Float3,
		Float4,
		Mat2,
		Mat3,
		Mat4,
	};

	GLuint ApiWrapMode(TextureWrapMode mode);
	GLuint ApiMinFilterMode(TextureMinFilterMode mode);
	GLuint ApiMagFilterMode(TextureMagFilterMode mode);
	GLuint ApiTextureInternalFormat(TextureInternalFormat format);
	GLuint ApiPixelFormat(PixelFormat format);
	GLuint ShaderDataTypeSize(ShaderDataType type);
	GLuint ShaderDataTypeElementCount(ShaderDataType type);
	GLuint ApiShaderDataType(ShaderDataType type);
	template <Fundamental F, size_t C>
	TextureInternalFormat GetInternalFormat() { static_assert(false); }

	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned char, 1>()
	{
		return TextureInternalFormat::R8;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned char, 2>()
	{
		return TextureInternalFormat::RG8;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned char, 3>()
	{
		return TextureInternalFormat::RGB8;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned char, 4>()
	{
		return TextureInternalFormat::RGBA8;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned short, 1>()
	{
		return TextureInternalFormat::R16;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned short, 2>()
	{
		return TextureInternalFormat::RG16;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned short, 3>()
	{
		return TextureInternalFormat::RGB16;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<unsigned short, 4>()
	{
		return TextureInternalFormat::RGBA16;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<float, 1>()
	{
		return TextureInternalFormat::R16F;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<float, 2>()
	{
		return TextureInternalFormat::RG16F;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<float, 3>()
	{
		return TextureInternalFormat::RGB16F;
	}
	template <>
	inline TextureInternalFormat GetInternalFormat<float, 4>()
	{
		return TextureInternalFormat::RGBA16F;
	}
}

