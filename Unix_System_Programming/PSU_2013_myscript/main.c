/*
** main.c for  in /home/chatea_s/project/unix/my_script
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jan 30 18:49:14 2014 Sylvain Chateau
** Last update Fri Feb 28 10:04:15 2014 Sylvain Chateau
*/

#include "my_script.h"

int		main(int argc, char **argv)
{
  t_script	script;

  memset(&script, 0, sizeof(t_script));
  script.file = "typescript";
  parse_arg(argc, argv, &script);
  if (exec(&script) == -1)
    return(EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
