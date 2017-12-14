
#ifndef ABOMBER_H_
#define ABOMBER_H_

//#include "Input.hpp"
#include	"AObject.hpp"

class ABomber : public AObject
{
public:
  ABomber();
  virtual ~ABomber();
  

  bool	getAlive() const;
  void	setDead();
  float	getSpeed() const;
protected:
  bool		_alive;
  float		_speed;
};

#endif /* !ABOMBER_H_*/
