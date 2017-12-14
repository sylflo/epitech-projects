//
// Network.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Tue Jun 24 04:24:35 2014 Julian Caille
// Last update Sun Jul 13 18:43:03 2014 Arthur Coudert
//

#include "Network.hpp"

Network::Network(const std::string &ip, const int &port) : _ip(ip),
							   _port(port)
{
  _quit = false;
}

Network::~Network()
{
}

void	Network::parseTempString(char msg[2])
{
  std::vector<std::string>	parsed;

  _mutex.lock();
  if (msg[0] == '\n')
    {
      _command = _temp;
      if (!_command.empty())
	{
	  boost::split(parsed, _command, boost::is_any_of(" "));
	  _world.parseCommand(parsed);
	  _command.clear();
	  parsed.clear();
	}
      _temp.clear();
    }
  else
    {
      _temp += msg[0];
    }
  _mutex.unlock();
}

void	Network::receivePackets()
{
  char	msg[2];

  while (1)
    {
      _mutex.lock();
      if (_quit)
	break ;
      _mutex.unlock();
      memset(msg, 0, 2);
      try{
	if (_socket.receive_socket((void *)msg, 1) != Socket::SUCCESS)
	  {
	    _mutex.lock();
	    _thread->terminate();
	    _mutex.unlock();
	    _socket.disconnect();
	    throw MyError("Error : connection to host encountered an error !");
	    return ;
	  }
      }catch (const MyError & e)
	{
	  throw MyError(std::string(e.what()));
	  return;
	}
      parseTempString(msg);
    }
}

sf::Thread	*Network::getThread()
{
  return (_thread);
}

bool	Network::initializeNetwork()
{
  sf::Time timeout = sf::seconds(30);

  _quit = false;
  if (_socket.connect_socket(_ip, _port, timeout.asSeconds()) == Socket::SUCCESS)
    {
      _thread = new sf::Thread(&Network::receivePackets, this);
      _thread->launch();
      return (true);
    }
  return (false);
}
