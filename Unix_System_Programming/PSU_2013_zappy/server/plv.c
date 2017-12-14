/*
** ppo.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jun 29 18:02:22 2014
** Last update Tue Jul  8 17:28:46 2014 
*/

#include "server.h"

int	fill_level(char *token, t_server *server)
{
  int	id_player;
  char	id_char[10];
  char	level_char[10];

  id_player = atoi(token);
  if (!get_AI(id_player, server))
    return (-2);
  if (get_AI(id_player, server)->is_graphic == 2)
    {
      if (sprintf(level_char, "%d", get_AI(id_player, server)->level) < 0 ||
	  sprintf(id_char, "%d", get_AI(id_player, server)->socket) < 0)
	return (FALSE);
      strcat(server->ln.response, id_char);
      strcat(server->ln.response, " ");
      strcat(server->ln.response, level_char);
      strcat(server->ln.response, " \n");
      return (TRUE);
    }
  return (-2);
}

int	plv_func(char *buf, t_server *server)
{
  char	*token;
  int	i;
  int	ret;

  i = 0;
  token = strtok(buf, " ");
  while (token)
    {
      if (i == 0)
	strcpy(server->ln.response, "ppo ");
      else if (i == 1)
	{
	  if ((ret = fill_level(token, server)) == FALSE)
	    return (FALSE);
	  else if (ret == -2)
	    return (-2);
	}
      token = strtok(NULL, " ");
      i++;
    }
  if (i != 2)
    return (-2);
  return (TRUE);
}
