/*
** liste_circ_function.h for  in /home/chatea_s/zappy/buffer_circ
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul  5 23:46:35 2014
** Last update Fri Jul 11 17:22:24 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

void	init_list(t_ring_buff *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->size = 0;
}

void			print(t_ring_buff *list)
{
  t_elem_ring_buff	*current;
  int			i;

  i = 0;
  current = list->begin;
  while (i < list->size)
    {
      printf ("%p - %s - %f\n", current, current->data, current->future_time);
      current = current->next;
      i++;
    }
  printf("\n");
}

char			*get_cmd(t_ring_buff *list, int pos)
{
  t_elem_ring_buff	*current;
  int			i;

  current = list->begin;
  i = 0;
  while (i < pos)
    {
      current = current->next;
      i++;
    }
  return (current->data);
}

void	destroy(t_ring_buff *list)
{
  while (list->size > 0)
    {
      if (list->size > 1)
	del_list_circ (list);
      else
	del_list_circ_unique(list);
    }
}
