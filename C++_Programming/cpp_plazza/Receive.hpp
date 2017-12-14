//
// Receive.hpp for  in /home/chatea_s/project/c++/plazza
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Sun Apr 27 19:06:04 2014 Sylvain Chateau
// Last update Sun Apr 27 19:50:49 2014 Sylvain Chateau
//

#ifndef RECEIVE_H_
# define RECEIVE_H_

#include "Thread.hpp"

class Receive: public IThread
{
public:
  Receive(int, int, int);
  ~Receive();

private:
  int	_mult;
  int	_cooking;
  int	_refresh;
};

#endif /* !RECEIVE_H_*/
