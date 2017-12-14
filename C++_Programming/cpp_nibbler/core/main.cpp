//
// main.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:43:24 2014 Sylvain Chateau
// Last update Tue Apr  1 16:43:25 2014 Sylvain Chateau
//

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <dlfcn.h>
#include <time.h>
#include <string.h>
#include "Nibbler.hpp"
#include "ILib.hpp"
#include "Objlib.hpp"

int		main(int argc, char **argv)
{
  ILib::t_size	size_win;

  if (getenv("DISPLAY") == NULL)
    {
      std::cout << "Error system environement" << std::endl;
      return (EXIT_FAILURE);
    }
  srand(time(NULL));
  if (argc != 4)
    {
      std::cout << "\033[31mError bad argument.\033[0m" << std::endl;
      std::cout << "Usage : [" << argv[0] << "] x y lib" << std::endl;
      return (EXIT_FAILURE);
    }
  Objlib n(argv[3]);
  if ((size_win.heigth = atoi(argv[1])) < 10 ||
      (size_win.width = atoi(argv[2])) < 10)
    {
      std::cout << "Error the win size is too small" << std::endl;
      return (EXIT_FAILURE);
    }
  Nibbler nib(n, size_win);
  nib.loop();
  return (EXIT_SUCCESS);
}
