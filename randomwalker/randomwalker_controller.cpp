#include "utilities.hpp"
#include "randomwalker_controller.hpp"

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

template<>
void RandomWalkerController::startWalking<Randomness::Random>()
{
	m_walker.setPosition(m_walker.getPosition() + getRandomDirection());
}

template<>
void RandomWalkerController::startWalking<Randomness::Custom>()
{
	m_walker.setPosition(m_walker.getPosition() + getCustomDirection(0.55, 0.5));
}

sf::Vector2f RandomWalkerController::getRandomDirection() const
{
	const int randX = utils::random<int>(1, 3);
	const int randY = utils::random<int>(1, 3);

	const float xPos = randX == 1 ?
		-m_velocity.x : (randX == 2 ? 0 : m_velocity.x);
	const float yPos = randY == 1 ?
		-m_velocity.y : (randY == 2 ? 0 : m_velocity.y);

	return sf::Vector2f(xPos, yPos);
}

sf::Vector2f RandomWalkerController::getCustomDirection(const float xRight, const float yDown) const
{
	const float randX = utils::random<float>(0, 1);
	const float randY = utils::random<float>(0, 1);

	const float xPos = randX < (1 - xRight) ?
		-m_velocity.x : (randX > (1 - xRight) ?
			m_velocity.y : 0);
	const float yPos = randY < (1 - yDown) ?
		-m_velocity.y : ( randY > (1 - yDown) ?
			m_velocity.y : 0);

	return sf::Vector2f(xPos, yPos);
}

