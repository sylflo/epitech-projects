//
// MyError.hpp for  in /home/chatea_s/cpp_bomberman
//
// Made by
// Login   <chatea_s@epitech.net>
//
// Started on  Fri May 23 19:03:20 2014
// Last update Fri May 23 19:11:52 2014 
//

#ifndef MYERROR_H_
# define MYERROR_H_

#include <iostream>
#include <stdexcept>

class	MyError : public std::runtime_error{
public:
  MyError(const std::string& msg = "") : std::runtime_error(msg) {}
};

#endif /* !MYERROR_H_*/
