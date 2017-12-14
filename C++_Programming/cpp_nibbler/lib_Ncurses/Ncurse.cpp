// Ncurse.cpp for nibbler in /tmp/cpp_nibbler
//
// Made by maxime duboy
// Login   <duboy_m@epitech.net>
//
// Started on  Wed Apr  2 18:26:48 2014 maxime duboy
// Last update Sat Apr  5 17:22:41 2014 maxime duboy
//

#include <sys/ioctl.h>
#include "Ncurse.hpp"

bool		Ncurse::initWindow(const ILib::t_size size_win)
{
  int		pos_x;
  int		pos_y;

  initscr();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_RED, COLOR_YELLOW);
  curs_set(0);
  noecho();
  cbreak();
  pos_x = (LINES / 2) - ((size_win.width + 2) / 2);
  pos_y = (COLS / 2) - ((size_win.heigth + 2)/ 2);
  if ((int)size_win.heigth + pos_x > LINES || (int)size_win.width +pos_y > COLS)
    {
      endwin();
      std::cout << "Wrong terminal size" << std::endl;
      return (false);
    }
  if ((this->win = newwin(size_win.heigth + 2, size_win.width + 2,
			  pos_x, pos_y)) == NULL)
    {
      endwin();
      std::cout << "Wrong terminal size" << std::endl;
      return (false);
    }
  box(this->win, 0, 0);
  wrefresh(this->win);
  this->size_x = size_win.width + 3;
  this->size_y = size_win.heigth + 3;
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  return (true);
}

void	Ncurse::display(const std::vector<struct s_element> &list,
			const std::vector<struct s_element> &food, const int score)
{
  int	i;

  i = 0;
  del_ncu();
  if (this->size_x + this->pos_x > LINES || (this->size_y + this->pos_y > COLS))
    {
      endwin();
      std::cout << "Wrong terminal size" << std::endl;
      exit(0);
    }
  if ((this->win = newwin(this->size_y, this->size_x, this->pos_x, this->pos_y)) == NULL)
    {
      endwin();
      std::cout << "Wrong terminal size" << std::endl;
      exit(0);
    }
  draw_wall();
  mvprintw(0, 0, "Score : %d", score);
  while (i < (int)list.size())
    {
      if (list[i].type == ILib::SNAKE_HEAD)
	wattron(this->win, COLOR_PAIR(2));
      else
	wattron(this->win, COLOR_PAIR(1));
      mvwaddch(this->win, list[i].position.y + 1, list[i].position.x + 1, '#');
      wattroff(this->win, 2);
      i++;
    }
  i = 0;
  wattron(this->win, COLOR_PAIR(3));
  while (i < (int)food.size())
    {
      if (food[i].type == ILib::BLOCK)
	wattron(this->win, COLOR_PAIR(4));
      else
	wattron(this->win, COLOR_PAIR(3));
      mvwaddch(this->win, food[i].position.y + 1, food[i].position.x + 1, '#');
      wattroff(this->win, 3);
      wattroff(this->win, 4);
      i++;
    }
  wrefresh(this->win);
  refresh();
}

void		Ncurse::del_ncu() const
{
  draw_wall();
  wrefresh(this->win);
  delwin(this->win);
}

void		Ncurse::draw_wall() const
{
  int		x;
  int		y;

  wattron(this->win, COLOR_PAIR(4));
  x = -1;
  y = 0;
  while (++x != this->size_x + 3)
    mvwaddch(this->win, y, x, '*');
  x = -1;
  y = this->size_y - 1;
  while (++x != this->size_x + 3)
  mvwaddch(this->win, y, x, '*');
  x = 0;
  y = -1;
  while (++y != this->size_y + 3)
    mvwaddch(this->win, y, x, '*');
  x = this->size_x - 1;
  y = -1;
  while (++y != this->size_y + 3)
  mvwaddch(this->win, y, x, '*');
  wattroff(this->win, 4);
}

void		Ncurse::closeWindow() const
{
  clear();
  curs_set(1);
  delwin(this->win);
  endwin();
}

ILib::key	Ncurse::getEvent() const
{
  int		k;

  timeout(1);
  k =  getch();
  if (k == 'p')
    return (PAUSE);
  if (k == '1')
    return (LIB1);
  if (k == '2')
    return (LIB2);
  if (k == '3')
    return (LIB3);
  if (k == '\033')
    {
      getch();
      switch(getch()){

      case 65:
	return(UP);
      case 66:
	return(DOWN);
      case 67:
	return(RIGTH);
      case 68:
	return(LEFT);
      }
    }
  if (k == 27)
    return (QUIT);
  return (NONE);
}

extern "C"
{
  ILib	*create_lib()
  {
    return (new Ncurse());
  }
}
