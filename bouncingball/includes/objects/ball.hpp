#ifndef BOUNCINGBALL_OBJECTS_BALL_HPP
#define BOUNCINGBALL_OBJECTS_BALL_HPP

#include <SFML/Graphics/CircleShape.hpp>

namespace objects
{

class Ball
{
public:
	Ball(
		const float radius,
		const sf::Color& color,
		const sf::Vector2f& initialCenterPosition
	);

	//void move(const sf::Vector2f&);
	void setPosition(const sf::Vector2f&);
	void setVelocity(const sf::Vector2f&);
	void setAcceleration(const sf::Vector2f&);

	float getRadius() const;
	float getDiameter() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getAcceleration() const;
	sf::CircleShape getDrawable() const;

private:
	float m_radius;
	float m_diameter;
	sf::CircleShape m_shape;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
};

} // namespace objects
#endif // BOUNCINGBALL_OBJECTS_BALL_HPP

