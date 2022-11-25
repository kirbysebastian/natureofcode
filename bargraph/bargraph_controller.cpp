#include <iostream>
#include "utilities.hpp"
#include "bargraph_controller.hpp"

BarGraphController::BarGraphController(
		const std::uint32_t numOfBars,
		const std::uint32_t width,
		const std::uint32_t height) :
	m_numOfBars(numOfBars),
	m_width(width),
	m_height(height),
	m_bars(m_numOfBars)
{
	initBars();
}

BarGraphController::~BarGraphController() {}


void BarGraphController::getEvent(const sf::Event& ev)
{
}

const sf::CircleShape& BarGraphController::getDrawable() const
{
	return sf::CircleShape(0.f);
}

void BarGraphController::draw(sf::RenderWindow& window)
{
	for (auto& bar : m_bars)
	{
		window.draw(bar);
	}
}

void BarGraphController::increaseHeight(sf::RenderWindow& window)
{
	//const auto idx = utils::random<int>(1, 100);
	
	//How much spread from the mean
	constexpr int kStdDeviation{10};
	const auto idx = utils::randomGaussian(1, 100, kStdDeviation);
	if (idx == 0)
		return;
	auto& bar = m_bars[idx-1];
	std::cout << "Bar[" << idx-1 << "] size: (" <<
		bar.getSize().x << "," << bar.getSize().y <<
		")" << std::endl;	
	bar.setSize(bar.getSize() + sf::Vector2f(0, 2));
	bar.setPosition(bar.getPosition() - sf::Vector2f(0, 2));
}

void BarGraphController::initBars()
{
	std::cout << "Size: " << m_bars.size() << std::endl;
	std::cout << "W: " << m_width << std::endl;
	float barWidth{m_width/m_numOfBars};
	float barHeight{20};

	auto currXPos{barWidth/2};
	auto currYPos{m_height - (barHeight/2)};
	for (auto& bar : m_bars)
	{
		bar.setSize({barWidth, barHeight});
		bar.setPosition(currXPos, currYPos);
		bar.setFillColor(sf::Color::Red);

		currXPos += barWidth;
	}
}

