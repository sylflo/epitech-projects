/*
** draw_map.c for  in /home/chatea_s/project/unix/lemipc/display
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 20:12:31 2014 Sylvain Chateau
** Last update Sat Mar 29 20:12:58 2014 Sylvain Chateau
*/

#include "display.h"

int	draw_square_red(t_display *display, int i)
{
  display->square_one  = SDL_CreateRGBSurface(SDL_HWSURFACE, 100, 100, 32,
						 0, 0, 0, 0);
  if (display->square_one == NULL)
    {
      fprintf(stderr, "SDL_CreateRGBSurface %s\n", SDL_GetError());
      return (0);
    }
  if (SDL_FillRect(display->square_one, NULL,
		   SDL_MapRGB(display->screen->format, 255, 0, 0))
      == -1)
    {
      fprintf(stderr, "SDL_FillRect %s\n", SDL_GetError());
      return (0);
    }
  get_pos(display, i);
  if (SDL_BlitSurface(display->square_one, NULL,
		      display->screen, &(display->pos)) < 0)
    {
      fprintf(stderr, "SDL_BLitSurface %s\n", SDL_GetError());
      return (0);
    }
  return (1);
}

int	draw_square_green(t_display *display, int i)
{
  display->square_two  = SDL_CreateRGBSurface(SDL_HWSURFACE, 100, 100, 32,
						 0, 0, 0, 0);
  if (display->square_two == NULL)
    {
      fprintf(stderr, "SDL_CreateRGBSurface %s\n", SDL_GetError());
      return (0);
    }
  if (SDL_FillRect(display->square_two, NULL,
		   SDL_MapRGB(display->screen->format, 0, 255, 0))
      == -1)
    {
      fprintf(stderr, "SDL_FillRect %s\n", SDL_GetError());
      return (0);
    }
  get_pos(display, i);
  if (SDL_BlitSurface(display->square_two, NULL,
		      display->screen, &(display->pos)) < 0)
    {
      fprintf(stderr, "SDL_BLitSurface %s\n", SDL_GetError());
      return (0);
    }
  return (1);
}

int	draw_map(t_display *display, char *map)
{
  int	i;

  i = -1;
  while (map[++i])
    {
      if (map[i] == '1')
	{
	  if (!draw_square_red(display, i))
	    return (0);
	}
      if (map[i] == '2')
	{
	  if (!draw_square_green(display, i))
	    return (0);
	}
      if (SDL_Flip(display->screen) == -1)
	{
	  fprintf(stderr, "SDL_Flip %s\n", SDL_GetError());
	  return (EXIT_FAILURE);
	}
    }
  return (1);
}
