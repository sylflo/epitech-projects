/*
** showmem.c for showmem in /home/storm/projects/C_projects/my_malloc/project/god
**
** Made by Julian Caille
** Login <caille_j@epitech.net>
**
** Started on  Sun Feb 16 17:48:25 2014 Julian Caille
** Last update Sun Feb 16 21:52:08 2014 Sylvain Chateau
*/

#include "malloc.h"

void		show_alloc_mem()
{
  size_t	rank;
  size_t	tmp;

  tmp = g_break;
  g_break = tmp;
  rank = -1;
  printf("break : %p\n", sbrk(0));
  while (++rank < FOUR_GB_MEM)
    {
      g_malloc.node = g_malloc.mallocrank[rank];
      if (g_malloc.node)
	{
	  while (g_malloc.node)
	    {
	      printf("%p", g_malloc.node);
	      printf(" - %p", (g_malloc.node + g_malloc.node->size));
	      printf(" : %lu octets\n", g_malloc.node->size);
	      g_malloc.node = g_malloc.node->next;
	    }
	}
    }
}
