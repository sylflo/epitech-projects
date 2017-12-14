/*
** convert_timeval.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jul  7 21:08:40 2014
** Last update Sun Jul 13 19:15:24 2014 
*/

#include <sys/time.h>

double	convert_to_micro(struct timeval *t)
{
  return (((double) t->tv_sec * 1000000) + (double)t->tv_usec);
}
