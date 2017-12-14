//
// Nibbler.hpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:43:21 2014 Sylvain Chateau
// Last update Tue Apr  1 16:43:22 2014 Sylvain Chateau
//

#ifndef NIBBLER_H
# define NIBBLER_H

# include <iostream>
# include <unistd.h>
# include <vector>
# include "Objlib.hpp"
# include "ILib.hpp"

# define MOVE			5

class				ILib;

class				Nibbler
{
private:
  int				time;
  bool				pause;
  Objlib			*objLib;
  int				counter;
  bool				alive;
  bool				isFeed;
  int				direction;
  std::vector<t_element>	snake;
  std::vector<t_element>	food;
  ILib				*lib;
  ILib::t_size			sizeWin;
  bool				loadLibrairy(int lib);
  void				endGame() const;
  void				moveSnake(const unsigned int move);
  void				moveUp();
  void				moveDown();
  void				moveRigth();
  void				moveLeft();
  void				popFood();
  void				collision();
  void				initSnake(ILib::t_size);
  void				deplaceSnake();
  bool				check_case(const unsigned int position_x,
					   const unsigned int position_y);
  void				feedSnake();
  void				addBlock();
  bool			        eatFood();
public:
  void				loop();
  Nibbler(Objlib &lib, const ILib::t_size win_size);
};

typedef				void (Nibbler::*FunctionPointer)(void);

#endif // NIBBLER
