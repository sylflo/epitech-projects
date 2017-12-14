/*
** parsing.c for zappy in /home/duboy_m/zappy/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Thu Jun 19 20:21:34 2014 maxime duboy
** Last update Sun Jul 13 21:52:46 2014 
*/

#include	<stdio.h>
#include	"server.h"

static void	parse_n(char **av, t_server *server)
{
  int		index;
  int		i;

  i = 0;
  index = optind - 1;
  while (av[index] && av[index][0] != '-')
    {
      ++index;
      ++i;
    }
  if (i > 0)
    {
      verif_malloc(server, i);
      while (i > 0)
	{
	  --i;
	  --index;
	  server->ln.team_name[i] = av[index];
	  server->ln.allow_team[i] = 1;
 	}
    }
}

void	init_arg(t_server *server)
{
  server->ln.height = HEIGTH;
  server->ln.width = WIDTH;
  server->ln.port = PORT;
  server->ln.allow_client = ALLOW_CLIENT;
  server->ln.delay = DELAY;
  server->ln.AI = NULL;
  server->ln.team_name = NULL;
}

static int		matchPos(int opt)
{
  int			i;
  static const char	*str = "p:x:y:t:c";

  i = 0;
  if (opt >= 'a' && opt <= 'z')
    while (str[i])
      {
	if (str[i] == opt)
	  return i / 2;
	++i;
      }
  return -1;
}

int	parse_number_team(t_server *server)
{
  int	i;

  i = 0;
  if (server->ln.team_name)
    {
      while (server->ln.team_name[i])
	i++;
    }
  server->ln.nbr_team = i;
  return (i);
}

void	parse_arg(int argc, char **argv, t_server *server)
{
  int	opt;
  int	pos;
  int	tmp;

  init_arg(server);
  while ((opt = getopt(argc, argv, "p:x:y:c:t:n:")) != -1)
    {
      if ((pos = matchPos(opt)) != -1)
	{
	  if ((tmp = atoi(optarg)) > 0)
	    server->init.arg[pos] = tmp;
	  else
	    fprintf(stderr, "Wrong argument for -%c %s, -%c is set to: %d\n",
		    opt, optarg, opt, server->init.arg[pos]);
	}
      else if (opt == 'n')
	parse_n(argv, server);
    }
  parse_number_team(server);
  if (server->ln.nbr_team == 0)
    {
      fprintf(stderr, "ERROR: -n missing\n%s", USAGE);
      free_end(server);
      exit(EXIT_FAILURE);
    }
}
