/*
** philo.h for  in /home/chatea_s/project/unix/philosophe/philosophe
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 15 16:49:51 2014 Sylvain Chateau
** Last update Sun Mar 23 21:46:43 2014 Sylvain Chateau
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <string.h>

# define NB_PHILO 9
# define TIME 5000
# define NB_FOOD 100

int			g_nb_food[NB_PHILO];

typedef struct		s_philo
{
  pthread_mutex_t	stick[NB_PHILO];
  pthread_t		philo[NB_PHILO];
  pthread_mutex_t	food;
  sem_t			can_eat;
  int			id;
}			t_philo;

void			*manage_philosophe(void *id);
void			take_sticks(int, int, char *, t_philo *);
void			put_down_sticks(int, int, t_philo *);
int			manage_food(t_philo *);
int			init(t_philo *);
int			manage_thread(t_philo *);
int			check_define();
void			print_end(void);
void			init_sticks(t_philo *, int *, int *);

#endif /* !PHILO_H_*/
