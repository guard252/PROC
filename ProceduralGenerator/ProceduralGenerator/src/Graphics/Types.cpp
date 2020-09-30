#include "Types.h"
#include <glew/glew.h>
template<>
unsigned int ApiType<int>()
{
	return GL_INT;
}

template<>
unsigned int ApiType<unsigned int>()
{
	return GL_UNSIGNED_INT;
}

template<>
unsigned int ApiType<short>()
{
	return GL_SHORT;
}

template<>
unsigned int ApiType<unsigned short>()
{
	return GL_UNSIGNED_SHORT;
}

template<>
unsigned int ApiType<signed char>()
{
	return GL_BYTE;
}

template<>
unsigned int ApiType<unsigned char>()
{
	return GL_UNSIGNED_BYTE;
}

template<>
unsigned int ApiType<float>()
{
	return GL_FLOAT;
}

template<>
unsigned int ApiType<double>()
{
	return GL_DOUBLE;
}

