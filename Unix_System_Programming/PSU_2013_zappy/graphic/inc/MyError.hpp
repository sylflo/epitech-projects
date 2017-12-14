//
// MyError.hpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Thu Jul 10 17:14:55 2014 Arthur Coudert
// Last update Thu Jul 10 17:14:55 2014 Arthur Coudert
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
