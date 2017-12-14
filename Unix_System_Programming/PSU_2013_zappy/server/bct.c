/*
** bct.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jun 26 15:16:25 2014
** Last update Sun Jul 13 21:50:46 2014 
*/

#include "server.h"

int	check_num_case(int pos, char *token)
{
  int	i;

  i = -1;
  if (pos < 0)
    return (FALSE);
  else if (pos == 0)
    {
      while (token[++i])
	{
	  if (token[i] != '0' && token[i] !='\n')
	    return (FALSE);
	}
    }
  return (TRUE);
}

int	check_and_cat_cmd(int posX, int posY, int posCase, t_server *server)
{
  if (posX > server->ln.width - 1 || posY > server->ln.height - 1)
    return (-2);
  sprintf(server->ln.response, "bct %d %d %d", posX, posY,
	  server->ln.map[posCase].food);
  return (TRUE);
}

int	object_in_case(int posX, int posY, t_server *server)
{
  int	posCase;
  int	i;
  int	ret;
  char	stones_char[10];

  i = -1;
  posCase = posY * (server->ln.width) + (posX);
  ret = check_and_cat_cmd(posX, posY, posCase, server);
  if (ret == -2)
    return (-2);
  else if (ret == FALSE)
    return (FALSE);
  while (++i < 6)
    {
      strcat(server->ln.response, " ");
      if (sprintf(stones_char, "%d", server->ln.map[posCase].stones[i]) < 0)
	return (-2);
      strcat(server->ln.response, stones_char);
    }
  strcat(server->ln.response, "\n");
  return (TRUE);
}

int	call_check_num_case(int i, int *posX, int *posY, char *token)
{
  if (i == 1)
    {
      *posX = atoi(token);
      if (check_num_case(*posX, token) == FALSE)
	return (-2);
    }
  else if (i == 2)
    {
      *posY = atoi(token);
      if (check_num_case(*posY, token) == FALSE)
	return (-2);
    }
  return (TRUE);
}

int	bct_func(char *buffer, t_server *server)
{
  char	*token;
  int	posX;
  int	posY;
  int	i;

  i = 0;
  token = strtok(buffer, " ");
  while (token)
    {
      if (call_check_num_case(i, &posX, &posY, token) == -2)
	return (TRUE);
      token = strtok(NULL, " ");
      i++;
    }
  if (i != 3)
    return (-2);
  return (object_in_case(posX, posY, server));
}
