/*
** ins_and_del_circ_buf.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jul  7 21:11:59 2014
** Last update Sun Jul 13 17:56:38 2014 
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

int			ins_list_circ_empty(t_ring_buff *list, char *data,
					    t_server *server)
{
  t_elem_ring_buff	*new_elem;

  if ((new_elem = (t_elem_ring_buff *)malloc(sizeof(t_elem_ring_buff)))
      == NULL)
    {
      perror("malloc");
      exit(-1);
    }
  strcpy (new_elem->data, data);
  new_elem->time_action = find_time(data, server);
  new_elem->future_time = new_elem->time_action
    + convert_to_micro(&server->ln.current_time);
  new_elem->next = new_elem;
  list->begin = new_elem;
  list->end = new_elem;
  list->size++;
  return (0);
}

double			find_total_time_action(t_ring_buff *list)
{
  t_elem_ring_buff	*current;
  int			i;
  double		time_action_all;

  time_action_all = 0;
  i = 0;
  current = list->begin;
  while (i < list->size)
    {
      time_action_all += current->time_action;
      current = current->next;
      i++;
    }
  return (time_action_all);
}

int			ins_list_circ(t_ring_buff *list, t_elem_ring_buff
				      *courant, char *data, t_server *server)
{
  t_elem_ring_buff	*new_elem;

  if ((new_elem = (t_elem_ring_buff *)malloc(sizeof(t_elem_ring_buff)))
      == NULL)
    {
      perror("malloc");
      exit(-1);
    }
  strcpy (new_elem->data, data);
  new_elem->time_action = find_time(data, server);
  new_elem->future_time =  new_elem->time_action
    + convert_to_micro(&server->ln.current_time)
    + find_total_time_action(list);
  if (courant != list->end)
    return (-1);
  new_elem->next = courant->next;
  courant->next = new_elem;
  list->end = new_elem;
  list->size++;
  return (0);
}

int			del_list_circ(t_ring_buff *list)
{
  t_elem_ring_buff	*del_element;

  if (list->size < 2)
    return (-1);
  del_element = list->begin;
  list->begin = list->begin->next;
  list->end->next = list->begin;
  memset(del_element->data, 0, 500);
  free (del_element);
  list->size--;
  return (0);
}

int			del_list_circ_unique(t_ring_buff *list)
{
  t_elem_ring_buff	*del_elem;

  if (list->size != 1)
    return (-1);
  del_elem = list->begin;
  list->begin = NULL;
  list->end = NULL;
  memset(del_elem->data, 0, 500);
  free (del_elem);
  list->size--;
  return (0);
}
