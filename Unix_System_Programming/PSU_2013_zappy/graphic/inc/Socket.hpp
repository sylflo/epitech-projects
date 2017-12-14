//
// Socket.hpp for zappy in /home/storm/zappy/zappy/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jul 10 20:26:34 2014 Julian Caille
// Last update Sun Jul 13 18:55:45 2014 Arthur Coudert
//

#ifndef _SOCKET_HPP_
# define _SOCKET_HPP_

# include <iostream>
# include <cstring>
# include <string>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <unistd.h>

class	Socket
{
public:
  enum
    {
      ERROR = -1,
      SUCCESS
    };

public:
  int	connect_socket(std::string const &ip, int const &port, int const &timeout);
  int	send_socket(void *message, int const &size);
  int	receive_socket(void *buffer, int const &size);
  void	disconnect();
private:
  int	_socket;
};

# endif /* !_SOCKET_HPP_ */
