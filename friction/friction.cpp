#include <iostream>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define UNIT_FORCE 1
#define FRICTION_COEFF 0.95

sf::Vector2f operator*(const sf::Vector2f& vec, float val)
{
	return sf::Vector2f{vec.x * val, vec.y * val};
}

sf::Vector2f calculateFriction(const sf::Vector2f& velocity)
{
	return velocity * -1 * UNIT_FORCE * FRICTION_COEFF;
}

bool isInLeftEdge(float leftBound)
{
	return leftBound <= 0;
}

bool isInRightEdge(float rightBound)
{
	return rightBound >= SCREEN_WIDTH;
}

float zoneOffset{50};
std::vector<std::pair<float, float>> zones = {
	{SCREEN_WIDTH/4 - zoneOffset, SCREEN_WIDTH/4 + zoneOffset},
	{SCREEN_WIDTH * 3/4 - zoneOffset, SCREEN_WIDTH * 3/4 + zoneOffset}};

bool isInZone(int identifier)
{
	for (const auto& zone : zones)
	{
		if (identifier >= zone.first && identifier <= zone.second)
		{ 
			//std::cout << "In the zone!" << std::endl;
			return true;
		}
	}
	//std::cout << "NOT In the zone!" << std::endl;
	return false;
}

int main()
{
	std::cout << "Friction!" << std::endl;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Friction!");

	// Setup Floor
	float floorHeight{20};
	sf::RectangleShape floor(sf::Vector2f{SCREEN_WIDTH, floorHeight});
	floor.setFillColor(sf::Color::Cyan);
	floor.setPosition(sf::Vector2f{0, SCREEN_HEIGHT - floorHeight});

	// Setup Rough Floor
	sf::RectangleShape roughFloor1(sf::Vector2f{zoneOffset * 2, floorHeight});
	sf::RectangleShape roughFloor2(sf::Vector2f{zoneOffset * 2, floorHeight});
	roughFloor1.setFillColor(sf::Color::Blue);
	roughFloor2.setFillColor(sf::Color::Blue);
	roughFloor1.setPosition(sf::Vector2f{SCREEN_WIDTH/4 - zoneOffset, SCREEN_HEIGHT - floorHeight});
	roughFloor2.setPosition(sf::Vector2f{SCREEN_WIDTH * 3/4 - zoneOffset, SCREEN_HEIGHT - floorHeight});

	// Setup the BALL
	const float ballRadius{10.f};
	sf::CircleShape ball{ballRadius};
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(sf::Vector2f{
		SCREEN_WIDTH/2 - ballRadius,
		SCREEN_HEIGHT - (2 * ballRadius) - floorHeight});

	//const float force{0.0125f};
	const float force{0.0125f};
	sf::Vector2f velocity{0, 0};
	auto appliedVelocity = velocity;
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
				if (ev.key.code == sf::Keyboard::Key::Left)
					velocity = sf::Vector2f{-force, 0};
				if (ev.key.code == sf::Keyboard::Key::Right)
					velocity = sf::Vector2f{force, 0};
			}
		}
		
		if ((isInLeftEdge(ball.getPosition().x) && velocity.x <= 0) ||
			(isInRightEdge(ball.getPosition().x + (ball.getRadius() * 2)) && velocity.x >= 0))
		{
			velocity = sf::Vector2f{0, 0};
		}

		if (isInZone(ball.getPosition().x + ball.getRadius()))
		{
			const auto& friction = calculateFriction(velocity);
			appliedVelocity = velocity + friction;
			//std::cout << "Friction: " << friction.x << "," << friction.y << std::endl;
			//std::cout << "Velocity: " << velocity.x << "," << velocity.y << std::endl;
			std::cout << "AppliedVelocity: " << appliedVelocity.x << "," << appliedVelocity.y << std::endl;
		}
		else
		{
			appliedVelocity = velocity;
			std::cout << "AppliedVelocity: " << appliedVelocity.x << "," << appliedVelocity.y << std::endl;
		}
		//std::cout << "Position: " << ball.getPosition().x << "," << ball.getPosition().y << std::endl;

		ball.setPosition(ball.getPosition() + appliedVelocity);

		
		window.clear();
		window.draw(floor);
		window.draw(roughFloor1);
		window.draw(roughFloor2);
		window.draw(ball);
		window.display();
	}

	return EXIT_SUCCESS;
}

