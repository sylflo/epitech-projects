/*
** check_and_exec_cmd_ia.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jul  7 21:18:41 2014
** Last update Sun Jul 13 20:19:59 2014 
*/

#include "server.h"

int	check_cmd_ia(char *buf, int fd)
{
  int	i;
  char *token;
  char  *command[12] = {"prend", "pose", "inventaire", "avance",
			"droite", "gauche", "incantation",
			"voir", "expulse", "fork", "broadcast",
			"connect_nbr"};
  i = -1;
  token = strdup(buf);
  token = strtok(token, " ");
  while (++i < 12)
    {
      if (!strcmp(command[i], token))
	{
	  free(token);
	  return (TRUE);
	}
    }
  free(token);
  write(fd, "suc\n", strlen("suc\n"));
  return (FALSE);
}

void		exec_cmd_ai(t_select *s_select, t_server *server)
{
  double	current_time;
  int		ret;

  if (get_AI(server->ln.fd_time, server) &&
      get_AI(server->ln.fd_time, server)->is_graphic == 2)
    {
      if (get_AI(server->ln.fd_time, server)->list->begin)
	{
	  current_time = convert_to_micro(&server->ln.current_time);
	  if (get_AI(server->ln.fd_time, server)->list->begin->future_time <=
	      current_time)
	    {
	      ret = command_AI(get_AI(server->ln.fd_time,
				      server)->list->begin->data,
			       server->ln.fd_time, server);
	      if (get_AI(server->ln.fd_time, server)->list->size == 1)
		del_list_circ_unique(get_AI(server->ln.fd_time, server)->list);
	      else
		del_list_circ(get_AI(server->ln.fd_time, server)->list);
	      if (ret == -2)
		close_fd(server->ln.fd_time, s_select, server);
	    }
	}
    }
}
