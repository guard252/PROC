#pragma once
#include <type_traits>

template<typename T>
concept Fundamental = std::is_fundamental_v<T>;