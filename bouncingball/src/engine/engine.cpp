#include <iostream>
#include "engine/engine.hpp"

namespace engine
{

Engine::Engine(const float xBound, const float yBound) :
	m_xBound(xBound),
	m_yBound(yBound)
{}

void Engine::move(objects::Ball& ball)
{
	ball.setVelocity(ball.getVelocity() + ball.getAcceleration());
	ball.setPosition(ball.getPosition() + ball.getVelocity());
}

void Engine::applyGravity(objects::Ball& ball)
{
	ball.setAcceleration(ball.getAcceleration() + m_gravity);
}

void Engine::applyCollision(objects::Ball& ball)
{
	if (isTouchingFloor(ball))
	{
		std::cout << "OUT OF BOUNDS!" << std::endl;
		ball.setVelocity(ball.getVelocity() * -1.f);
		ball.setAcceleration(ball.getAcceleration() + m_gravity);
		//ball.setAcceleration(ball.getAcceleration() * -1.f);
		/*
		ball.setVelocity(sf::Vector2f{0.f, 0.f});
		ball.setAcceleration(sf::Vector2f{0.f, 0.f});
		*/
	}
}

bool Engine::isOutOfBounds(const objects::Ball& ball)
{
	const auto width = ball.getDiameter();
	const auto height = ball.getDiameter();
	const auto& pos{ball.getPosition()};
	if ((pos.x < 0 || ((pos.x + width) >= m_xBound)) ||
		(pos.y < 0 || ((pos.y + height) >= m_yBound)))
	{
		return true;
	}

	return false;
}

bool Engine::isTouchingFloor(const objects::Ball& ball)
{
	const auto height = ball.getDiameter();
	const auto& pos{ball.getPosition()};
	if (pos.y < 0 || ((pos.y + height) >= m_yBound))
	{
		return true;
	}

	return false;
}

} // namespace engine

