/*
** write_on_server.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jun 30 14:11:50 2014
** Last update Sun Jul 13 23:41:28 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

void	write_on_server(char *cmd, int fd, int num_resources, t_server *server)
{
  char	id_char[10];
  char	num_resources_char[10];

  sprintf(id_char, "%d", fd);
  sprintf(num_resources_char, "%d", num_resources);
  strcpy(server->ln.response, cmd);
  strcat(server->ln.response, id_char);
  strcat(server->ln.response, " ");
  strcat(server->ln.response, num_resources_char);
  strcat(server->ln.response, "\n");
  send_to_graphic(server->ln.response, server);
}

void	call_write_server(char *cmd, int fd, int ret, t_server *server)
{
  char	cmd_pin[10] = {"pin "};
  char	cmd_bct[10] = {"bct "};
  char	fd_char[10];
  char	posX_char[10];
  char	posY_char[10];

  memset(server->ln.response, 0, 2048);
  write_on_server(cmd, fd, ret, server);
  sprintf(fd_char, "%d", fd);
  strcat(cmd_pin, fd_char);
  strcat(cmd_pin, "\n");
  pin_func(cmd_pin, server);
  send_to_graphic(server->ln.response, server);
  sprintf(posX_char, "%d", get_AI(fd, server)->posX);
  sprintf(posY_char, "%d", get_AI(fd, server)->posY);
  strcat(cmd_bct, posX_char);
  strcat(cmd_bct, " ");
  strcat(cmd_bct, posY_char);
  strcat(cmd_bct, "\n");
  bct_func(cmd_bct, server);
  send_to_graphic(server->ln.response, server);
}

void	write_begin(t_server *server)
{
  printf("Listening on port %d..\n", server->ln.port);
  printf("Configuration : Max(%d) WorldX(%d) WorldY(%d) T(%d)\n",
	 server->ln.allow_client, server->ln.width, server->ln.height,
	 server->ln.delay);
}
