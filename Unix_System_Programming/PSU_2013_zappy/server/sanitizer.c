/*
** sanitizer.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jul  7 18:26:42 2014
** Last update Fri Jul 11 16:41:43 2014 
*/

#include	"sanitizer.h"

void	sanitizer(char *buffer)
{
  int	buflen;

  buflen = strlen(buffer);
  if (buflen > 2)
    {
      if (buffer[buflen - 2] == '\r')
	buffer[buflen - 2] = 0;
      else if (buffer[buflen - 1] == '\n')
	buffer[buflen - 1] = 0;
    }
}
