//
// ILib.hpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:44:38 2014 Sylvain Chateau
// Last update Fri Apr  4 13:17:57 2014 maxime duboy
//

#ifndef LIB_H
# define LIB_H

# include <iostream>
# include <vector>

struct			s_element;

class			ILib
{
public:
  enum			key
    {
      UP = 0,
      DOWN = 1,
      LEFT = 2,
      RIGTH = 3,
      QUIT,
      PAUSE,
      LIB1,
      LIB2,
      LIB3,
      NONE
    };
  enum			typeDisplay
    {
      BLOCK,
      FOOD,
      SNAKE_HEAD,
      SNAKE
    };
  typedef struct        s_position
  {
    int			x;
    int			y;
  }			t_position;
  typedef struct        s_size
  {
    unsigned int	width;
    unsigned int        heigth;
  }			t_size;
  typedef struct        s_rect
  {
    t_size		size;
    t_position		position;
  }			t_rect;
  virtual bool		initWindow(const t_size) = 0;
  virtual void		display(const std::vector<struct s_element> &list,
				const std::vector<struct s_element> &food,
				const int counter) = 0;
  virtual void		closeWindow() const = 0;
  virtual key		getEvent() const = 0;
};

typedef struct		s_element
{
  ILib::t_position	position;
  ILib::typeDisplay	type;
}			t_element;

#endif // LIB
