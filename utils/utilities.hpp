#pragma once
#include <random>
#include <cmath>

namespace utils
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
}

