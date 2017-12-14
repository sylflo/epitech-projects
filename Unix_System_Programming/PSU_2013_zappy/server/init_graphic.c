/*
** init_graphic.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jun 30 11:48:57 2014
** Last update Sun Jul 13 21:49:10 2014 
*/

#include <unistd.h>
#include "server.h"
#include "cmd_graphic.h"

void		exec_pnw(t_server *server)
{
  t_trantorian	*hand;
  char		cmd_pin[10];
  char		id[10];

  hand = server->ln.AI;
  while (hand != NULL)
    {
      if (hand->is_graphic == 2)
	{
	  pnw_cmd(hand, server);
	  write(server->ln.client_fd, server->ln.response,
		strlen(server->ln.response));
	  memset(server->ln.response, 0, 2048);
	  sprintf(id, "%d", hand->socket);
	  strcpy(cmd_pin, "pin ");
	  strcat(cmd_pin, id);
	  pin_func(cmd_pin, server);
	  write(server->ln.client_fd, server->ln.response,
		strlen(server->ln.response));
	  memset(server->ln.response, 0, 2048);
	  memset(server->ln.response, 0, 10);

	}
      hand = hand->next;
    }
}

void	init_graphic(t_server *server)
{
  msz_func("msz\n", server);
  write(server->ln.client_fd, server->ln.response,
	strlen(server->ln.response));
  sgt_func("sgt\n", server);
  write(server->ln.client_fd, server->ln.response,
	strlen(server->ln.response));
  mct_func("mct\n", server);
  write(server->ln.client_fd, server->ln.response,
	strlen(server->ln.response));
  tna_func("tna\n", server);
  write(server->ln.client_fd, server->ln.response,
	strlen(server->ln.response));
  exec_pnw(server);
}
