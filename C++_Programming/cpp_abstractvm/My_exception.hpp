//
// My_exception.hh for  in /home/chatea_s/project/c++/abstrac_vm_part_1
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Thu Feb 20 10:08:24 2014 Sylvain Chateau
// Last update Mon Feb 24 08:27:30 2014 Sylvain Chateau
//

#ifndef MY_EXCEPTION_HH_
# define MY_EXCEPTION_HH_

#include <iostream>
#include <exception>

class My_exception : public std::exception
{
public:
  My_exception(std::string m="exception!") : msg(m) {}
  ~My_exception() throw() {}
  const char* what() const throw() { return msg.c_str(); }

private:
  std::string msg;
};

#endif
