#include "Constants.h"

namespace GFX
{
	unsigned ApiWrapMode(TextureWrapMode mode)
	{
		switch (mode)
		{
			case TextureWrapMode::CLAMP_TO_EDGE:
				return GL_CLAMP_TO_EDGE;
			case TextureWrapMode::CLAMP_TO_BORDER:
				return GL_CLAMP_TO_BORDER;
			case TextureWrapMode::REPEAT:
				return GL_REPEAT;
			case TextureWrapMode::MIRRORED_REPEAT:
				return GL_MIRRORED_REPEAT;
		}
	}
	unsigned ApiMinFilterMode(TextureMinFilterMode mode)
	{
		switch(mode)
		{
			case TextureMinFilterMode::LINEAR:
				return GL_LINEAR;
			case TextureMinFilterMode::NEAREST:
				return GL_NEAREST;
			case TextureMinFilterMode::LINEAR_MIPMAP_LINEAR:
				return GL_LINEAR_MIPMAP_LINEAR;
			case TextureMinFilterMode::LINEAR_MIPMAP_NEAREST:
				return GL_LINEAR_MIPMAP_NEAREST;
			case TextureMinFilterMode::NEAREST_MIPMAP_LINEAR:
				return GL_NEAREST_MIPMAP_LINEAR;
			case TextureMinFilterMode::NEAREST_MIPMAP_NEAREST:
				return GL_NEAREST_MIPMAP_NEAREST;
		}
	}
	unsigned ApiMagFilterMode(TextureMagFilterMode mode)
	{
		switch (mode)
		{
			case TextureMagFilterMode::LINEAR:
				return GL_LINEAR;
			case TextureMagFilterMode::NEAREST:
				return GL_NEAREST;
		}
	}
	unsigned ApiTextureInternalFormat(TextureInternalFormat format)
	{
		switch (format)
		{
			case TextureInternalFormat::R8:
				return GL_R8;
			case TextureInternalFormat::RG8:
				return GL_RG8;
			case TextureInternalFormat::RGB8:
				return GL_RGB8;
			case TextureInternalFormat::RGBA8:
				return GL_RGBA8;
			case TextureInternalFormat::R16:
				return GL_R16;
			case TextureInternalFormat::RG16:
				return GL_RG16;
			case TextureInternalFormat::RGB16:
				return GL_RGB16;
			case TextureInternalFormat::RGBA16:
				return GL_RGBA16;
			case TextureInternalFormat::R16F:
				return GL_R16F;
			case TextureInternalFormat::RG16F:
				return GL_RG16F;
			case TextureInternalFormat::RGB16F:
				return GL_RGB16F;
			case TextureInternalFormat::RGBA16F:
				return GL_RGBA16F;
		}
	}
	unsigned ApiPixelFormat(PixelFormat format)
	{
		switch (format)
		{
			case PixelFormat::R:
				return GL_RED;
			case PixelFormat::RG:
				return GL_RG;
			case PixelFormat::RGB:
				return GL_RGB;
			case PixelFormat::BGR:
				return GL_BGR;
			case PixelFormat::RGBA:
				return GL_RGBA;
			case PixelFormat::BGRA:
				return GL_BGRA;
			case PixelFormat::DEPTH_CONPONENT:
				return GL_DEPTH_COMPONENT;
			case PixelFormat::STENCIL_INDEX:
				return GL_STENCIL_INDEX;
		}
	}

	
}