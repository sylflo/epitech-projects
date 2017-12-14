/*
** canonic_mode.c for  in /home/chatea_s/PSU_2013_myscript
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Feb 18 13:47:45 2014 Sylvain Chateau
** Last update Sun Mar  2 21:47:57 2014 Sylvain Chateau
*/

#include "my_script.h"

void	child(int sig)
{
  if (sig == SIGCHLD)
    g_pid = -1;
}

int	mode_no_canon(int fd)
{
  t	term;

  if (tcgetattr(fd, &term))
    {
      perror("in mode_no_canon tcgetattr");
      return (-1);
    }
  term.c_lflag &= ~(ICANON | ISIG | ECHO);
  if (tcsetattr(fd, TCSANOW, &term))
    {
      perror("in mode_no_canon tcsetattr");
      return (-1);
    }
  return (0);
}

int	mode_canon(int fd)
{
  t	term;

  if (tcgetattr(fd, &term))
    {
      perror("in mode_no_canon tcgetattr");
      return (-1);
    }
  term.c_lflag |= (ICANON | ISIG | ECHO);
  if (tcsetattr(fd, TCSANOW, &term))
    {
      perror("in mode_no_canon tcsetattr");
      return (-1);
    }
  return (0);
}
