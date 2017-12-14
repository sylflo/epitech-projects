/*
** change_map_incantation.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul 12 20:29:00 2014
** Last update Sat Jul 12 20:30:05 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

void	change_stone_place(int nb_stones, int stones, t_trantorian *hand,
			   t_server *server)
{
  int	posCase;
  int	posCaseRand;
  int	posXrand;
  int	posYrand;
  int	i;

  i = -1;
  posCase = hand->posX + (server->ln.width * hand->posY);
  while (++i < nb_stones)
    {
      posXrand = rand() % server->ln.width;
      posYrand = rand() % server->ln.height;
      posCaseRand = posXrand + (server->ln.width * posYrand);
      server->ln.map[posCase].stones[stones]--;
      server->ln.map[posCaseRand].stones[stones]++;
      object_in_case(hand->posX, hand->posY, server);
      send_to_graphic(server->ln.response, server);
      object_in_case(posXrand, posYrand, server);
      send_to_graphic(server->ln.response, server);
    }
}

void	change_map_level_one(t_trantorian *hand, t_server *server)
{
  change_stone_place(1, 0, hand, server);
}

void	change_map_level_two(t_trantorian *hand, t_server *server)
{
  change_stone_place(1, 0, hand, server);
  change_stone_place(1, 1, hand, server);
  change_stone_place(1, 2, hand, server);
}

void	change_map_level_three(t_trantorian *hand, t_server *server)
{
  change_stone_place(2, 0, hand, server);
  change_stone_place(1, 2, hand, server);
  change_stone_place(2, 4, hand, server);
}

void	change_map_level_four(t_trantorian *hand, t_server *server)
{
  change_stone_place(1, 0, hand, server);
  change_stone_place(1, 1, hand, server);
  change_stone_place(2, 2, hand, server);
  change_stone_place(1, 4, hand, server);
}
