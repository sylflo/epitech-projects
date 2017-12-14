/*
** script.c for  in /home/chatea_s/PSU_2013_myscript
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Feb 18 13:47:03 2014 Sylvain Chateau
** Last update Sun Mar  2 21:57:42 2014 Sylvain Chateau
*/

#include "my_script.h"

int	write_typescript(t_script *script, int option)
{
  if (option == 0)
    {
      if (printf("Script started, file is %s\n", script->file) == -1)
	{
	  perror("printf");
	  exit(-1);
	}
      my_write(script->fd_file, "Script started on ");
      my_write(script->fd_file, get_time());
    }
  else
    {
      if (printf("Script done, file is %s\n", script->file) == -1)
	{
	  perror("printf");
	  exit(-1);
	}
      my_write(script->fd_file, "\nScript done on ");
      my_write(script->fd_file, get_time());
    }
  return (0);
}

void		loop_script(t_script *script, fd_set set)
{
  fd_set	temp;
  int		ret_select;
  char		buffer[4096];

  g_pid = script->pid;
  while (g_pid != -1)
    {
      memcpy(&temp, &set, sizeof(temp));
      ret_select = select(script->fd_master + 1, &temp, NULL, NULL, NULL);
      if (ret_select != -1 && FD_ISSET(0, &temp))
	{
	  ret_select = read(0, buffer, 4096);
	  write(script->fd_master, buffer, ret_select);
	}
      else if (ret_select != -1 && FD_ISSET(script->fd_master, &temp))
	{
	  ret_select = read(script->fd_master, buffer, 4096);
	  write(script->fd_file, buffer, ret_select);
	  write(1, buffer, ret_select);
	}
    }
}

int	init_my_script(fd_set *set, t_script *script)
{
  if (signal(SIGCHLD, child) == SIG_ERR)
    {
      perror("signal");
      return (-1);
    }
  FD_ZERO(set);
  FD_SET(0, set);
  FD_SET(script->fd_master, set);
  return (0);
}

int		my_script(t_script *script)
{
  fd_set	set;

  if (init_my_script(&set, script) == -1)
    return (-1);
  if (mode_no_canon(0) == -1)
    return (-1);
  if (script->append == 1)
    script->fd_file = open(script->file, O_APPEND | O_CREAT | O_WRONLY, 0644);
  else
    script->fd_file = open(script->file, O_TRUNC | O_CREAT | O_WRONLY, 0644);
  if (script->fd_file == -1)
    {
      perror("in my_script open");
      return (-1);
    }
  if (write_typescript(script, 0) == -1)
    return(-1);
  loop_script(script, set);
  if (write_typescript(script, 1) == -1)
    return(-1);
  if (mode_canon(0) == -1)
    return (-1);
  return (0);
}

int	exec(t_script *script)
{
  char	*name_shell;
  t	term;
  w	win;

  if (ioctl(0, TIOCGWINSZ, &win) == -1 || tcgetattr(0, &term) == -1)
    {
      perror("in exec function ioctl or tcgettar");
      return (-1);
    }
  script->pid = my_forkpty(script, &term, &win);
  name_shell = getenv("SHELL");
  if (!name_shell)
    name_shell = "/bin/sh";
  if (script->pid == -1)
    return (-1);
  if (script->pid)
    {
      if (my_script(script) == -1)
	return (-1);
    }
  else
    execlp(name_shell, name_shell, NULL);
  return (0);
}
