/*
** server.c for zappy in /home/duboy_m/zappy/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Wed Jun 18 09:41:53 2014 maxime duboy
** Last update Sun Jul 13 21:31:07 2014 
*/

#include <signal.h>
#include "server.h"

void	set_nbr_team(t_server *server)
{
  int	i;

  i = 0;
  if (server->ln.allow_client != 1)
    {
      while (server->ln.team_name[i])
	{
	  server->ln.allow_team[i] = server->ln.allow_client;
	  i++;
	}
    }
}

void		free_end(t_server *server)
{
  t_trantorian  *ai;
  int           fd[(server->ln.allow_client + 1) * server->ln.nbr_team];
  int           i;

  memset(fd, 0, (server->ln.allow_client + 1) * server->ln.nbr_team);
  i = 0;
  ai = server->ln.AI;
  while (ai)
    {
      fd[i] = ai->socket;
      i++;
      destroy(ai->list);
      free(ai->list);
      ai = ai->next;
    }
  fd[i] = -1;
  i = -1;
  while (fd[++i] != -1)
    del_ia(fd[i], server);
  free(server->ln.team_name);
  free(server->ln.allow_team);
  free(server->ln.map);
}

void    init_struct(t_server *server)
{
  server->ln.team_name = NULL;
  server->ln.allow_team = NULL;
  server->ln.map = NULL;
}

void	intHandler()
{
  g_quit = FALSE;
}

int		main(int argc, char **argv)
{
  t_server	server;

  g_quit = TRUE;
  init_struct(&server);
  signal(SIGINT, intHandler);
  parse_arg(argc, argv, &server);
  set_nbr_team(&server);
  if (server.ln.width < 10 || server.ln.height < 10)
    {
      fprintf(stderr, "Height and width must be superior to 10\n");
      return (FALSE);
    }
  init_map(&server);
  init_command_func(&server);
  if (create_server(&server) == FALSE)
    return (FALSE);
  return (TRUE);
}
