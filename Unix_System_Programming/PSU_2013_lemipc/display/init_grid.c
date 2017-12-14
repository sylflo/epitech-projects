/*
** init_grid.c for  in /home/chatea_s/project/unix/lemipc/display
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 20:11:19 2014 Sylvain Chateau
** Last update Sat Mar 29 20:28:59 2014 Sylvain Chateau
*/

#include "display.h"

int	init_draw_vertical(t_display *display)
{
  int	i;

  i = -1;
  while (++i < 5)
    {
      display->rect_vert[i]  = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, 660, 32,
						    0, 0, 0, 0);
      if (display->rect_vert[i] == NULL)
	{
	  fprintf(stderr, "SDL_CreateRGBSurface %s\n", SDL_GetError());
	  return (0);
	}
    }
  display->pos.x = 101;
  display->pos.y = 0;
  return (1);
}

int	draw_vertical(t_display *display)
{
  int	i;

  if (!init_draw_vertical(display))
    return (0);
  i = -1;
  while (++i < 5)
    {
      if (SDL_FillRect(display->rect_vert[i], NULL,
		       SDL_MapRGB(display->screen->format, 255, 255, 255))
	  == -1)
	{
	  fprintf(stderr, "SDL_FillRect %s\n", SDL_GetError());
	  return (0);
	}
      if (SDL_BlitSurface(display->rect_vert[i], NULL,
			  display->screen, &(display->pos)) < 0)
	{
	  fprintf(stderr, "SDL_BLitSurface %s\n", SDL_GetError());
	  return (0);
	}
      display->pos.x += 101;
    }
  return (1);
}

int	init_draw_horizontal(t_display *display)
{
  int	i;

  i = -1;
  while (++i < 5)
    {
      display->rect_hor[i]  = SDL_CreateRGBSurface(SDL_HWSURFACE, 660, 1, 32,
						   0, 0, 0, 0);
      if (display->rect_hor[i] == NULL)
	{
	  fprintf(stderr, "SDL_CreateRGBSurface %s\n", SDL_GetError());
	  return (0);
	}
    }
  display->pos.x = 0;
  display->pos.y = 101;
  return (1);
}

int	draw_horizontal(t_display *display)
{
  int	i;

  if (!init_draw_horizontal(display))
    return (0);
  i = -1;
  while (++i < 5)
    {
      if (SDL_FillRect(display->rect_hor[i], NULL,
		       SDL_MapRGB(display->screen->format, 255, 255, 255))
	  == -1)
	{
	  fprintf(stderr, "SDL_FillRect %s\n", SDL_GetError());
	  return (0);
	}
      if (SDL_BlitSurface(display->rect_hor[i], NULL,
			  display->screen, &(display->pos)) < 0)
	{
	  fprintf(stderr, "SDL_BLitSurface %s\n", SDL_GetError());
	  return (0);
	}
      display->pos.y += 101;
    }
  return (1);
}
