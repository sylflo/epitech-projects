/*
** my_forkpty.c for  in /home/chatea_s/project/unix/my_script
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Fri Jan 31 14:26:02 2014 Sylvain Chateau
** Last update Fri Feb 28 10:04:03 2014 Sylvain Chateau
*/

#include "my_script.h"

char		*my_ptsname(int fd)
{
  int		nb;
  int		size;
  static char	name[50];

  if (ioctl(fd, TIOCGPTN, &nb))
    {
      perror("in my_ptsname ioctl");
      exit(EXIT_FAILURE);
    }
  size = sprintf(name, "/dev/pts/%d", nb);
  if (size == -1)
    {
      perror("in my_ptsname sprintf");
      exit(EXIT_FAILURE);
    }
  name[size] = '\0';
  return (name);
}

int	my_unlockpt(int fd)
{
#ifdef TIOCSPTLCK
  int	unlock;

  unlock = 0;
  if (ioctl(fd, TIOCSPTLCK, &unlock))
    return (-1);
#endif
  return (0);
}

int	my_openpty(t_script *script, const t *termp, const w *winp)
{
  if ((script->fd_master = getpt()) == -1)
    {
      perror("getpt: ");
      return (-1);
    }
  if (my_unlockpt(script->fd_master) == -1)
    return (-1);
  script->name_slave = my_ptsname(script->fd_master);
  if ((script->fd_slave = open(script->name_slave, O_RDWR)) == -1)
    exit(EXIT_FAILURE);
  if (termp)
    {
      if (tcsetattr(script->fd_slave, TCSANOW, termp))
	perror("in my_openpty tcsetattr");
    }
  if (winp)
    {
      if (ioctl(script->fd_slave, TIOCSWINSZ, winp))
	perror("in my_openpty ioctl");
    }
  return (0);
}

int	my_login_tty(int fd)
{
  if (setsid() == -1)
    {
      perror("in my_login_tty setsid");
      exit(EXIT_FAILURE);
    }
  if (ioctl(fd, TIOCSCTTY, NULL) == -1)
    {
      perror("in my_login_tty ioctl");
      exit(EXIT_FAILURE);
    }
  my_dup2(fd, 0);
  my_dup2(fd, 1);
  my_dup2(fd, 2);
  close(fd);
  return (0);
}

pid_t	my_forkpty(t_script *script, const t *termp, const w *winp)
{
  pid_t	pid;

  if (my_openpty(script, termp, winp) == -1)
    return (-1);
  pid = fork();
  if (pid == -1)
    {
      perror("in my_forkpty fork");
      return (-1);
    }
  if (pid == 0)
    {
      my_login_tty(script->fd_slave);
      close(script->fd_master);
    }
  return (pid);
}
