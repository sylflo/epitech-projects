/*
** elevate.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jun 30 15:36:41 2014
** Last update Sat Jul 12 20:35:08 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

void	write_end_incantation(t_trantorian *hand, t_server *server)
{
  write_bct_and_change_map(hand, server);
  write_cmd_pie(hand, server, "1");
  write_cmd_plv(hand, server);
}

void		write_on_AI_same_case(t_trantorian *hand, char *msg,
				      t_server *server)
{
  t_trantorian	*loop;

  loop = server->ln.AI;
  while (loop)
    {
      if (hand->posX == loop->posX && hand->posY == loop->posY)
	write(loop->socket, msg, strlen(msg));
      loop = loop->next;
    }
}

void	incantation_fail(t_server *server, int fd)
{
  if (get_AI(fd, server)->is_incantation == 1)
    {
      write_cmd_pie(get_AI(fd, server), server, "0");
      get_AI(fd, server)->is_incantation = 0;
    }
  write_on_AI_same_case(get_AI(fd, server), "ko\n", server);
}

void	first_in_incantation(t_server *server, int fd)
{
  write(get_AI(fd, server)->socket, "elevation en cours\n",
	strlen("elevation en cours\n"));
  write_pic(get_AI(fd, server), server);
  get_AI(fd, server)->is_incantation = 1;

}

int	incantation_func(__attribute__((unused))char *buf, int fd,
			 t_server *server)
{
  char	level[100] = {"niveau actuel : "};
  char	level_char[10] = {0};

  memset(server->ln.response, 0, 2048);
  if (!get_AI(fd, server))
    return (FALSE);
  if (get_AI(fd, server)->level == 8)
    return (FALSE);
  if (check_level_case(get_AI(fd, server), server) == FALSE)
    {
      incantation_fail(server, fd);
      return (FALSE);
    }
  if (get_AI(fd, server)->is_incantation == 0)
    {
      first_in_incantation(server, fd);
      return (TRUE);
    }
  write_end_incantation(get_AI(fd, server), server);
  sprintf(level_char, "%d", get_AI(fd, server)->level);
  strcat(level, level_char);
  strcat(level, "\n");
  write_on_AI_same_case(get_AI(fd, server), level, server);
  get_AI(fd, server)->is_incantation = 0;
  return (TRUE);
}
