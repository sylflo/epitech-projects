//
// Network.hpp for zappy in /home/storm/zappy/zappy/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Tue Jun 24 04:20:22 2014 Julian Caille
// Last update Sun Jul 13 20:07:05 2014 Arthur Coudert
//

#ifndef _NETWORK_HPP_
# define _NETWORK_HPP_

# include "Socket.hpp"
# include "MyError.hpp"
# include "World.hh"
# include <SFML/Network.hpp>
# include <iostream>
# include <unistd.h>
# include <string.h>
# include <boost/algorithm/string.hpp>

class	Network
{
public:
  Network(const std::string &ip, const int &port);
  ~Network();
  bool	initializeNetwork();
  void	receivePackets();
  void	parseTempString(char msg[2]);
  sf::Thread *getThread();
protected:
  sf::Thread	*_thread;
  sf::Mutex	_mutex;
  std::string	_ip;
  std::string	_temp;
  std::string	_command;
  std::vector<Case*> _map;
  std::vector<LivingEntity*> _entities;
  Socket	_socket;
  bool		_quit;
  int		_port;
  World		_world;
};

#endif /* !_NETWORK_HPP_ */
