/*
** command.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Wed Jun 25 18:02:08 2014
** Last update Sun Jul 13 19:27:24 2014 
*/

#include <unistd.h>
#include "server.h"
#include "cmd_graphic.h"

int	command_graphic(char *buffer, t_server *server)
{
  int	(*command_func[8])(char *, t_server *);
  char	*command[9] = {"msz", "sgt", "bct ", "mct", "tna", "ppo", "plv",
		       "pin ", "sst "};
  int	i;

  i = 0;
  command_func[0] = &msz_func;
  command_func[1] = &sgt_func;
  command_func[2] = &bct_func;
  command_func[3] = &mct_func;
  command_func[4] = &tna_func;
  command_func[5] = &ppo_func;
  command_func[6] = &plv_func;
  command_func[7] = &pin_func;
  command_func[8] = &sst_func;
  command_func[9] = NULL;
  while (i < 9 && strncmp(buffer, command[i], strlen(command[i])))
    i++;
  if (i < 9)
    return (command_func[i](buffer, server));
  memset(server->ln.response, 0, 2048);
  strcpy(server->ln.response, "suc\n");
  return (-4);
}

void	close_fd(int fd, t_select *s_select, t_server *server)
{
  printf("Deleting player %d\n", fd);
  destroy(get_AI(fd, server)->list);
  free(get_AI(fd, server)->list);
  del_ia(fd, server);
  close(fd);
  FD_CLR(fd, &s_select->master);
}

int		exec_command(char *buffer, int fd, t_select *s_select,
			     t_server *server)
{
  int		ret;
  t_trantorian *AI;

  AI = get_AI(fd, server);
  if (AI && AI->is_graphic == 1)
    {
      if ((ret = command_graphic(buffer, server)) == FALSE)
	close_fd(fd, s_select, server);
      if (ret == -2)
	{
	  memset(server->ln.response, 0, 2048);
	  strcpy(server->ln.response, "sbp\n");
	}
    }
  if (get_AI(fd, server) != NULL && get_AI(fd, server)->is_graphic == 0)
    {
      if (first_command(buffer, fd, server) == -1)
	{
	  write(fd, "ko\n", 3);
	  close_fd(fd, s_select, server);
	  return (FALSE);
	}
    }
  return (TRUE);
}
