/*
** 209sondage.h for  in /home/chatea_s/epitech_perso/Tech_2/Math/209sondage
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jun  8 12:54:48 2014
** Last update Sun Jun  8 13:10:07 2014 
*/

#ifndef __209SONDAGE_H_
# define __209SONDAGE_H_

#include        <string>
#include        <sstream>
#include        <iostream>

#define USAGE_NEG "Bad parameters : no NEGATIF paramater\nPlease use \"./209sondage [size_pop] [size_ech] [%% vote]\"\n"


#define USAGE "Bad parameters : verif number of parameters\nPlease use \"./209sondage [size_pop] [size_ech] [%% vote]\"\n"

typedef struct s_struct
{
  int		pop_len;
  int		ech_len;
  double	poll;
}	t_struct;

double		loi_binomial(double n, double p);

#endif /* __209SONDAGE_H_ */
