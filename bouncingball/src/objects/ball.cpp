#include "objects/ball.hpp"

namespace objects
{
Ball::Ball(const float radius,
		const sf::Color& color,
		const sf::Vector2f& initialCenterPosition) :
	m_shape(radius),
	m_radius(radius),
	m_diameter(radius * 2)
{
	m_shape.setFillColor(color);
	m_shape.setPosition(initialCenterPosition - sf::Vector2f{m_radius, m_radius});
}

/*
void Ball::move(const sf::Vector2f& movementVec)
{
	m_shape.setPosition(m_shape.getPosition() + movementVec);
}
*/

void Ball::setPosition(const sf::Vector2f& positionVec)
{
	m_shape.setPosition(positionVec);
}

void Ball::setVelocity(const sf::Vector2f& velocityVec)
{
	m_velocity = velocityVec;
}

void Ball::setAcceleration(const sf::Vector2f& accelerationVec)
{
	m_acceleration = accelerationVec;
}

float Ball::getRadius() const
{
	return m_radius;
}

float Ball::getDiameter() const
{
	return m_diameter;
}

sf::Vector2f Ball::getPosition() const
{
	return m_shape.getPosition();
}

sf::Vector2f Ball::getVelocity() const
{
	return m_velocity;
}

sf::Vector2f Ball::getAcceleration() const
{
	return m_acceleration;
}

sf::CircleShape Ball::getDrawable() const
{
	return m_shape;
}

} // namespace objects

