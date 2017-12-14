/*
** exec_incantation_and_fork.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul 12 20:42:36 2014
** Last update Sun Jul 13 20:31:00 2014 
*/

#include "server.h"

void	exec_incantation(t_server *server, int fd)
{
  if (get_AI(fd, server) && get_AI(fd, server)->list->begin &&
      !strcmp(get_AI(fd, server)->list->begin->data, "incantation") &&
      get_AI(fd, server)->is_incantation == 0)
    {
      if (incantation_func("incantation", fd, server) == FALSE)
	{
	  if (get_AI(fd, server)->list->size == 1)
	    del_list_circ_unique(get_AI(fd, server)->list);
	  else
	    del_list_circ(get_AI(fd, server)->list);
	}
    }
}

void	exec_fork(t_server *server, int fd)
{
  if (get_AI(fd, server) && get_AI(fd, server)->list->begin &&
      !strcmp(get_AI(fd, server)->list->begin->data, "fork") &&
      get_AI(fd, server)->fork_flag == 0)
    {
      if (fork_func("fork", fd, server) == FALSE)
	{
	  if (get_AI(fd, server)->list->size == 1)
	    del_list_circ_unique(get_AI(fd, server)->list);
	  else
	    del_list_circ(get_AI(fd, server)->list);
	}
    }
}

void		exec_incantation_and_fork(t_server *server)
{
  t_trantorian	*ai;
  int		fd[(server->ln.allow_client + 1) * server->ln.nbr_team];
  int		i;

  memset(fd, 0, (server->ln.allow_client + 1) * server->ln.nbr_team);
  i = 0;
  ai = server->ln.AI;
  while (ai)
    {
      if (ai->is_graphic == 2)
	{
	  fd[i] = ai->socket;
	  i++;
	}
      ai = ai->next;
    }
  fd[i] = -1;
  i = -1;
  while (fd[++i] != -1)
    {
      exec_incantation(server, fd[i]);
      exec_fork(server, fd[i]);
    }
}
