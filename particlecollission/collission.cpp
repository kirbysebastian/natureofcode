#include <iostream>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define PROJECT "Particle Collission"

int main()
{
	std::cout << PROJECT << "!" << std::endl;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), PROJECT);

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed ||
				(ev.type ==sf::Event::KeyPressed &&
				 (ev.key.code == sf::Keyboard::Key::Escape)))
			{
				window.close();
			}
		}
	}

	return EXIT_SUCCESS;
}

