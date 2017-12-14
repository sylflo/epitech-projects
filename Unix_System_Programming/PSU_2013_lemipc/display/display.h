/*
** display.h for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Fri Mar 28 21:43:53 2014 Sylvain Chateau
** Last update Sun Mar 30 19:52:42 2014 edouard mansuy
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

# include <SDL/SDL.h>

typedef struct s_display
{
  SDL_Surface	*screen;
  SDL_Surface	*rect_vert[5];
  SDL_Surface	*rect_hor[5];
  SDL_Surface	*square_one;
  SDL_Surface	*square_two;
  SDL_Rect	pos;
}		t_display;

/*
** draw_map.c
*/

int		draw_square_red(t_display *, int);
int		draw_square_green(t_display *, int);
int		draw_map(t_display *, char *);

/*
** init_grid.c
*/

int		init_draw_vertical(t_display *);
int		draw_vertical(t_display *);
int		init_draw_horizontal(t_display *);
int		draw_horizontal(t_display *);

/*
** init_sdl.c
*/

int		prepare_window(t_display *);
int		init_sdl(t_display *);

/*
** main.c
*/

int		manage_event(int, t_display *);

/*
** map_and_pos.c
*/

char		*get_map(int);
void		print_map(char *);
void		get_pos(t_display *, int);

#endif /* !DISPLAY_H_*/
