//
// main.cpp for  in /home/chatea_s/project/c++/plazza
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon Apr 14 10:18:30 2014 Sylvain Chateau
// Last update Sun Apr 27 19:16:22 2014 Sylvain Chateau
//

#include <cstdlib>
#include <sstream>
#include "Exception.hpp"
#include "Receive.hpp"

int	convert(const char *nb_str)
{
  int	nb;

  std::istringstream(nb_str) >> nb;
  return (nb);
}

int	main(int argc, char **argv)
{
  int	nb1;
  int	nb2;
  int	nb3;

  try
    {
      if (argc != 4)
	throw Exception("Usage: ./plazza type size number");
      else
	{
	  nb1 = convert(argv[1]);
	  nb2 = convert(argv[2]);
	  nb3 = convert(argv[3]);
	  if (nb1 <= 0 && nb2 <= 0 && nb3 <= 0)
	    return (EXIT_FAILURE);
	  Receive plazza(convert(argv[1]), convert(argv[2]), convert(argv[3]));
	}
    }
  catch (const Exception &e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
