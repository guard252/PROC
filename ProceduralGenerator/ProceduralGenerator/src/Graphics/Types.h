#pragma once
#include <type_traits>



template<typename T>
concept Fundamental = std::is_fundamental_v<T>;

template<Fundamental T>
constexpr int ApiType()
{
	static_assert(false, "The function has no implementation for this type");
}

template<Fundamental T>
constexpr int api_type = ApiType<T>();
