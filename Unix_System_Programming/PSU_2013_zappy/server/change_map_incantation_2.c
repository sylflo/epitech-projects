/*
** change_map_incantation_2.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul 12 20:30:30 2014
** Last update Sat Jul 12 20:31:00 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

void	change_map_level_five(t_trantorian *hand, t_server *server)
{
  change_stone_place(1, 0, hand, server);
  change_stone_place(2, 1, hand, server);
  change_stone_place(1, 2, hand, server);
  change_stone_place(3, 3, hand, server);
}

void	change_map_level_six(t_trantorian *hand, t_server *server)
{
  change_stone_place(1, 0, hand, server);
  change_stone_place(2, 1, hand, server);
  change_stone_place(3, 2, hand, server);
  change_stone_place(1, 4, hand, server);
}

void	change_map_level_seven(t_trantorian *hand, t_server *server)
{
  change_stone_place(2, 0, hand, server);
  change_stone_place(2, 1, hand, server);
  change_stone_place(2, 2, hand, server);
  change_stone_place(2, 3, hand, server);
  change_stone_place(2, 4, hand, server);
  change_stone_place(1, 5, hand, server);
}
