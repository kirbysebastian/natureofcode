#pragma once
#include <random>
#include <cmath>

#include <SFML/System/Vector2.hpp>

namespace common::utils
{
	template<typename T>
	T random(const T min, const T max)
	{
		std::random_device rdev;
		std::mt19937 rgen(rdev());
		typedef typename std::conditional<
			std::is_floating_point<T>::value,
			std::uniform_real_distribution<T>,
			std::uniform_int_distribution<T>>::type RandomType;
		RandomType dist(min, max);
		return dist(rgen);
	}

	int randomGaussian(
		const double min,
		const double max,
		const double deviation)
	{
		std::random_device rdev;
		std::mt19937 rgen(rdev());
		std::normal_distribution<double> d{((min+max-1)/2), deviation};
		const auto res{std::round(d(rgen))};

		if (res < min || res > max)
			return 0;
		return res;
	}

	template<typename T>
	T magnitude(const T x, const T y)
	{
		return std::sqrt((x * x) + (y * y));
	}

	template <typename T>
	sf::Vector2<T> magnitude(const sf::Vector2<T>& vector)
	{
		return std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
	}
	
	template <typename T>
	sf::Vector2<T> normalize(const sf::Vector2<T>& vector)
	{
		const T vecMag = magnitude<T>(vector);
		if (0 == vecMag)
		{
			return vector;
		}

		return vector / vecMag;
	}

} // namespace common::utils

