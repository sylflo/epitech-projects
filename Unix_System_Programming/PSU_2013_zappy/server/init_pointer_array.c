/*
** command_2.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Thu Jun 26 16:42:09 2014 maxime duboy
** Last update Sat Jul 12 19:44:47 2014 maxime duboy
*/

#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "server.h"
#include "cmd_graphic.h"

void	init_command_func(t_server *server)
{
  server->ln.command_func[0] = &take_func;
  server->ln.command_func[1] = &drop_func;
  server->ln.command_func[2] = &inv_func;
  server->ln.command_func[3] = &move_func;
  server->ln.command_func[4] = &right_func;
  server->ln.command_func[5] = &left_func;
  server->ln.command_func[6] = &incantation_func;
  server->ln.command_func[7] = &see_func;
  server->ln.command_func[8] = &expulse_func;
  server->ln.command_func[9] = &fork_func;
  server->ln.command_func[10] = &broadcast_func;
  server->ln.command_func[11] = &connect_nbr_func;
}
