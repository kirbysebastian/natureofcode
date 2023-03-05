#include <iostream>
#include <SFML/Graphics.hpp>

#include "manager/eventmanager.hpp"
#include "engine/engine.hpp"
#include "objects/ball.hpp"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define PROJECT_NAME "Bouncing Ball"

int main()
{
	std::cout << PROJECT_NAME << std::endl;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), PROJECT_NAME);
	manager::EventManager evManager;
	engine::Engine engine{SCREEN_WIDTH, SCREEN_HEIGHT};

	const float ballRadius{30.f};
	objects::Ball ball{
		ballRadius,
		sf::Color::Red,
		sf::Vector2f{SCREEN_WIDTH/2, SCREEN_HEIGHT/2}
		//sf::Vector2f{SCREEN_WIDTH/2 - 2.f, SCREEN_HEIGHT/2 - 2.f}
	};
	//ball.setVelocity(sf::Vector2f{0.1f, 0.1f});
	engine.applyGravity(ball);

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (sf::Event::Closed == ev.type ||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
			{
				window.close();
			}
			// Should we listen to event here???
			evManager.listen(ev);
		}
		engine.applyCollision(ball);
		engine.move(ball);

		//std::cout << "Position (" << ball.getPosition().x << "," << ball.getPosition().y << ")" << std::endl;
		std::cout << "Velocity: " << ball.getVelocity().x << "," << ball.getVelocity().y << std::endl;
		std::cout << "Acceleration: " << ball.getAcceleration().x << "," << ball.getAcceleration().y << std::endl;

		window.clear();

		window.draw(ball.getDrawable());
		window.display();

		// integrate engine on the manager????
		// should manager handle all window events????
	}
	
	return EXIT_SUCCESS;
}
