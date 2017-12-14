//
// Hotkeys.cpp for gomoku in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Sun Nov  9 17:10:46 2014
// Last update Sun Jan  4 18:53:15 2015 caille_j
//

#include "Menu.hpp"
#include "Game.hpp"

struct bitfield
{
	int champ1 : 2;

};

bool	Menu::hotKeys(const sf::Event::EventType &type)
{
  sf::Vector2i	localPosition = sf::Mouse::getPosition(*_window);

  if (type == sf::Event::Closed ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return (false);
	if (_event->type == sf::Event::KeyPressed)
		{
			if (_event->key.code == sf::Keyboard::Down)
				line++;
			if (_event->key.code == sf::Keyboard::Up)
				line--;
			if (_event->key.code == sf::Keyboard::Return)
				{
					if (subMenu == 0)
						{
							if (line == 1)
								_mode = !_mode;
							else if (line == 2)
								{
									subMenu = 1;
									line = 1;
								}
							else if (line == 3)
								{
									_finish = !_finish;
									return (false);
								}
							else if (line == 4)
								return (false);
						}
					else if (subMenu == 1)
						{
							if (line == 1)
								_option1 = !_option1;
							else if (line == 2)
								_option2 = !_option2;

							else
								subMenu = 0;
						}
				}
		}
	return (true);
}

bool	Game::hotKeys(const sf::Event::EventType &type)
{
	sf::Vector2i	localPosition = sf::Mouse::getPosition(*_window);

	if (type == sf::Event::Closed ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
		(localPosition.x >= 815 && localPosition.x <= 950 &&
		 localPosition.y >= 550 && localPosition.y <= 650 &&
		 sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		return (false);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (localPosition.x > 0 && localPosition.x < 760 &&
				localPosition.y > 0 && localPosition.y < 768)
				_referee.check(localPosition.x / 40, localPosition.y / 40, &_player);
			usleep(100000);
		}
	return (true);
}
