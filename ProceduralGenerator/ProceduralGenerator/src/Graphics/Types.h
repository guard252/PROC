#pragma once
#include <type_traits>
#include "Concepts.h"



template<Fundamental T>
unsigned int ApiType()
{
	static_assert(false, "The function has no implementation for this type");
}

template<> unsigned int ApiType<int>();
template<> unsigned int ApiType<unsigned int>();
template<> unsigned int ApiType<short>();
template<> unsigned int ApiType<unsigned short>();
template<> unsigned int ApiType<signed char>();
template<> unsigned int ApiType<unsigned char>();
template<> unsigned int ApiType<float>();
template<> unsigned int ApiType<double>();

//template<Fundamental T>
//constexpr int api_type = ApiType<T>();






