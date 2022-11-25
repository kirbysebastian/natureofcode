#pragma once

#include "IController.hpp"

enum class Randomness : std::uint8_t
{
	Random = 0,
	Custom,
	Gaussian
};

class RandomWalkerController final : public IController
{
public:
	RandomWalkerController();
	~RandomWalkerController();

	void getEvent(const sf::Event&) override;
	const sf::CircleShape& getDrawable() const override;

	template<Randomness T>
	void startWalking();

private:
	sf::Vector2f getRandomDirection() const;
	sf::Vector2f getCustomDirection(const float, const float) const;

	sf::CircleShape m_walker{1.f};
	sf::Vector2f m_velocity{0.5, 0.5};
};
