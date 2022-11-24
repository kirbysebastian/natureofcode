#pragma once

#include "IController.hpp"

class RandomWalkerController final : public IController
{
public:
	RandomWalkerController();
	~RandomWalkerController();

	void getEvent(const sf::Event&) override;
	const sf::CircleShape& getDrawable() const override;

	void startWalking();

private:
	sf::CircleShape m_walker{1.f};
};
