/*
** misc_incantation.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul 12 20:34:54 2014
** Last update Sun Jul 13 21:52:29 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int		nb_players_same_level_func(t_trantorian *hand,
					   t_server *server)
{
  int		nb_players;
  t_trantorian	*loop;

  nb_players = 0;
  loop = server->ln.AI;
  while (loop)
    {
      if (loop->is_graphic == 2)
	{
	  if (hand->posX == loop->posX && hand->posY == loop->posY &&
	      hand->level == loop->level)
	    nb_players++;
	}
      loop = loop->next;
    }
  return (nb_players);
}

void		write_pic(t_trantorian *hand, t_server *server)
{
  t_trantorian	*loop;
  char		cmd_pic[100] = {0};
  char		id_char[10];

  sprintf(cmd_pic, "pic %d %d %d", hand->posX, hand->posY, hand->level);
  loop = server->ln.AI;
  while (loop)
    {
      if (hand->posX == loop->posX && hand->posY == loop->posY)
	{
	  sprintf(id_char, "%d", hand->socket);
	  strcat(cmd_pic, " ");
	  strcat(cmd_pic, id_char);
	}
      loop = loop->next;
    }
  strcat(cmd_pic, "\n");
  send_to_graphic(cmd_pic, server);
}

void	write_cmd_pie(t_trantorian *hand, t_server *server, char result[1])
{
  char	cmd_pie[100] = {"pie "};

  sprintf(cmd_pie, "pie %d %d %s\n", hand->posX, hand->posY,
	  result);
  send_to_graphic(cmd_pie, server);
}

void		write_cmd_plv(t_trantorian *hand, t_server *server)
{
  t_trantorian	*loop;
  char		cmd_plv[100];
  char		level_char[10];
  char		id_char[10];

  loop = server->ln.AI;
  while (loop)
    {
      if (hand->posX == loop->posX && hand->posY == loop->posY)
	{
	  memset(cmd_plv, 0, 100);
	  loop->level++;
	  sprintf(id_char, "%d", loop->socket);
	  sprintf(level_char, "%d", loop->level);
	  strcpy(cmd_plv, "plv ");
	  strcat(cmd_plv, id_char);
	  strcat(cmd_plv, " ");
	  strcat(cmd_plv, level_char);
	  strcat(cmd_plv, "\n");
	  send_to_graphic(cmd_plv, server);
	}
      loop = loop->next;
    }
}

void	write_bct_and_change_map(t_trantorian *hand, t_server *server)
{
  int	tab_level[] = {1, 2, 3, 4, 5, 6, 7, 8};
  void	(*change_map[7])(t_trantorian *hand, t_server *);
  int	i;

  i = -1;
  change_map[0] = &change_map_level_one;
  change_map[1] = &change_map_level_two;
  change_map[2] = &change_map_level_three;
  change_map[3] = &change_map_level_four;
  change_map[4] = &change_map_level_five;
  change_map[5] = &change_map_level_six;
  change_map[6] = &change_map_level_seven;
  change_map[7] = NULL;
  while (++i < 7)
    if (hand->level == tab_level[i])
      change_map[i](hand, server);
}
