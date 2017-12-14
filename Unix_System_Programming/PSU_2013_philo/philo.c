/*
** test.c for  in /home/chatea_s/project/unix/philosophe/philosophe
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 15 16:49:09 2014 Sylvain Chateau
** Last update Sun Mar 23 21:46:37 2014 Sylvain Chateau
*/

#include "philo.h"

int		main(void)
{
  t_philo	s_philo;

  if (!check_define())
    return (EXIT_FAILURE);
  memset(&s_philo, 0, sizeof(t_philo));
  if (!init(&s_philo))
    return(EXIT_FAILURE);
  if (!manage_thread(&s_philo))
    return(EXIT_FAILURE);
  print_end();
  return (EXIT_SUCCESS);
}

void	init_sticks(t_philo *philo, int *right_stick, int *left_stick)
{
  printf("Philosphe %d end thinking and can now eat\n", philo->id);
  *right_stick = philo->id;
  *left_stick = philo->id + 1;
  if (*left_stick == NB_PHILO)
    *left_stick = 0;
}

void		*manage_philosophe(void *num)
{
  t_philo	philo;
  int		left_stick;
  int		right_stick;
  int		food;

  philo = *(t_philo *) num;
  init_sticks(&philo, &right_stick, &left_stick);
  while ((food = manage_food(&philo)))
    {
      if (sem_wait(&philo.can_eat) == -1)
	exit(EXIT_FAILURE);
      take_sticks(philo.id, right_stick, "right", &philo);
      take_sticks(philo.id, left_stick, "left", &philo);
      printf("Philosopher %d: is eating\n", philo.id);
      if (usleep(TIME * (NB_FOOD - food + 1)) == -1)
	exit(EXIT_FAILURE);
      put_down_sticks(left_stick, right_stick, &philo);
      if (sem_post(&philo.can_eat) == -1)
	exit(EXIT_FAILURE);
    }
  return (NULL);
}

int		manage_food(t_philo *s_philo)
{
  static int	food = NB_FOOD;
  int		myfood;

  if (pthread_mutex_lock(&s_philo->food))
    {
      perror("pthread_mutex_lock");
      exit(EXIT_FAILURE);
    }
  if (food > 0)
    {
      g_nb_food[s_philo->id]++;
      food--;
    }
  myfood = food;
  if (pthread_mutex_unlock(&s_philo->food))
    {
      perror("pthread_mutex_lock");
      exit(EXIT_FAILURE);
    }
  return (myfood);
}

void	take_sticks(int phil, int c, char *hand, t_philo *s_philo)
{
  if (pthread_mutex_lock(&s_philo->stick[c]))
    {
      perror("pthread_mutex_lock");
      exit(EXIT_FAILURE);
    }
  printf ("Philosopher %d: take chopstick %d on the %s\n", phil, c, hand);
}

void	put_down_sticks(int c1, int c2, t_philo *s_philo)
{
  if (pthread_mutex_unlock(&s_philo->stick[c1]))
    {
      perror("pthread_mutex_lock");
      exit(EXIT_FAILURE);
    }
  if (pthread_mutex_unlock(&s_philo->stick[c2]))
    {
      perror("pthread_mutex_lock");
      exit(EXIT_FAILURE);
    }
}
