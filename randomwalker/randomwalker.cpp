#include <iostream>
#include <SFML/Graphics.hpp>

#include "randomwalker_controller.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main()
{
	std::cout << "randomwalker!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Nature of Code: RandomWalker");
	window.setVerticalSyncEnabled(true);

	RandomWalkerController walkerCtrlr;
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed ||
					(ev.type == sf::Event::KeyPressed &&
						ev.key.code == sf::Keyboard::Key::Escape))
				window.close();
			//walkerCtrlr.getEvent(ev);
			walkerCtrlr.startWalking();
		}
		//window.clear();
		window.draw(walkerCtrlr.getDrawable());
		window.display();
	}

	return EXIT_SUCCESS;
}
