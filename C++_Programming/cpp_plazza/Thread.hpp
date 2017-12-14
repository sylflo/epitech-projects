//
// Thread.hpp for  in /home/chatea_s/project/c++/plazza
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Sun Apr 27 18:48:30 2014 Sylvain Chateau
// Last update Sun Apr 27 19:48:31 2014 Sylvain Chateau
//

#ifndef THREAD_H_
# define THREAD_H_

# include <pthread.h>

class IThread
{
public:
  ~IThread();
};

class Thread
{
private:
  pthread_t	_thread;
  IThread	&_thread_obj;

public:
  Thread(IThread &thread);
  ~Thread();
};

#endif /* !THREAD_H_*/
