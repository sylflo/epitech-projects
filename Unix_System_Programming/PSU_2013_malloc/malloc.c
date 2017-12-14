/*
** malloc.c for  in /home/chatea_s/project/unix/malloc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Feb  6 13:00:26 2014 Sylvain Chateau
** Last update Sun Feb 16 21:52:20 2014 Sylvain Chateau
*/

#include "malloc.h"

size_t		calc_rank(size_t size)
{
  size_t	rank;
  size_t	total;

  rank = 0;
  total = 1;
  while (total <= size)
    {
      total *= 2;
      rank++;
    }
  return (rank);
}

void		*check_exist(size_t size)
{
  int		rank;

  rank = calc_rank(size);
  g_malloc.node = g_malloc.freerank[rank];
  if (g_malloc.node)
    g_malloc.freerank[rank] = NULL;
  return (g_malloc.node);
}

void		*heap_update(size_t size, t_meta *meta, size_t enough)
{
  void		*ptr;
  int		temp;

  if (enough == 0)
    meta = sbrk(0) - g_break;
  else
    {
      temp = ((size + sizeof(t_meta)) / getpagesize());
      g_break = ++temp * getpagesize();
      meta = sbrk(g_break);
    }
  g_break -= (size + sizeof(t_meta));
  meta->size = size;
  ptr = (void*)meta;
  g_malloc.mallocrank[calc_rank(size + sizeof(t_meta))] = ptr;
  return ((t_meta *)ptr + 1);
}

void		*malloc(size_t size)
{
  t_meta	*meta;
  int		check_heap;

  if ((meta = check_exist(size + sizeof(t_meta))))
    return (meta + 1);
  else
    check_heap = g_break - (size + sizeof(t_meta));
  if (g_break != 0)
    {
      if (check_heap > 0)
	return (heap_update(size, meta, 0));
      else
	return (heap_update(size, meta, 1));
    }
  return (NULL);
}
