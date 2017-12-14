/*
** dump.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Mar 27 16:30:36 2014 Sylvain Chateau
** Last update Sun Mar 30 19:38:52 2014 edouard mansuy
*/

#include <unistd.h>
#include <sys/ipc.h>
#include "display.h"

int		manage_event(int key, t_display *display)
{
  int		loop;
  SDL_Event	event;
  char		*map;

  loop = 1;
  while (loop)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	loop = 0;
      if ((map = get_map(key)) == NULL)
	return (0);
      if (!prepare_window(display))
      	return (EXIT_FAILURE);
      print_map(map);
      if (!draw_map(display, map))
	return (0);
      printf("\n");
      if (usleep(900000) == -1)
	return (0);
    }
  return (1);
}

int		main(void)
{
  int		key;
  t_display	display;

  memset(&display, 0, sizeof(t_display));
  if (!init_sdl(&display))
    return (EXIT_FAILURE);
  key = ftok("/dev", 0);
    if (!prepare_window(&display))
    return (EXIT_FAILURE);
  if (!manage_event(key, &display))
    return (EXIT_FAILURE);
  if (SDL_Flip(display.screen) == -1)
    {
      fprintf(stderr, "SDL_Flip %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_Quit();
  return (EXIT_SUCCESS);
}
