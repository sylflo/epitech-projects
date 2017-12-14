/*
** philo_two.c for  in /home/chatea_s/project/unix/philosophe/philosophe
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Fri Mar 21 16:03:30 2014 Sylvain Chateau
** Last update Sun Mar 23 21:46:40 2014 Sylvain Chateau
*/

#include "philo.h"

int	init(t_philo *s_philo)
{
  int	i;

  if (pthread_mutex_init(&s_philo->food, NULL))
    {
      perror("pthread_mutex_init");
      return (0);
    }
  if (sem_init(&s_philo->can_eat, 0, NB_PHILO - 1) == -1)
    return (0);
  i = -1;
  while (++i < NB_PHILO)
    if (pthread_mutex_init(&s_philo->stick[i], NULL))
      {
	perror("pthread_mutex_init");
	return (0);
      }
  return (1);
}

int	manage_thread(t_philo *s_philo)
{
  s_philo->id = -1;
  while (++s_philo->id < NB_PHILO)
    {
      if (pthread_create(&s_philo->philo[s_philo->id], NULL, manage_philosophe,
			 (void *)s_philo))
	{
	  perror("pthread_create");
	  return (0);
	}
      if (usleep(1000) == -1)
	return (0);
    }
  s_philo->id = -1;
  while (++s_philo->id < NB_PHILO)
    {
      if (pthread_join(s_philo->philo[s_philo->id], NULL))
	{
	  perror("pthread_join");
	  return (0);
	}
    }
  return (1);
}


int	check_define()
{
  if (NB_PHILO < 2 || NB_PHILO > 10)
    {
      fprintf(stderr, "Philosophes must be superior to 2 and inferior to ten\n");
      return (0);
    }
  if (TIME > 5000 || TIME < 0)
    {
      fprintf(stderr, "Time must be positive and inferior or equal to 5000\n");
      return (0);
    }
  if (NB_FOOD > 100 || NB_FOOD < 0)
    {
      fprintf(stderr, "Food must be superior to 0 and inferior");
      fprintf(stderr, " or equal to 100\n");
      return (0);
    }
  return (1);
}

void	print_end(void)
{
  int	i;

  i = -1;
  printf("\n");
  while (++i < NB_PHILO)
    printf("Philosophe %d ate %d parts\n", i, g_nb_food[i]);
}
