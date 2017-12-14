/*
** ppo.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jun 29 18:02:22 2014
** Last update Fri Jul 11 21:54:44 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int	call_ppo(int fd, t_server *server)
{
  char	fd_char[10];
  char	ppo_char[10] = {"ppo "};

  if (sprintf(fd_char, "%d", fd) < 0)
    return (FALSE);
  strcat(ppo_char, fd_char);
  strcat(ppo_char, "\n");
  ppo_func(ppo_char, server);
  send_to_graphic(server->ln.response, server);
  return (TRUE);
}

void	fill_str(char id_char[10], char posX_char[10], char posY_char[10],
		 char dir_char[10], t_server *server)
{
  strcat(server->ln.response, id_char);
  strcat(server->ln.response, " ");
  strcat(server->ln.response, posX_char);
  strcat(server->ln.response, " ");
  strcat(server->ln.response, posY_char);
  strcat(server->ln.response, " ");
  strcat(server->ln.response, dir_char);
  strcat(server->ln.response, "\n");
}

int	fill_pos(char *token, t_server *server)
{
  int	id_player;
  char	id_char[10];
  char	posX_char[10];
  char	posY_char[10];
  char	dir_char[10];

  id_player = atoi(token);
  if (!get_AI(id_player, server))
    return (-2);
  if (get_AI(id_player, server)->is_graphic == 2)
    {
      if (sprintf(posX_char, "%d", get_AI(id_player, server)->posX) < 0 ||
	  sprintf(posY_char, "%d", get_AI(id_player, server)->posY) < 0 ||
	  sprintf(dir_char, "%d", get_AI(id_player, server)->dir) < 0 ||
	  sprintf(id_char, "%d", get_AI(id_player, server)->socket) < 0)
	return (FALSE);
      fill_str(id_char, posX_char, posY_char, dir_char, server);
      return (TRUE);
    }
  return (-2);
}

int	ppo_func(char *buf, t_server *server)
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
	  if ((ret = fill_pos(token, server)) == FALSE)
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
