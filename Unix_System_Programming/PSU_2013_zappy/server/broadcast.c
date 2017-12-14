/*
** broadcast.c for zappy in /home/couder_a/Depot/PSU/git/zappy/broadcast
**
** Made by Arthur Coudert
** Login   <couder_a@epitech.net>
**
** Started on  Sun Jul 13 02:22:51 2014 Arthur Coudert
** Last update Sun Jul 13 21:29:00 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "server.h"

void		find_vec_dir(t_trantorian *p, double *x2, double *y2)
{
  *x2 = 0;
  *y2 = 0;
  if (p->dir == NORD)
    *y2 = -1;
  else if (p->dir == EST)
    *x2 = -1;
  else if (p->dir == SUD)
    *y2 = 1;
  else
    *x2 = 1;
}

int	find_case_for_angle(double angle)
{
  int	ret;

  if (angle >= 18.5 && angle < 71.5)
    ret = 8;
  else if (angle >= 71.5 && angle < 108.5)
    ret = 7;
  else if (angle >= 108.5 && angle < 161.5)
    ret = 6;
  else if (angle >= 161.5 && angle < 198.5)
    ret = 5;
  else if (angle >= 198.5 && angle < 251.5)
    ret = 4;
  else if (angle >= 251.5 && angle < 288.5)
    ret = 3;
  else if (angle >= 288.5 && angle < 341.5)
    ret = 2;
  else
    ret = 1;
  return (ret);
}

int		calc_case(t_trantorian *p1, t_trantorian *p2, double px2,
			  double py2)
{
  double	angle;
  double	tmp1;
  double	tmp2;
  double	x1;
  double	x2;
  double	y1;
  double	y2;

  x1 = (double)(p1->posX) - px2;
  y1 = (double)(p1->posY) - py2;
  find_vec_dir(p2, &x2, &y2);
  tmp1 = (x1 * x2) + (y1 * y2);
  tmp2 = sqrt(pow(x1, 2.0) + pow(y1, 2.0)) * sqrt(pow(x2, 2.0) + pow(y2, 2.0));
  angle = acos(tmp1 / tmp2);
  angle = 180.0 * (angle)/ M_PI;
  if (p1->posY > py2)
    angle = 180 + (180 - angle);
  return (find_case_for_angle(angle));
}

int	find_case_for_dest(t_trantorian *p1, t_trantorian *p2,
			   t_server *serv)
{
  int	x2;
  int	y2;
  int	dx;
  int	dy;

  dx = p2->posX - p1->posX;
  dy = p2->posY - p1->posY;
  x2 = p2->posX;
  y2 = p2->posY;
  if (abs(dx) > (serv->ln.width / 2))
    {
      if (dx < 0)
  	x2 = serv->ln.width + p2->posX;
      else
  	x2 = -(serv->ln.width - p2->posX);
    }
  if (abs(dy) > (serv->ln.height / 2))
    {
      if (dy < 0)
  	y2 = serv->ln.height + p2->posY;
      else
  	y2 = -(serv->ln.height - p2->posY);
    }
  return (calc_case(p1, p2, (double)x2, (double)y2));
}

int		broadcast_func(char *buffer, int fd, t_server *server)
{
  t_trantorian	*ai;
  char		response[strlen(buffer) + 100];
  char		cpy_buf[strlen(buffer) + 100];
  int		posCase;

  strcpy(cpy_buf, &buffer[strlen("broadcast ")]);
  ai = server->ln.AI;
  while (ai)
    {
      sprintf(response, "message 0, %s\n", cpy_buf);
      if (ai->posX == get_AI(fd, server)->posX &&
	  ai->posY == get_AI(fd, server)->posY
	  && ai->socket != get_AI(fd, server)->socket)
	write(ai->socket, response, strlen(response));
      else if (ai->socket != get_AI(fd, server)->socket)
	{
	  posCase = find_case_for_dest(get_AI(fd, server), ai, server);
	  sprintf(response, "message %d, %s\n", posCase, cpy_buf);
	  write(ai->socket, response, strlen(response));
	}
      memset(response, 0, strlen(buffer) + 100);
      ai = ai->next;
      send_broadcast(server, cpy_buf, fd);
    }
  return (TRUE);
}
