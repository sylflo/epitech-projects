//
// Time.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sat Jul  5 17:05:30 2014 Julian Caille
// Last update Sun Jul 13 23:47:31 2014 Julian Caille
//

#include "Game.hpp"
#include <boost/lexical_cast.hpp>

void	Game::changeTime(int const &new_time)
{
  std::string temp;

  temp = "sst " + boost::lexical_cast<std::string>(new_time) + "\n";
  _mutex.lock();
  if (_socket.send_socket((void *)temp.c_str(), sizeof(temp.c_str())) == Socket::ERROR)
    throw MyError("Couldn't send time on socket");
  _mutex.unlock();
}
