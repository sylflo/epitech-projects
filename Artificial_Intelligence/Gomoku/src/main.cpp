//
// main.cpp for gomoku in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:28:52 2014
// Last update Sun Jan  4 18:55:44 2015 caille_j
//

#include "Game.hpp"
#include "Menu.hpp"

int	main()
{
  try
    {
      sf::RenderWindow	*window = new sf::RenderWindow(sf::VideoMode(1024, 760),
						      "Gomoku",
						      sf::Style::Titlebar |
						      sf::Style::Close);
      Sound		*sound = new Sound();
      sf::Event		*event = new sf::Event();
      std::string	ret = "again";

      window->setFramerateLimit(60);
      while (ret == "again")
	{
	  Menu		*menu = new Menu(window, sound, event);

	  if (!menu->initialize())
	    throw Exception("[ERROR] : an error occured during menu initialisation");
	  while ((ret = menu->events()) == "continue")
	    menu->show();
	  delete menu;
	  if (ret == "quit")
	    break ;

	  Game		*game = new Game(window, sound, event, ret);

	  if (!game->initialize())
	    throw Exception("[ERROR] : an error occured during menu initialisation");
	  while ((ret = game->events()) == "continue")
	    game->show();
	}
      delete window;
      delete event;
      delete sound;
    }
  catch (const Exception &e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
