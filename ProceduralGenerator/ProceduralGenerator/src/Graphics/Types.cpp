#include "Types.h"
#include <glew/glew.h>

template<>
constexpr int ApiType<GLuint>()
{
	return GL_UNSIGNED_INT;
}

template<>
constexpr int ApiType<GLint>()
{
	return GL_INT;
}

template<>
constexpr int ApiType<GLshort>()
{
	return GL_SHORT;
}

template<>
constexpr int ApiType<GLushort>()
{
	return GL_UNSIGNED_SHORT;
}

template<>
constexpr int ApiType<GLbyte>()
{
	return GL_BYTE;
}

template<>
constexpr int ApiType<GLubyte>()
{
	return GL_UNSIGNED_BYTE;
}

template<>
constexpr int ApiType<GLfloat>()
{
	return GL_FLOAT;
}

template<>
constexpr int ApiType<GLdouble>()
{
	return GL_DOUBLE;
}

