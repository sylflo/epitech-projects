/*
** create_server_2.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Jun 24 11:00:43 2014
** Last update Sun Jul 13 20:30:17 2014 
*/

#include <unistd.h>
#include "server.h"

int			func_accept(t_select *s_select, t_server *server)
{
  socklen_t		addrlen;
  struct sockaddr_in	clientaddr;
  int			newfd;

  addrlen = sizeof(clientaddr);
  if ((newfd = accept(s_select->listener,
		      (struct sockaddr *)&clientaddr,
		      &addrlen)) == -1)
    {
      perror("accept");
      free_end(server);
      exit(FALSE);
    }
  else
    {
      FD_SET(newfd, &s_select->master);
      if (newfd > s_select->fdmax)
	s_select->fdmax = newfd;
      add_ia(newfd, server);
      write(newfd, "BIENVENUE\n", 10);
      printf("Sending message BIENVENUE to %d\n", newfd);
    }
  return (TRUE);
}

int	func_send(t_select *s_select, char *buf, int i, int nbytes)
{
  int	j;

  j = 0;
  while (j <= s_select->fdmax)
    {
      if (FD_ISSET(j, &s_select->master))
	{
	  if (j != s_select->listener && j != i)
	    {
	      if (send(j, buf, nbytes, 0) == -1)
		perror("send");
	    }
	}
      j++;
    }
  return (TRUE);
}
