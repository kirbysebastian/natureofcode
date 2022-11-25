#include "IController.hpp"

class BarGraphController final : public IController
{
public:
	BarGraphController(
		const std::uint32_t,
		const std::uint32_t,
		const std::uint32_t);
	~BarGraphController();

	void getEvent(const sf::Event&) override;
	const sf::CircleShape& getDrawable() const override;

	void draw(sf::RenderWindow&);
	void increaseHeight(sf::RenderWindow&);

private:
	void initBars();

	std::uint32_t m_numOfBars;
	std::uint32_t m_width;
	std::uint32_t m_height;
	std::vector<sf::RectangleShape> m_bars;
};
