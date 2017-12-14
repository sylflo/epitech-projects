//
// Objlib.hpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:44:43 2014 Sylvain Chateau
// Last update Tue Apr  1 16:44:43 2014 Sylvain Chateau
//

#ifndef OBJLIB_H
# define OBJLIB_H

# include <iostream>
# include <dlfcn.h>
# include "ILib.hpp"

class		ILib;

class		Objlib
{
private:
  void		*ptr_lib;
  ILib		*obj;
  void		openLib(const char *name_lib);
public:
  Objlib(const char *name_lib);
  ~Objlib();
  ILib		*getClass() const;
  void		closeLib() const;
};

#endif // LIB
