//
// Parser.hpp for  in /home/chatea_s/project/c++/abstractvm
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Thu Feb 20 09:57:45 2014 Sylvain Chateau
// Last update Mon Feb 24 10:25:53 2014 Sylvain Chateau
//

#ifndef Instruction_HPP_
# define Instruction_HPP_

#include <iostream>
#include <list>

class	Instruction
{
public:
  Instruction(const std::string &line);
  ~Instruction();

public:
  void	setInstruction(std::string &instruction);
  const std::string &getInstruction() const;

public:
  void				add_to_list(const std::string &instruction);
  const std::list<std::string>	&getList_instruction() const;
  bool				exec();

private:
  std::string m_instruction;
  std::list<std::string> m_list_instruction;
};

#endif /* Instruction_HPP_ */
