/*
** init_sdl.c for  in /home/chatea_s/project/unix/lemipc/display
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 20:09:29 2014 Sylvain Chateau
** Last update Sun Mar 30 19:54:27 2014 edouard mansuy
*/

#include "display.h"

int	prepare_window(t_display *display)
{
  if (SDL_FillRect(display->screen, NULL, SDL_MapRGB(display->screen->format,
						     0, 0, 0)) == -1)
    {
      fprintf(stderr, "SDL_FillRect %s\n", SDL_GetError());
      return (0);
    }
  if (!draw_vertical(display) || !draw_horizontal(display))
    return (0);
  return (1);
}

int	init_sdl(t_display *display)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  if ((display->screen = SDL_SetVideoMode(606, 606, 32, SDL_HWSURFACE))
      == NULL)
    {
      fprintf(stderr, "SDL_SetVideoMode: %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Lemipc", NULL);
  return (1);
}
