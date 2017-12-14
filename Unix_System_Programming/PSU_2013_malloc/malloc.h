/*
** malloc.c for  in /home/chatea_s/project/unix/malloc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Feb  6 13:10:04 2014 Sylvain Chateau
** Last update Sun Feb 16 23:34:59 2014 Sylvain Chateau
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define FOUR_GB_MEM 32
#define EIGHT_GB_MEM 33

static size_t	g_break = -1;
struct s_malloc	g_malloc;

typedef struct	s_meta
{
  size_t	size;
  struct s_meta	*next;
}		t_meta;

typedef struct	s_malloc
{
  t_meta	*freerank[FOUR_GB_MEM];
  t_meta	*mallocrank[FOUR_GB_MEM];
  t_meta	*node;
}		t_malloc;

void		*check_exist(size_t size);
size_t		calc_rank(size_t size);
void		*heap_update(size_t size, t_meta *data, size_t enough);
void		*malloc(size_t size);
void		free_heap(size_t rank);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void            show_alloc_mem();

#endif /* MALLOC_H_ */
