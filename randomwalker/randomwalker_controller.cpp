#include <iostream>
#include <random>
#include "randomwalker_controller.hpp"

namespace helper
{
	int random(const int min, const int max)
	{
		std::random_device rdev;
		std::mt19937 rgen(rdev());
		std::uniform_int_distribution<int> dist(min, max);
		return dist(rgen);
	}

	sf::Vector2f getRandomDirection()
	{
		const int randX = random(1, 3);
		const int randY = random(1, 3);

		const float xPos = randX == 1 ?
			-0.5 : (randX == 2 ? 0 : 0.5);
		const float yPos = randY == 1 ?
			-0.5 : (randY == 2 ? 0 : 0.5);

		return sf::Vector2f(xPos, yPos);
	}
}

RandomWalkerController::RandomWalkerController()
{
	m_walker.setFillColor(sf::Color::Red);
	m_walker.setPosition(sf::Vector2f(800, 400));
}

RandomWalkerController::~RandomWalkerController() {}

void RandomWalkerController::getEvent(const sf::Event& ev)
{

}

const sf::CircleShape& RandomWalkerController::getDrawable() const
{
	return m_walker;
}

void RandomWalkerController::startWalking()
{
	m_walker.setPosition(m_walker.getPosition() + helper::getRandomDirection());
}
