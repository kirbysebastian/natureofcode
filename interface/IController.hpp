#pragma once
#include <SFML/Graphics.hpp>

class IController
{
public:
	virtual void getEvent(const sf::Event&) = 0;
	virtual const sf::CircleShape& getDrawable() const = 0;
};

