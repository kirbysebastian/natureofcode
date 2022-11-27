
#include <iostream>
#include "SFML/Graphics.hpp"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

template<typename T>
T createObject(float size, float xPos, float yPos)
{
	T shape{sf::Vector2f{size, size}};
	shape.setPosition({xPos-(size/2), yPos-(size/2)});
	return shape;
}

template<>
sf::CircleShape createObject<sf::CircleShape>(float size, float xPos, float yPos)
{
	float radius{size/2};
	sf::CircleShape shape{radius};
	shape.setPosition({xPos-radius, yPos-radius});
	return shape;
}

template<typename T>
void drawObjects(sf::RenderWindow& window, const std::vector<T>& objects)
{
	for (const auto& obj : objects)
	{
		window.draw(obj);
	}
}

int main()
{
	std::cout << "ObjectOnClick!" << std::endl;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ObjectOnClick!");

	std::vector<sf::CircleShape> objects;
	bool isMouseLeftButtonPressed{false};
	float size{10};
	sf::CircleShape mouseObj{size/2};
	mouseObj.setFillColor(sf::Color::White);
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed ||
				(ev.type == sf::Event::KeyPressed &&
					(ev.key.code == sf::Keyboard::Key::Escape)))
				window.close();
			if (ev.type == sf::Event::MouseButtonReleased && ev.mouseButton.button == sf::Mouse::Button::Left)
				isMouseLeftButtonPressed = false;
			if (ev.type == sf::Event::MouseButtonPressed)
			{
				if (ev.mouseButton.button == sf::Mouse::Button::Right)
				{
					objects.clear();
				}
				else if (ev.mouseButton.button == sf::Mouse::Button::Left)
				{
					isMouseLeftButtonPressed = true;
				}
			}
			if (ev.type == sf::Event::MouseWheelScrolled)
			{
				std::cout << "MouseWheelScroll Delta :3 " << ev.mouseWheelScroll.delta << std::endl;
				size += 1.f * ev.mouseWheelScroll.delta;
			}
		}

		window.clear();
		const auto& mousePos{sf::Mouse::getPosition(window)};
		if (isMouseLeftButtonPressed)
		{
			objects.emplace_back(createObject<sf::CircleShape>(size, (float)mousePos.x, (float)mousePos.y));
			//std::cout << "Objects created: " << objects.size() << std::endl;
		}
		// Draw Mouse Object
		mouseObj.setPosition(sf::Vector2f{mousePos.x - (size/2), mousePos.y - (size/2)});
		mouseObj.setRadius(size/2);
		window.draw(mouseObj);

		drawObjects(window, objects);
		window.display();
	}

	return EXIT_SUCCESS;
}
