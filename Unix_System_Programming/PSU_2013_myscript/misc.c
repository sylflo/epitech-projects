/*
** misc.c for  in /home/chatea_s/PSU_2013_myscript
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Feb 18 13:45:59 2014 Sylvain Chateau
** Last update Fri Feb 28 10:13:04 2014 Sylvain Chateau
*/

#include "my_script.h"
#include <time.h>

int	my_dup2(int oldfd, int newfd)
{
  int	ret;

  if ((ret = dup2(oldfd, newfd)) == -1)
    {
      perror("dup2");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	my_write(int fd, char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    {
      perror("write");
      exit(-1);
    }
}

char		*get_time()
{
  time_t	current_time;
  char		*c_time_string;

  current_time = time(NULL);
  if (current_time == ((time_t)-1))
    {
      perror("time");
      exit(-1);
    }
  c_time_string = ctime(&current_time);
  if (c_time_string == NULL)
    {
      perror("ctime");
      return (NULL);
    }
  return (c_time_string);
}

void	parse_arg(int argc, char **argv, t_script *script)
{
  int	i;

  i = 0;
  while (++i < argc)
    {
      if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "-append"))
	script->append = 1;
      else
	script->file = argv[i];
    }
}
