#pragma once
#include <memory>
#include <type_traits>
#include <glm/glm.hpp>

template<typename T>
concept Fundamental = std::is_fundamental_v<T>;

template<Fundamental T, size_t channel_size>
glm::vec<channel_size, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos);

template<Fundamental T, size_t channel_size>
class Image
{
	glm::uvec2 m_size{ 0, 0 };
	std::unique_ptr<T[]> m_raw_data{ nullptr };



public:
	
	Image(size_t width, size_t height, bool create_black = false) : m_size{ width, height }
	{
		m_raw_data = std::make_unique<T[]>(width * height);
		if (create_black)
		{
			std::fill(std::begin(m_raw_data), std::end(m_raw_data), 0);
		}
	}

	Image(glm::uvec2 size, bool create_black = false) : m_size{ size }
	{
		m_raw_data = std::make_unique<T[]>(size.x * size.y);
		if (create_black)
		{
			std::fill(std::begin(m_raw_data), std::end(m_raw_data), 0);
		}
	}

	Image(size_t width, size_t height, std::unique_ptr<T[]>&& data) : m_size{ width, height }
	{
		m_raw_data = data;
	}

	Image(glm::uvec2 size, std::unique_ptr<T[]>&& data) : m_size{ size }
	{
		m_raw_data = data;
	}

	Image(const Image& other) : m_size{ other.m_size }
	{
		m_raw_data = std::make_unique<T[]>(m_size.x * m_size.y);
		std::copy(std::begin(other.m_raw_data), std::end(other.m_raw_data), m_raw_data);
	}

	Image(Image&& other) : m_size{ other.m_size }, m_raw_data{ std::move(other.m_raw_data) } {	}

	glm::vec<channel_size, T, glm::defaultp> At(glm::uvec2 pos) const
	{
		return GetPixel(m_raw_data, m_size, pos);
	}
	
};



template<Fundamental T>
glm::vec<1, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	glm::vec<1, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x + pos.x;
	return res;
}

template<Fundamental T>
glm::vec<2, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	glm::vec<2, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x * 2 + pos.x * 2;
	res.g = data.get() + pos.y * size.x * 2 + pos.x  * 2 + 1;
	return res;
}

template<Fundamental T>
glm::vec<3, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	glm::vec<3, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x * 3 + pos.x * 3;
	res.g = data.get() + pos.y * size.x * 3 + pos.x * 3 + 1;
	res.b = data.get() + pos.y * size.x * 3 + pos.x * 3 + 2;
	return res;
}

template<Fundamental T>
glm::vec<4, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	glm::vec<4, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x * 4 + pos.x * 4;
	res.g = data.get() + pos.y * size.x * 4 + pos.x * 4 + 1;
	res.b = data.get() + pos.y * size.x * 4 + pos.x * 4 + 2;
	res.a = data.get() + pos.y * size.x * 4 + pos.x * 4 + 3;
	return res;
}