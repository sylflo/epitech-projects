/*
** main.c for  in /home/chatea_s/epitech_perso/Tech_2/Math/209sondage
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jun  8 12:54:36 2014
** Last update Sun Jun  8 13:07:16 2014 
*/

#include	<string.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"209sondage.h"

void	printresult(t_struct *var, double first, double second, double varia)
{
  double	a, a_one, b, b_one;

  a = (var->poll - first);
  if (a < 0)
    a = 0;
  a_one = (var->poll + first);
  if (a_one > 100.0)
    a_one = 100;
  b = (var->poll - second);
  if (b < 0)
    b = 0;
  b_one = (var->poll + second);
  if (b_one > 100.0)
    b_one = 100;
  printf("taille de la population :\t%d\n", var->pop_len);
  printf("taille de l'echantillon :\t%d\n", var->ech_len);
  printf("resultat du sondage :\t\t%0.2f%%\n", var->poll);
  printf("variance estimee :\t\t%f\n", varia);
  printf("intervalle de confiance a 95%% :\t[%0.2f%% ; %0.2f%%]\n", a, a_one);
  printf("intervalle de confiance a 99%% :\t[%0.2f%% ; %0.2f%%]\n", b, b_one);
}

double	calc_first(double variance)
{
  return (((2 * 1.96) * sqrt(variance)) / 2 * 100);
}

double	calc_second(double variance)
{
  return (((2 * 2.58) * sqrt(variance)) / 2 * 100);
}

double	find_variance(t_struct *donee)
{
  double	var_b = 0, p = 0, pop, ech;
  double	res = 0;

  pop = donee->pop_len;
  ech = donee->ech_len;

  p = donee->poll / 100;
  var_b = (p * (1 - p));

  res = ((var_b / ech) * ((pop - ech) / (pop - 1)));
  return (res);
}

void	launch(t_struct *donee)
{
  double	first = 0, second = 0, var = 0.000464;

  var = find_variance(donee);
  first = calc_first(var);
  second = calc_second(var);
  printresult(donee, first, second, var); /* variance */
}

int	new_struct(t_struct *var, char *argv[])
{
  var->pop_len = atoi(argv[1]);
  var->ech_len = atoi(argv[2]);
  var->poll = atof(argv[3]);
  if (var->pop_len < 0 || var->ech_len < 0 || var->poll < 0)
    {
      fprintf(stderr, USAGE_NEG);
      return (EXIT_FAILURE);
    }
  if (var->pop_len < var->ech_len)
    {
      fprintf(stderr, "Error pop_len need > ech_len\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
  t_struct	variable;

  if (argc != 4)
    {
      fprintf(stderr, USAGE);
      return (EXIT_FAILURE);
    }
  if (new_struct(&variable, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  launch(&variable);
  return EXIT_SUCCESS;
}
