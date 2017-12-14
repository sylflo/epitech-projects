//
// Parser.cpp for  in /home/chatea_s/project/c++/abstrac_vm_part_1
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Thu Feb 20 14:36:13 2014 Sylvain Chateau
// Last update Sun Mar  2 17:11:01 2014 Sylvain Chateau
//

#include <sstream>
#include <iterator>
#include <cstdlib>
#include "Instruction.hpp"
#include "My_exception.hpp"
#include "Stack.hpp"

using namespace std;


Instruction::Instruction(const std::string &line)
{
  add_to_list(line);

}

Instruction::~Instruction()
{

}

void	Instruction::setInstruction(std::string &instruction)
{
  m_instruction = instruction;
}

const std::string &Instruction::getInstruction() const
{
  return m_instruction;
}

void	Instruction::add_to_list(const std::string &line)
{
  std::string instruction("");
  std::istringstream s;
  std::string str;

  s.str(line);
  while (s >> str >> std::ws)
    {
      if (instruction != "")
	instruction += " ";
      instruction += str;
    }
  if (instruction[0] != ';' && !(instruction.empty()))
    m_list_instruction.push_front(instruction);
}


const std::list<std::string>	&Instruction::getList_instruction() const
{
  return m_list_instruction;
}

bool	Instruction::exec()
{
  static Stack stack;

  try
    {
      std::string instruction;

      while (!m_list_instruction.empty())
	{
	  std::istringstream line(m_list_instruction.front());
	  std::string arg;

	  line >> instruction;
	  setInstruction(instruction);
	  if (instruction == "exit")
	    break;
	  line >> arg;
	  std::string check;
	  line >> check;
	  if (!check.empty() && check[0] != ';')
	    {
	      std::ostringstream nb;
	      std::string str = "Syntax error: " + check;
	      throw My_exception(str);
	    }
	  if (!arg.empty())
	    stack.exec(instruction, arg);
	  else
	    stack.exec(instruction);
	  m_list_instruction.pop_front();
	}
      if (m_list_instruction.size() == 1 && instruction != "exit")
	throw My_exception("Instruction should end by exit");
    }
  catch(const My_exception& e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }
  return true;
}
