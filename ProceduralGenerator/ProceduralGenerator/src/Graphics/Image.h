#pragma once
#include <memory>
#include <glm/glm.hpp>

#include "Concepts.h"

template<Fundamental T, size_t channel_count>
[[nodiscard]] constexpr glm::vec<channel_count, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos) noexcept;

template<Fundamental T, size_t channel_count>
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
			std::fill(m_raw_data.get(), m_raw_data.get() + size.x * size.y * channel_count, 0);
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
		std::copy(other.m_raw_data.get(), other.m_raw_data.get() + m_size.x * m_size.y * channel_count, m_raw_data.get());
	}

	Image(Image&& other) : m_size{ other.m_size }, m_raw_data{ std::move(other.m_raw_data) } {	}

	[[nodiscard]] constexpr glm::vec<channel_count, T, glm::defaultp> At(glm::uvec2 pos) const noexcept
	{
		return GetPixel(m_raw_data, m_size, pos);
	}

	[[nodiscard]] constexpr glm::vec<channel_count, T, glm::defaultp> At(size_t x, size_t y) const noexcept
	{
		return GetPixel(m_raw_data, m_size, { x, y });
	}

	[[nodiscard]] constexpr glm::uvec2 GetSize() const noexcept 
	{
		return m_size;
	}
	
	[[nodiscard]] constexpr size_t GetWidth() const noexcept
	{
		return m_size.x;
	}

	[[nodiscard]] constexpr size_t GetHeight() const noexcept
	{
		return m_size.y;
	}

	[[nodiscard]] constexpr const std::unique_ptr<T[]>& GetRawData() const noexcept
	{
		return m_raw_data;
	}

};



template<Fundamental T>
constexpr glm::vec<1, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	assert(pos.x < size.x&& pos.y < size.y);
	glm::vec<1, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x + pos.x;
	return res;
}

template<Fundamental T>
constexpr glm::vec<2, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	assert(pos.x < size.x&& pos.y < size.y);
	glm::vec<2, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x * 2 + pos.x * 2;
	res.g = data.get() + pos.y * size.x * 2 + pos.x  * 2 + 1;
	return res;
}

template<Fundamental T>
constexpr glm::vec<3, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	assert(pos.x < size.x&& pos.y < size.y);
	glm::vec<3, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x * 3 + pos.x * 3;
	res.g = data.get() + pos.y * size.x * 3 + pos.x * 3 + 1;
	res.b = data.get() + pos.y * size.x * 3 + pos.x * 3 + 2;
	return res;
}

template<Fundamental T>
constexpr glm::vec<4, T, glm::defaultp> GetPixel(const std::unique_ptr<T[]> data, glm::uvec2 size, glm::uvec2 pos)
{
	assert(pos.x < size.x&& pos.y < size.y);
	glm::vec<4, T, glm::defaultp> res;
	res.r = data.get() + pos.y * size.x * 4 + pos.x * 4;
	res.g = data.get() + pos.y * size.x * 4 + pos.x * 4 + 1;
	res.b = data.get() + pos.y * size.x * 4 + pos.x * 4 + 2;
	res.a = data.get() + pos.y * size.x * 4 + pos.x * 4 + 3;
	return res;
}