/*
** verif_malloc.c for zappy in /tmp/PSU_2013_zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Sun Jul 13 16:52:29 2014 maxime duboy
** Last update Sun Jul 13 16:53:48 2014 maxime duboy
*/

#include	<stdio.h>
#include	"server.h"

void	verif_malloc(t_server *server, int i)
{
  if ((server->ln.team_name = malloc((i + 1) * sizeof(char **))) == NULL)
    {
      perror("Malloc : ");
      exit (EXIT_FAILURE);
    }
  server->ln.team_name[i] = NULL;
  if ((server->ln.allow_team = malloc((i + 1) * sizeof(int *))) == NULL)
    {
      perror("Malloc : ");
      exit (EXIT_FAILURE);
    }
  server->ln.allow_team[i] = 1;
}
