//
// Objlib.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:43:29 2014 Sylvain Chateau
// Last update Tue Apr  1 16:43:30 2014 Sylvain Chateau
//

#include "Objlib.hpp"

Objlib::Objlib(const char *name_lib)
{
  this->ptr_lib = NULL;
  this->obj = NULL;
  this->openLib(name_lib);
}

Objlib::~Objlib()
{
  this->closeLib();
}

void		Objlib::openLib(const char *name_lib)
{
  ILib		*(*d)();

  if ((this->ptr_lib = dlopen(name_lib, RTLD_LAZY)) == NULL)
    {
      std::cout << "Error open librairy : " << name_lib << std::endl;
      return ;
    }
  if ((d = reinterpret_cast<ILib *(*)()>(dlsym(this->ptr_lib,
					       "create_lib"))) == NULL)
    {
      std::cout << "Error to call librairy" << std::endl;
      return ;
    }
  this->obj = d();
}

ILib		*Objlib::getClass() const
{
  return (this->obj);
}

void		Objlib::closeLib() const
{
  if (this->ptr_lib != NULL)
    dlclose(this->ptr_lib);
}
