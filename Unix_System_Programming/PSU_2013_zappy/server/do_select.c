/*
** do_select.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Fri Jul 11 17:30:17 2014
** Last update Sun Jul 13 21:49:49 2014 
*/

#include <sys/time.h>
#include <errno.h>
#include "server.h"

void	quit_game(t_server *server)
{
  if (errno == EINTR)
    printf("You just quit the server\n");
  if (errno == EINVAL)
    printf("There was a problem with select\n");
  free_end(server);
  exit(-1);
}

void	do_select_action(t_server *server, t_select *s_select)
{
  exec_incantation_and_fork(server);
  if (select(s_select->fdmax + 1, &s_select->read_fds,
	     NULL, NULL, &server->ln.exec_action) == -1)
    {
      quit_game(server);
      perror("select");
    }
}

void	do_select(t_server *server, t_select *s_select)
{
  if (check_dead_ia(server) == TRUE ||
      find_min_time_first_command(server) == TRUE)
    do_select_action(server, s_select);
  else if (find_min_death(server) != -1)
    {
      if (select(s_select->fdmax + 1, &s_select->read_fds,
		 NULL, NULL, &server->ln.exec_death) == -1)
	{
	  quit_game(server);
	  perror("select");
	}
    }
  else
    {
      if (select(s_select->fdmax + 1, &s_select->read_fds,
		 NULL, NULL, NULL) == -1)
	{
	  quit_game(server);
	  perror("select");
	}
    }
}

void	loop_select(t_select *s_select, t_server *server)
{
  server->ln.fd_time = 0;
  while (win(server) == FALSE && g_quit == TRUE)
    {
      memset(server->ln.response, 0, 100);
      s_select->read_fds = s_select->master;
      do_select(server, s_select);
      kill_ai(server, s_select);
      gettimeofday(&server->ln.current_time, NULL);
      exec_cmd_ai(s_select, server);
      fd_loop(s_select, server);
      memset(server->ln.response, 0, 100);
    }
}
