#ifndef BOUNCINGBALL_ENGINE_HPP
#define BOUNCINGBALL_ENGINE_HPP

#include "objects/ball.hpp"

#define GRAVITY_ACCELERATION 0.0001f
//#define FRICTION 0.898f
#define FRICTION 0.98f

namespace engine
{
class Engine
{
public:
	Engine(const float xBound, const float yBound);
	void move(objects::Ball&);
	void applyGravity(objects::Ball&);
	void applyCollision(objects::Ball&);

private:
	bool isOutOfBounds(const objects::Ball&);
	bool isTouchingFloor(const objects::Ball&);

	float m_xBound{0.0f};
	float m_yBound{0.0f};
	sf::Vector2f m_gravity{0, GRAVITY_ACCELERATION};
};
} // namespace engine

#endif // BOUNCINGBALL_ENGINE_HPP

