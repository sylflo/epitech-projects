//
// Exception.hpp for  in /home/chatea_s/project/c++/plazza
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon Apr 14 09:53:59 2014 Sylvain Chateau
// Last update Mon Apr 14 10:19:42 2014 Sylvain Chateau
//

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

# include <exception>
# include <iostream>

class Exception : public std::exception
{
private:
  std::string _what;

public:
  Exception(std::string const &msg="exception"): _what(msg) {}
  const char *what(void) const throw() { return _what.c_str(); }
  ~Exception(void) throw() {}
};

#endif /* !EXCEPTION_H_*/
