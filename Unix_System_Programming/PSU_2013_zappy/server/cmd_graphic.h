/*
** cmd_graphic.h for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Jul  8 22:02:58 2014
** Last update Fri Jul 11 15:14:59 2014 sylvain chateau
*/

#ifndef CMD_GRAPHIC_H_
# define CMD_GRAPHIC_H_

/*
** bct.c
*/
int	check_num_case(int pos, char *token);
int	object_in_case(int posX, int posY, t_server *server);
int	bct_func(char *buffer, t_server *server);

/*
** msz.c
*/
int	msz_func(char *buf, t_server *server);

/*
** tna.c
*/
int	tna_func(char *buf, t_server *server);

/*
** sgt.c
*/
int	sgt_func(char *buf, t_server *server);

/*
** mct.c
*/
int	mct_func(char *buf, t_server *server);

/*
** tna.c
*/
int	tna_func(char *buf, t_server *server);

/*
** ppo.c
*/
int	call_ppo(int fd, t_server *server);
int	ppo_func(char *buf, t_server *server);

/*
** plv.c
*/
int	plv_func(char *buf, t_server *server);

/*
** pin.c
*/
int	pin_func(char *buf, t_server *server);

/*
** pin.c
*/
int	sst_func(char *buf, t_server *server);

/*
** pnw.c
*/
int	pnw_cmd(t_trantorian *hand, t_server *server);
void	exec_pin(t_trantorian *hand, t_server *server);

#endif /* !CMD_GRAPHIC_H_*/
