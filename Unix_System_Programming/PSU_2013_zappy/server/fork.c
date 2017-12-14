/*
** fork.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Jul  8 16:52:44 2014
** Last update Sun Jul 13 20:31:19 2014 
*/

#include	<stdio.h>
#include	<sys/time.h>
#include	"server.h"
#include	"ai.h"
#include	"cmd_graphic.h"

int			set_hatch(t_trantorian *AI_egg, t_server *server)
{
  struct timeval	cur_time;
  double		time_set;

  gettimeofday(&cur_time, NULL);
  time_set = convert_to_micro(&cur_time);
  time_set += 600 / server->ln.delay * 1000000;
  cur_time.tv_sec = ((time_t)time_set / 1000000);
  cur_time.tv_usec = ((suseconds_t)time_set % 1000000);
  AI_egg->hatch = cur_time;
  return (TRUE);
}

int		create_egg(int fd, t_server *server)
{
  int		fd_egg;
  t_trantorian	*AI;
  t_trantorian	*AI_egg;

  fd_egg = 0 - fd;
  add_ia(fd_egg, server);
  AI_egg = get_AI(fd_egg, server);
  AI = get_AI(fd, server);
  AI_egg->posX = AI->posX;
  AI_egg->posY = AI->posY;
  AI_egg->is_graphic = 3;
  AI_egg->is_first = 1;
  AI_egg->hatch_flag = 0;
  AI_egg->team = AI->team;
  set_hatch(AI_egg, server);
  return (TRUE);
}

void	init_egg(t_trantorian *egg, t_trantorian *hand)
{
  int	i;

  i = 0;
  hand->posX = egg->posX;
  hand->posY = egg->posY;
  hand->food = 10;
  hand->level = 1;
  hand->is_graphic = 2;
  hand->team = egg->team;
  hand->dir = rand() % 4 + 1;
  while (++i != 6)
    hand->stones[i] = 0;
  if ((hand->list = (t_ring_buff *) malloc(sizeof (t_ring_buff))) == NULL)
    {
      perror("malloc");
      exit(-1);
    }
  init_list(hand->list);
}

int			check_egg_pop(int fd, t_server *server)
{
  t_trantorian		*egg;
  t_trantorian		*hand;
  struct timeval	cur_time;
  char			ebo[50];

  gettimeofday(&cur_time, NULL);
  egg = server->ln.AI;
  hand = get_AI(fd, server);
  while (egg != NULL)
    {
      if (egg->is_graphic == 3)
	if (egg->team == hand->team && !timercmp(&cur_time, &egg->hatch, <=))
	  {
	    sprintf(ebo, "ebo %d\n", egg->socket);
	    init_egg(egg, hand);
	    send_to_graphic(ebo, server);
	    pnw_cmd(hand, server);
	    del_ia(egg->socket, server);
	    return (TRUE);
	  }
      egg = egg->next;
    }
  return (FALSE);
}

int		fork_func(__attribute__((unused))char *buf, int fd,
			  t_server *server)
{
  char		pfk[20];
  t_trantorian	*hand;

  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  if (hand->fork_flag == 0)
    {
      memset(server->ln.response, 0, 2048);
      write(fd, "ok\n", 3);
      sprintf(pfk, "pfk %d\n", fd);
      send_to_graphic(pfk, server);
      create_egg(fd, server);
      hand->fork_flag = 1;
    }
  else if (hand->fork_flag == 1)
    {
      if ((hand = get_AI(fd, server)) == NULL)
	return (FALSE);
      sprintf(pfk, "enw %d %d %d %d\n", -hand->socket, hand->socket,
	      hand->posX, hand->posY);
      send_to_graphic(pfk, server);
      hand->fork_flag = 0;
    }
  return (TRUE);
}
