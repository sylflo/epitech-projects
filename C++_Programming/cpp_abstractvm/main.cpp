//
// main.cpp for  in /home/chatea_s/project/c++/abstrac_vm_part_1
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Wed Feb 19 16:34:09 2014 Sylvain Chateau
// Last update Fri Feb 28 13:45:05 2014 Sylvain Chateau
//

#include "My_exception.hpp"
#include "Read.hpp"

int	main(int argc, char **argv)
{
  Read	read;
  try
    {
      if (argc == 2)
	{
	  if (!read.read_from_file(argv))
	    return (-1);
	}
      else
	{
	  if (!read.read_from_entry_standard())
	    return (-1);
	}
    }
  catch(const My_exception &e)
    {
      std::cerr << e.what() << std::endl;
      return (-1);
    }
  return (0);
}
