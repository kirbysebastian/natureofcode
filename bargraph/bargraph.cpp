#include <iostream>
#include <SFML/Graphics.hpp>

#include "bargraph_controller.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main()
{
	std::cout << "bargraph!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Nature of Code: BarGraph");
	window.setVerticalSyncEnabled(true);

	BarGraphController barGraphCtrlr{100, WIDTH, HEIGHT};
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed ||
					(ev.type == sf::Event::KeyPressed &&
						ev.key.code == sf::Keyboard::Key::Escape))
				window.close();
		}
		barGraphCtrlr.increaseHeight(window);
		barGraphCtrlr.draw(window);
		window.display();
	}

	return EXIT_SUCCESS;
}
