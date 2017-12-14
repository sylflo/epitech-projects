//
// Read.cpp for  in /home/chatea_s/project/c++/vm/vm_in_building
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri Feb 28 13:40:52 2014 Sylvain Chateau
// Last update Sun Mar  2 17:11:18 2014 Sylvain Chateau
//

#include <fstream>
#include "My_exception.hpp"
#include "Instruction.hpp"
#include "Read.hpp"

Read::Read()
{

}

Read::~Read()
{

}

bool	Read::read_from_file(char **argv)
{
  std::string	line;
  std::ifstream	my_file(argv[1]);
  bool		check_exit = false;

  if (!my_file.is_open())
    throw My_exception("File not open or does not exist");
  else
    {
      while (std::getline(my_file, line))
	{
	  Instruction instruction(line);
	  if (!instruction.exec())
	    return false;
	  if (instruction.getInstruction() == "exit")
	    {
	      check_exit = true;
	      break;
	    }
	}
      if (!check_exit)
	{
	  throw My_exception("Error the last instruction must be exit");
	  return false;
	}
      my_file.close();
    }
  return true;
}

bool	Read::read_from_entry_standard(void)
{
  std::string	line;
  bool		check_exit = false;
  bool		check_final_exit = false;

  do
    {
      std::getline(std::cin, line);
      Instruction instruction(line);
      if (!instruction.exec())
	return false;
      if (instruction.getInstruction() == "exit")
	check_exit = true;

      if (line == ";;" )
	{
	  check_final_exit = true;
	  break;
	}
    } while (!check_final_exit);
  if (!check_exit)
    {
      throw My_exception("Error missing instruction exit");
      return false;
    }
  if (!check_final_exit)
    {
      throw My_exception("Error missing instruction ';;' for end of file");
      return false;
    }

  return true;
}
