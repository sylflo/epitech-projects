/*
** create_server.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Thu Jun 26 15:30:14 2014 maxime duboy
** Last update Sun Jul 13 23:41:22 2014 
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "sanitizer.h"

void	exec_and_del_ai(int i, t_server *server, char *buf)
{
  if (get_AI(i, server) && get_AI(i, server)->is_graphic == 2
      &&  check_cmd_ia(buf, i) == TRUE)
    {
      if (get_AI(i, server)->list->size == 0)
	ins_list_circ_empty(get_AI(i, server)->list, buf, server);
      else if (get_AI(i, server)->list->size < 10)
        ins_list_circ(get_AI(i, server)->list,
		      get_AI(i, server)->list->end, buf, server);
    }
}

int	func_recv(t_select *s_select, int i, t_server *server)
{
  int	nbytes;
  char 	buf[1024] = {0};

  if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0)
    {
      if (nbytes == 0)
	close_fd(i, s_select, server);
      else
	{
	  perror("recv");
	  free_end(server);
	  exit(FALSE);
	}
    }
  if (get_AI(i, server) && buf[0] != '\0')
    {
      printf("Received message from %d %s\n", i, buf);
      server->ln.client_fd = i;
      sanitizer(buf);
      exec_and_del_ai(i, server, buf);
      exec_command(buf, i, s_select, server);
      if (server->ln.response != NULL)
	write(i, server->ln.response, strlen(server->ln.response));
    }
  return (TRUE);
}

int	fd_loop(t_select *s_select, t_server *server)
{
  int	i;

  i = 0;
  while (i <= s_select->fdmax)
    {
      if (FD_ISSET(i, &s_select->read_fds))
	{
	  if (i == s_select->listener)
	    func_accept(s_select, server);
	  else
	    func_recv(s_select, i, server);
	}
      i++;
    }
  return (TRUE);
}

int			func_bind(t_select *s_select, t_server *server)
{
  struct sockaddr_in    serveraddr;

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(server->ln.port);
  memset(&(serveraddr.sin_zero), '\0', 8);
  if (bind(s_select->listener, (struct sockaddr *)&serveraddr,
	   sizeof(serveraddr)) == -1)
    {
      perror("bind");
      exit(1);
    }
  if (listen(s_select->listener, 10) == -1)
    {
      perror("listen");
      exit(1);
    }
  FD_SET(s_select->listener, &(s_select->master));
  s_select->fdmax = s_select->listener;
  return (TRUE);
}

int	create_server(t_server *server)
{
  int	yes;

  yes = 1;
  FD_ZERO(&(server->ln.s_select.master));
  FD_ZERO(&(server->ln.s_select.read_fds));
  if ((server->ln.s_select.listener = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror("socket");
      exit(1);
    }
  if (setsockopt(server->ln.s_select.listener, SOL_SOCKET, SO_REUSEADDR, &yes,
		 sizeof(int)) == -1)
    {
      perror("setsockopt");
      exit(1);
    }
  func_bind(&server->ln.s_select, server);
  write_begin(server);
  loop_select(&server->ln.s_select, server);
  return (TRUE);
}
