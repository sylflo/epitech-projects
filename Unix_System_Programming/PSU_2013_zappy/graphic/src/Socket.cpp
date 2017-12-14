//
// Socket.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jul 10 21:50:49 2014 Julian Caille
// Last update Sun Jul 13 18:55:17 2014 Arthur Coudert
//

#include "Socket.hpp"

void		Socket::disconnect()
{
  close(_socket);
}

int		Socket::receive_socket(void *buffer, int const &size)
{
  int		temp;

  if ((temp = recv(_socket, buffer, size, 0)) < 0)
    {
      std::cerr << "Error receiving message from host. Host may be disconnected" << std::endl;
      return (Socket::ERROR);
    }
  return (Socket::SUCCESS);
}

int		Socket::send_socket(void *message, int const &size)
{
  if (send(_socket, message, size, 0) < 0)
    {
      std::cerr << "Error receiving message from host. Host may be disconnected" << std::endl;
      return (Socket::ERROR);
    }
  return (Socket::SUCCESS);
}

int		Socket::connect_socket(std::string const &ip, int const &port,
				int const &timeout)
{
  struct hostent *hostinfo;
  struct sockaddr_in serv_addr;
  struct timeval	tv;

  tv.tv_sec = 30;
  if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      std::cout << "Couldn't create the socket :(" << std::endl;
      return (Socket::ERROR);
    }

  hostinfo = gethostbyname(ip.c_str());
  if (!hostinfo)
    {
      std::cerr << "Error : Could not retrive the adress " << ip << std::endl ;
      return (Socket::ERROR);
    }
  serv_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_family = AF_INET;

  setsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO,(struct timeval *)&tv,sizeof(struct timeval));
  if (connect(_socket, (struct sockaddr *)(&serv_addr), sizeof(serv_addr)) == -1)
    {
      std::cerr << "Couldn't connect to remote host" << std::endl;
      return (Socket::ERROR);
    }
  (void)timeout;
  return (Socket::SUCCESS);
}
