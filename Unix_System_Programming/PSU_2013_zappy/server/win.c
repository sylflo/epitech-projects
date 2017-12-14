/*
** win.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jul 13 04:12:45 2014
** Last update Sun Jul 13 16:27:25 2014 
*/

#include "server.h"

int		win(t_server *server)
{
  t_trantorian	*ai;
  int		array_level8[server->ln.nbr_team];

  memset(array_level8, 0, server->ln.nbr_team);
  ai = server->ln.AI;
  while (ai)
    {
      if (ai->level == 8)
	{
	  if (array_level8[ai->team == 5])
	    {
	      printf("The team %s wins the game\n",
		     server->ln.team_name[ai->team]);
	      quit_game(server);
	      return (TRUE);
	    }
	  array_level8[ai->team]++;
	}
      ai = ai->next;
    }
  return (FALSE);
}
