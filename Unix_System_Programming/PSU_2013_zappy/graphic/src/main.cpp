//
// main.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 16:06:10 2014 Julian Caille
// Last update Sun Jul 13 23:46:46 2014 Julian Caille
//

#include "Sound.hpp"
#include "Display.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "MyError.hpp"
#include "SFML/Window.hpp"
#include <boost/algorithm/string.hpp>

std::vector<std::string>	parseIp(std::string &_ip)
{
  std::vector<std::string>	finished;

  boost::split(finished,_ip,boost::is_any_of(":"));
  return (finished);
}

int		main()
{
  sf::RenderWindow	window(sf::VideoMode(1024, 768), "Zappy",
			       sf::Style::Titlebar | sf::Style::Close);
  sf::View		view(sf::FloatRect(0, 0, 1024, 768));
  Sound			sound;
  sf::Event		event;
  Menu			*menu;
  Game			*game;
  std::string		ret;
  std::vector<std::string>	ip;

  window.setView(view);
  while (ret != "quit")
  {
    menu = new Menu(&window, sound, event, &view);
    if (!menu->initialize())
      {
	std::cerr << "Error while initializing" << std::endl;
	return (EXIT_FAILURE);
      }
    while ((ret = menu->events()) == "continue")
      menu->show();
    if (ret == "quit")
      return (EXIT_SUCCESS);
    std::cout << "[Initialize game] with ip : " << ret << std::endl;
    ip = parseIp(ret);
    if (ip.empty() || ip.size() != 2 || ip[1].empty())
      {
	std::cerr << "Ip badly formated, you might have forgotten to specify the port" << std::endl;
	return EXIT_FAILURE;
      }
    delete menu;
    try{
      game = new Game(&window, sound, event, &view, ip[0], atoi(ip[1].c_str()));
      if (!game->initialize())
	return (EXIT_FAILURE);
      ret.clear();
      while ((ret = game->events()) == "continue")
	game->show();
    }
    catch (const MyError &e){
      std::cerr << e.what() << std::endl;
      delete game;
      return (EXIT_FAILURE);
    }
    delete game;
  }
  return (EXIT_SUCCESS);
}
