#ifndef BOUNCINGBALL_MANAGER_EVENTMANAGER_HPP
#define BOUNCINGBALL_MANAGER_EVENTMANAGER_HPP

#include <SFML/Window/Event.hpp>

namespace manager
{

class EventManager
{
public:
	void listen(const sf::Event& ev);

private:
	/*
	template <typename T>
	void handleEvent(const T) { return; }
	*/

	void handleKeyboardEvent(const sf::Event&);
};

} // namespace manager
#endif // BOUNCINGBALL_MANAGER_EVENTMANAGER_HPP

