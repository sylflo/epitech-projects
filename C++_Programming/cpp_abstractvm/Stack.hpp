//
// Vm.hpp for  in /home/chatea_s/project/c++/vm_in_building
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri Feb 21 01:06:00 2014 Sylvain Chateau
// Last update Sun Mar  2 21:24:05 2014 Sylvain Chateau
//

#ifndef STACK_HPP_
# define STACK_HPP_

#include <list>
#include <map>
#include "Operand.hpp"

class Stack
{
public:
  Stack();
  ~Stack();

public:
  void		exec(const std::string &arg1, const std::string &arg2 = "");
  IOperand	*get_arg2(const std::string &arg2);
  void		check_int(const std::string &value);
  void		check_float(const std::string &value);
  void		check_zero(const std::string &value);

public:
  IOperand	*new_int_8(const std::string &val);
  IOperand	*new_int_16(const std::string &val);
  IOperand	*new_int_32(const std::string &val);
  IOperand	*new_float(const std::string &val);
  IOperand	*new_double(const std::string &val);

public:
  void	push(IOperand *v);
  void	assert(IOperand *v);

public:
  void	pop();
  void	dump();
  void	add();
  void	sub();
  void	mul();
  void	div();
  void	mod();
  void	print();

private:
  std::list<IOperand *>	m_stack;

  std::map<std::string, void (Stack::*)(void)>		m_instruction_void;
  std::map<std::string, void (Stack::*)(IOperand *)>	m_instruction_arg;

  std::map<std::string, IOperand *(Stack::*)(const std::string &val)>	m_set;
};

#endif /* STACK_HPP_ */
