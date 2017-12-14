/*
** realloc.c for realloc in /home/storm/projects/C_projects/my_malloc/project/god
**
** Made by Julian Caille
** Login <caille_j@epitech.net>
**
** Started on  Sun Feb 16 17:45:17 2014 Julian Caille
** Last update Sun Feb 16 19:25:51 2014 Julian Caille
*/

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  void		*new;
  size_t	break_tmp;

  if (g_malloc.node)
    {
      break_tmp = g_break;
      g_break = break_tmp;
    }
  if (!ptr)
    {
      if (size > 0)
	return (malloc(size));
      return (NULL);
    }
  if (size < ((t_meta *)ptr - 1)->size)
    return (ptr);
  else if (size >= ((t_meta *)ptr - 1)->size)
    {
      new = malloc(size);
      new = memcpy(new, ptr, ((t_meta *)ptr - 1)->size);
      free(ptr);
    }
  return (new);
}
