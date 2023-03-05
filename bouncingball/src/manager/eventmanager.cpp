#include <iostream> // @Todo: Remove me
#include "manager/eventmanager.hpp"

namespace manager
{
void EventManager::listen(const sf::Event& ev)
{
	std::cout << "Listening to an event..." << std::endl;

	if (sf::Event::EventType::KeyPressed == ev.type)
	{
		handleKeyboardEvent(ev);
	}
}

/*
template <>
void EventManager::handleEvent(const sf::Event::EventType eventType)
{
	std::cout << "KEYPRESSED EVENT!" << std::endl;
}
*/

void EventManager::handleKeyboardEvent(const sf::Event& ev)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		std::cout << "A is PRESSED!" << std::endl;
}

} // namespace manager

