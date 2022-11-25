#pragma once
#include <random>

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

	int randomGaussian(const double mean, const double deviation)
	{
		std::random_device rdev;
		std::mt19937 rgen(rdev());
		std::normal_distribution<double> d{mean, deviation};
		return std::round(d(rgen));
	}
}

