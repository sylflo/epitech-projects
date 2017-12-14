/*
** map.h for zappy in /home/duboy_m/zappy/zappy/src
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Wed Jun 18 09:32:07 2014 maxime duboy
** Last update Sun Jul 13 23:41:41 2014 
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <getopt.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "ai.h"

#define USAGE "usage: ./zappy -p <port> -x <width> -y \
<height> -n <team name> -t <delay> -c <allow_client>\n"
#define HEIGTH		10
#define WIDTH		10
#define PORT		4242
#define ALLOW_CLIENT	1
#define DELAY		100

int	g_quit;

enum
  {
    TRUE = 0,
    FALSE = -1
  };

typedef struct	s_select
{
  fd_set	master;
  fd_set	read_fds;
  int		listener;
  int		fdmax;
}		t_select;

typedef struct		s_userServer
{
  int			port;
  int			width;
  int			height;
  int			delay;
  int			allow_client;
  char			**team_name;
  int			nbr_team;
  int			*allow_team;
  int			sockfd;
  char			response[2048];
  int			client_fd;
  int			fd_time;
  int			(*command_func[12])(char *, int, t_server *);
  struct timeval	exec_action;
  struct timeval	exec_death;
  struct timeval	current_time;
  struct s_case		*map;
  struct s_trantorian	*AI;
  t_select		s_select;
}			t_userServer;

typedef struct		s_initServer
{
  int			arg[5];
  char			**n;
  int			nbr_team;
  int			*allow_team;
  int			sockfd;
  char			response[2048];
  int			client_fd;
  int			fd_time;
  int			(*command_func[12])(char *, int, t_server *);
  struct timeval	exec_action;
  struct timeval	exec_death;
  struct timeval	current_time;
  struct s_case		*map;
  struct s_trantorian	*AI;
  t_select		s_select;
}			t_initServer;

typedef union	u_server
{
  t_initServer	init;
  t_userServer	ln;
}		t_server;

typedef struct	s_case
{
  int		food;
  int		stones[6];
}		t_case;

/*
** map.c
*/
int	full_map(t_server *server);
int	init_map(t_server *server);

/*
** server.c
*/
void	free_end(t_server *server);
void	intHandler();

/*
** parsing.c
*/
void	parse_arg(int ac, char**av, t_server *server);

/*
** do_select.c
*/
void	do_select(t_server *server, t_select *s_select);
void	loop_select(t_select *s_select, t_server *server);
void	quit_game(t_server *server);

/*
** create_server.c
*/
int	create_server(t_server *server);
int	fd_loop(t_select *s_select, t_server *server);

/*
** create_server_2.c
*/
int	func_accept(t_select *s_select, t_server *server);
int	func_send(t_select *s_select, char *buf, int i, int nbytes);

/*
** command.c
*/
int	exec_command(char *buf, int i, t_select *s_select, t_server *server);
int	command_graphic(char *buf, t_server *server);
void	close_fd(int fd, t_select *s_select, t_server *server);

/*
** commande_2.c
*/
int	check_if_team(char *buffer, t_trantorian *hand, t_server *server);
int	first_command(char *buffer, int fd, t_server *server);
int	send_to_graphic(char *msg, t_server *server);
int	command_AI(char *buffer, int fd, t_server *server);
int	inv_func(char *buffer, int fd, t_server *server);

/*
** write_on_server.c
*/
void	call_write_server(char *cmd, int fd, int ret, t_server *server);
void	write_on_server(char *cmd, int fd, int num_resources,
			t_server *server);
void	write_begin(t_server *server);

/*
** take_ia.c
*/
int	can_take(int obj, t_trantorian *hand, t_server *server);
int	take_item(char *token, int fd, t_server *server);
int	take_func(char *buffer, int fd, t_server *server);

/*
** drop.ia.c
*/
int	can_drop(int obj, t_trantorian *hand, t_server *server);
int	drop_item(char *token, int fd, t_server *server);
int	drop_func(char *buffer, int fd, t_server *server);

/*
** move_ia.c
*/
int     move_func(char *buffer, int fd, t_server *server);
void    move_ia(t_trantorian *hand, t_server *server);
void    do_move_x(t_trantorian *hand, t_server *server);
void    do_move_y(t_trantorian *hand, t_server *server);

/*
** orientation.c
*/
int	left_func(char *buffer, int fd, t_server *server);
int	right_func(char *buffer, int fd, t_server *server);

/*
** vision.c
*/
int	see_func(char *buffer, int fd, t_server *server);
void	init_see(t_trantorian *hand, t_server *server);
int	get_true_pos(int x, int y, t_server *server);
void	do_see_sud(int casX, int casY, t_trantorian *hand, int level,
		   t_server *server);
void	do_see(int level, t_trantorian *hand, t_server *server);

/*
** vision_2.c
*/
void	next_item_in_case(int pos, char *response, t_server *server);
void	item_in_case(int pos, char *response, int posx, int posy,
		     t_server *server);
void	player_in_case(char *response, int posx, int posy, t_server *server);

/*
** broadcast.c
*/
int	broadcast_func(char *buffer, int fd, t_server *server);

/*
** broadcast_2.c
*/
void	send_broadcast(t_server *server, char *buffer, int fd);

/*
** init_AI.c
*/
int	left_slot(char *team, t_server *server);
int	init_AI_msg(t_trantorian *hand, t_server *server);

/*
** init_graphic.c
*/
void	init_graphic(t_server *server);

/*
** incantation.c
*/
int	incantation_func(char *buf, int fd, t_server *server);
void	change_stone_place(int nb_stones, int stones, t_trantorian *hand,
			   t_server *server);

/*
** check_level_incantation_1.c
*/
int	check_level_one_stones_and_players(int pos, int nb_players,
				    t_server *server);
int	check_level_two_stones_and_players(int pos, int nb_players,
				   t_server *server);
int	check_level_three_stones_and_players(int pos, int nb_players,
				     t_server *server);
int	check_level_four_stones_and_players(int pos, int nb_players,
				     t_server *server);

/*
** check_level_incantation_2.c
*/
int	check_level_five_stones_and_players(int pos, int nb_players,
				    t_server *server);
int	check_level_six_stones_and_players(int pos, int nb_players,
				   t_server *server);
int	check_level_seven_stones_and_players(int pos, int nb_players,
				     t_server *server);
int	check_level_case(t_trantorian *hand, t_server *server);

/*
** change_map_incantation_2.c
*/
void	change_map_level_one(t_trantorian *hand, t_server *server);
void	change_map_level_two(t_trantorian *hand, t_server *server);
void	change_map_level_three(t_trantorian *hand, t_server *server);
void	change_map_level_four(t_trantorian *hand, t_server *server);

/*
** change_map_incantation_2.c
*/
void	change_map_level_five(t_trantorian *hand, t_server *server);
void	change_map_level_six(t_trantorian *hand, t_server *server);
void	change_map_level_seven(t_trantorian *hand, t_server *server);

/*
** misc_incantation.c
*/
int	 nb_players_same_level_func(t_trantorian *hand,
				    t_server *server);
void	 write_pic(t_trantorian *hand, t_server *server);
void	write_cmd_pie(t_trantorian *hand, t_server *server, char result[1]);
void	write_cmd_plv(t_trantorian *hand, t_server *server);
void	 write_bct_and_change_map(t_trantorian *hand, t_server *server);

/*
** expulse.c
*/
int	expulse_func(char *buffer, int fd, t_server *server);
void	write_expulse_ser(int i, t_server *server, int fd);
int	get_posX(int posX, t_server *server);
int	get_posY(int posY, t_server *server);
void	write_pex(int i, int fd, t_server *server);

/*
** check_and_cmd_ia.c
*/
int	check_cmd_ia(char *buf, int fd);
void	exec_cmd_ai(t_select *s_select, t_server *server);

/*
** first_cmd_ia.c
*/
int	find_min_time_first_command(t_server *server);

/*
** nbr_connect.c
*/
int	connect_nbr_func(char *buf, int fd, t_server *server);

/*
** fork.c
*/
int	fork_func(char *buf, int fd, t_server *server);
int	set_hatch(t_trantorian *AI_egg, t_server *server);
int	create_egg(int fd, t_server *server);
void	init_egg(t_trantorian *egg, t_trantorian *hand);
int	check_egg_pop(int fd, t_server *server);

/*
** death.c
*/
int	 dead_ai(t_trantorian *hand, t_server *server);
void	kill_ai(t_server *server, t_select *s_select);
int	check_dead_ia(t_server *server);
void	put_stones_in_map(int nb_stones, int stones, t_server *server);
void	change_exec_death(t_server *server, double min);

/*
** death_time.c
*/

int	find_min_death(t_server *server);
double	find_time_death(t_trantorian *AI, t_server *server);

/*
** init_pointer_array.c
*/
void	init_command_func(t_server *server);

/*
** exec_incantation_and_fork.c
*/
void	exec_incantation_and_fork(t_server *server);

/*
** win.c
*/
int	win(t_server *server);

/*
** verif_malloc.c
*/
void verif_malloc(t_server *server, int i);

#endif /* !SERVER_H_ */
