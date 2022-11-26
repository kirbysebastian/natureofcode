#include <iostream>
#include "SFML/Graphics.hpp"

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300

int main()
{
	std::cout << "Velocity!" << std::endl;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Velocity!");


	// Object
	sf::CircleShape obj{10.f};
	obj.setFillColor(sf::Color::White);
	obj.setPosition({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});

	const float displacement{0.0125f};
	// Velocity
	sf::Vector2f velocity{displacement, 0};
	
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed ||
				(ev.type == sf::Event::KeyPressed &&
					(ev.key.code == sf::Keyboard::Key::Escape)))
				window.close();
			if (ev.type == sf::Event::KeyPressed)
			{
				if (ev.key.code == sf::Keyboard::Key::Up)
					velocity = sf::Vector2f{0, -displacement};
				if (ev.key.code == sf::Keyboard::Key::Down)
					velocity = sf::Vector2f{0, displacement};
				if (ev.key.code == sf::Keyboard::Key::Left)
					velocity = sf::Vector2f{-displacement, 0};
				if (ev.key.code == sf::Keyboard::Key::Right)
					velocity = sf::Vector2f{displacement, 0};
			}
		}

		// Apply velocity to object
		obj.setPosition(obj.getPosition() + velocity);

		// Reset Object position if out of bounds
		const auto& objPos{obj.getPosition()};
		if (objPos.x <= 0)
			obj.setPosition({SCREEN_WIDTH, objPos.y});
		else if (objPos.x >= SCREEN_WIDTH)
			obj.setPosition({0, objPos.y});
		else if (objPos.y <= 0)
			obj.setPosition({objPos.x, SCREEN_HEIGHT});
		else if (objPos.y >= SCREEN_HEIGHT)
			obj.setPosition({objPos.x, 0});

		const auto& mousePos{sf::Mouse::getPosition(window)};

		sf::Vertex line[] = {
			sf::Vertex{sf::Vector2f{(float)mousePos.x, (float)mousePos.y}, sf::Color::Green},
			sf::Vertex{
				sf::Vector2f{
					obj.getPosition().x+obj.getRadius(),
					obj.getPosition().y+obj.getRadius()},
				sf::Color::Red}
		};
		
		window.clear();
		window.draw(obj);
		window.draw(line, 2, sf::Lines);
		window.display();
	}

	return EXIT_SUCCESS;
}
