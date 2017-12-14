/*
** lemipc.h for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Mar 27 13:04:28 2014 Sylvain Chateau
** Last update Sun Mar 30 19:22:20 2014 edouard mansuy
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/sem.h>
# include <sys/shm.h>

typedef struct	s_lemipc
{
  int		shm_id;
  int		key;
  char		*addr;
  int		sem_id;
  char		team;
  struct sembuf	sops;
  int		access;
  int		first;
  int		nb_players;
  int		can_play;
  char		**map;
  int		pos_player;
}		t_lemipc;

/*
** create_board.c
*/

int		create_board(t_lemipc *);
int		create_map(t_lemipc *);
void		add_player_in_map(t_lemipc *);
void		fill_map(t_lemipc *, int *, int *);
void		free_tab(char **);

/*
** init_players.c
*/

void		choose_player(t_lemipc *);
int		first_player(t_lemipc *);
int		next_player(t_lemipc *);

/*
** lemipc.c
*/

int		move(t_lemipc *);
int		play_game(t_lemipc *);
int		func_lemipc(t_lemipc *);
int		func_board(t_lemipc *);

/*
** lock_sem.c
*/

int		lock_sem(t_lemipc *);
int		unlock_sem(t_lemipc *);

/*
** number_player.c
*/

int		nb_team_player(char *, char);
void		total_player(t_lemipc *);

/*
** opponent.c
*/

int		find_side_opponent(t_lemipc *, int, int, char);
int		find_diago_opponent(t_lemipc *, int, int, char);
int		find_opponent(t_lemipc *, int, int, char);
int		check_killing(t_lemipc *);

#endif /* !LEMIPC_H_*/
