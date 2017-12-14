/*
** IA.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Wed Jun 25 22:42:00 2014 maxime duboy
** Last update Sun Jul 13 23:35:29 2014 
*/

#include "server.h"

void	init_AI(t_trantorian *AI, t_server *server)
{
  int	i;

  i = -1;
  AI->posX = rand() % server->ln.width;
  AI->posY = rand() % server->ln.height;
  AI->food = 10;
  AI->level = 1;
  AI->time_death = -1;
  AI->is_incantation = 0;
  AI->is_dead = 0;
  AI->is_graphic = 0;
  AI->fork_flag = 0;
  AI->is_first = 0;
  AI->dir = rand() % 4 + 1;
  while (++i != 6)
    AI->stones[i] = 0;
  if ((AI->list = (t_ring_buff *) malloc(sizeof (t_ring_buff))) == NULL)
    {
      perror("malloc");
      exit(-1);
    }
  init_list(AI->list);
}

void		aff_list(t_server *server)
{
  t_trantorian *hand;

  hand = server->ln.AI;
  if (hand != NULL)
    {
      while (hand != NULL)
	{
	  printf("L'Ia actuelle est : %d\n", hand->socket);
	  hand = hand->next;
	}
    }
}

int		add_ia(int fd, t_server *server)
{
  t_trantorian	*new;
  t_trantorian	*hand;

  if ((new = malloc(sizeof(t_trantorian))) == NULL)
    {
      exit(-1);
      return (FALSE);
    }
  new->socket = fd;
  new->next = NULL;
  if (server->ln.AI == NULL)
    server->ln.AI = new;
  else
    {
      hand = server->ln.AI;
      while (hand->next != NULL)
	hand = hand->next;
      hand->next = new;
    }
  init_AI(new, server);
  return (TRUE);
}

int		del_ia(int fd, t_server *server)
{
  t_trantorian	*hand;
  t_trantorian	*next;

  if (server->ln.AI == NULL)
    return (TRUE);
  hand = server->ln.AI;
  if (hand->socket == fd)
    {
      next = hand->next;
      free(hand);
      server->ln.AI = next;
      return (TRUE);
    }
  while (hand != NULL && hand->next != NULL)
    {
      if (hand->next->socket == fd)
	{
	  next = hand->next;
	  hand->next = hand->next->next;
	  free(next);
	}
      hand = hand->next;
    }
  return (TRUE);
}

t_trantorian	*get_AI(int fd, t_server *server)
{
  t_trantorian	*hand;

  hand = server->ln.AI;
  while (hand != NULL)
    {
      if (hand != NULL)
	if (hand->socket == fd)
	  return (hand);
      hand = hand->next;
    }
  return (hand);
}
