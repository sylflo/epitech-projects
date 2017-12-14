/*
** free.c for free in /home/storm/projects/C_projects/my_malloc/project/god
**
** Made by Julian Caille
** Login <caille_j@epitech.net>
**
** Started on  Sun Feb 16 17:46:48 2014 Julian Caille
** Last update Sun Feb 16 21:53:11 2014 Sylvain Chateau
*/

#include "malloc.h"

void		free_heap(size_t rank)
{
  g_malloc.node = g_malloc.freerank[rank];
  if (g_malloc.node)
    {
      if (g_malloc.node + g_malloc.node->size == sbrk(0))
	{
	  sbrk(-g_malloc.node->size);
	  g_break -= g_malloc.node->size;
	}
      g_malloc.freerank[rank] = NULL;
      g_malloc.mallocrank[rank] = NULL;
    }
}

void		free(void *ptr)
{
  int		rank;

  if (ptr)
    {
      rank = calc_rank(((t_meta *)ptr - 1)->size + sizeof(t_meta));
      g_malloc.freerank[rank] = (t_meta *)ptr - 1;
      free_heap(calc_rank(((t_meta *)ptr - 1)->size + sizeof(t_meta)));
      memset(ptr, '\0', g_malloc.node->size);
    }
}
