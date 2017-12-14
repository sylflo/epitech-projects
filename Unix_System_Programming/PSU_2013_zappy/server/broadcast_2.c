/*
** broadcast_2.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jul 13 21:28:42 2014
** Last update Sun Jul 13 21:29:02 2014 
*/

#include "server.h"

void	send_broadcast(t_server *server, char *buffer, int fd)
{
  char	response[100] = {0};

  sprintf(response, "pbc %d %s\n", fd, buffer);
  send_to_graphic(response, server);

}
