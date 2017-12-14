//
// main.cpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:56:50 2014 Sylvain Chateau
// Last update Sun Jun 15 22:33:08 2014 maxime duboy
//

#include <cstdlib>
#include <iostream>
#include "GameEngine.hpp"
#include "MenuManager.hpp"
#include "MyError.hpp"

int		main(int argc, char *argv[])
{
  try
    {
      MenuManager	Menuman;

      srand(time(NULL));
      if (!Menuman.initialize())
      	return (EXIT_FAILURE);
      while (Menuman.update())
      	Menuman.draw();
    }
  catch(const MyError& e)
    {
      std::cout << e.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}
