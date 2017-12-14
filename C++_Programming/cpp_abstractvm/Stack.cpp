//
// Vm.cpp for  in /home/chatea_s/project/c++/vm/vm_in_building
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri Feb 21 14:37:57 2014 Sylvain Chateau
// Last update Sun Mar  2 22:43:13 2014 Sylvain Chateau
//

#include <stdint.h>
#include "Stack.hpp"
#include "My_exception.hpp"
#include "Operand.hpp"

Stack::Stack()
{
  m_set["int8"] = &Stack::new_int_8;
  m_set["int16"] = &Stack::new_int_16;
  m_set["int32"] = &Stack::new_int_32;
  m_set["float"] = &Stack::new_float;
  m_set["double"] = &Stack::new_double;

  m_instruction_arg["push"] = &Stack::push;
  m_instruction_arg["assert"] = &Stack::assert;

  m_instruction_void["pop"] = &Stack::pop;
  m_instruction_void["dump"] = &Stack::dump;
  m_instruction_void["add"] = &Stack::add;
  m_instruction_void["sub"] = &Stack::sub;
  m_instruction_void["mul"] = &Stack::mul;
  m_instruction_void["div"] = &Stack::div;
  m_instruction_void["mod"] = &Stack::mod;
  m_instruction_void["print"] = &Stack::print;
}

Stack::~Stack()
{

}

void		Stack::check_int(const std::string &value)
{
  std::string	str_int = "0123456789";
  int		i = 0;
  int		count_occ;

  if (value[0] == '-' && value.size() == 1)
    throw My_exception("You must put a number");
  if (value[i] == '-')
    i++;
  while(value[i])
    {
      count_occ = 0;
      for (int j = 0; str_int[j]; j++)
	{
	  if (value[i] == str_int[j])
	    count_occ++;
	}
      if (count_occ == 0)
	throw My_exception(value + ": the number must be an integer");
      i++;
    }
}

void		Stack::check_float(const std::string &value)
{
  std::string	str_dot = ".0123456789";
  int		i = 0;
  int		count_occ;
  int		nb_dot = 0;

  if (value[0] == '-' && value.size() == 1)
    throw My_exception("You must put a number");
  if (value[i] == '-')
    i++;
  if (value[0] == '-' && value[1] == '.')
    throw My_exception("You have to put number after '-'");
  for(int k = 0; value[k]; k++)
    {
      if (value[k] == '.')
	nb_dot++;
    }
  if (nb_dot < 1)
    throw My_exception(value + ": You must specifiy a dot");
  if (nb_dot > 1)
    throw My_exception(value + ": You must specifiy a dot and only one");

  int	pos_dot =  value.find('.');
  if (pos_dot == 0 && pos_dot == (int)value.size() - 1)
    throw My_exception(value + ": your must specify some number before and after the dot");
  if (pos_dot == (int)value.size() - 1)
    throw My_exception(value + ": your must specify some number after the dot");
  if (pos_dot == 0)
    throw My_exception(value + ": your must specify some number before the dot");

  while(value[i])
    {
      count_occ = 0;
      for (int j = 0; str_dot[j]; j++)
	{
	  if (value[i] == str_dot[j])
	    count_occ++;
	}
      if (count_occ == 0)
	throw My_exception(value + ": the number must be a decimal");
      i++;
    }
}

IOperand	*Stack::get_arg2(const std::string &arg)
{
  std::map<std::string, IOperand *(Stack::*)(const std::string &val)>::iterator it_set;
  IOperand	*operand;
  int		l_par;
  int		r_par;
  std::string	type_operand;
  std::string	str_value;

  r_par = arg.find_last_of(')');
  l_par = arg.find_first_of('(');
  operand = NULL;
  if (l_par == -1 || r_par == -1)
      throw My_exception(arg + ": Missing parenthesis");
  if (l_par > r_par || l_par == r_par - 1)
    throw My_exception(arg + ": Incorrect syntax");
  type_operand = arg.substr(0, l_par);
  str_value = arg.substr(l_par + 1, r_par - l_par - 1);
  it_set = m_set.find(type_operand);
  if (it_set != m_set.end())
    operand = (this->*m_set[type_operand])(str_value);
  else
    throw My_exception(arg + ": this type does not exist");
  return operand;
}

void		Stack::exec(const std::string &arg1, const std::string &arg2)
{
  IOperand	*operand;
  std::map<std::string, void (Stack::*)(void)>::iterator it_void;
  std::map<std::string, void (Stack::*)(IOperand *)>::iterator it_arg;

  it_void = m_instruction_void.find(arg1);
  it_arg = m_instruction_arg.find(arg1);
  if (it_void != m_instruction_void.end())
    {
      if (!arg2.empty())
	throw My_exception(arg2 + ": You must put only one instruction per line");
      (this->*m_instruction_void[arg1])();
    }
  else if (it_arg != m_instruction_arg.end())
    {
      operand = get_arg2(arg2);
      (this->*m_instruction_arg[arg1])(operand);
    }
  else
    {
      std::string str = "Incorrect instruction: " + arg1;
      throw My_exception(str);
    }
}

IOperand	*Stack::new_int_8(const std::string &val)
{

  check_int(val);
  return new Operand<int8_t>(val, INT8);
}

IOperand	*Stack::new_int_16(const std::string &val)
{
  check_int(val);
  return new Operand<int16_t>(val, INT16);
}

IOperand	*Stack::new_int_32(const std::string &val)
{
  check_int(val);
  return new Operand<int32_t>(val, INT32);
}

IOperand	*Stack::new_float(const std::string &val)
{
  check_float(val);
  return new Operand<float>(val, FLOAT);
}

IOperand	*Stack::new_double(const std::string &val)
{
  check_float(val);
  return new Operand<double>(val, DOUBLE);
}

void	Stack::push(IOperand *v)
{
  m_stack.push_front(v);
}

void	Stack::assert(IOperand *v)
{
  if (m_stack.empty())
    throw My_exception("The list is empty\n");
  if (m_stack.front()->toString() != v->toString() || m_stack.front()->getType() != v->getType())
    throw My_exception("The numbers are different");
}

void	Stack::pop()
{
  if (m_stack.empty())
    throw My_exception("The stack is empty");
  m_stack.pop_front();
}

void	Stack::dump()
{
  std::list<IOperand *>::iterator it;

  for (it = m_stack.begin(); it != m_stack.end(); ++it)
    std::cout << (*it)->toString() << std::endl;
}

void		Stack::add()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (m_stack.size() < 2)
    throw My_exception("You need a least two number in the stack");

  nb1 = m_stack.front();
  m_stack.pop_front();
  nb2 = m_stack.front();
  m_stack.pop_front();
  m_stack.push_front(*nb1 + *nb2);
  delete nb1;
  delete nb2;
}

void	Stack::sub()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (m_stack.size() < 2)
    throw My_exception("You need a least two number in the stack");

  nb1 = m_stack.front();
  m_stack.pop_front();
  nb2 = m_stack.front();
  m_stack.pop_front();
  m_stack.push_front(*nb1 - *nb2);
  delete nb1;
  delete nb2;
}

void	Stack::mul()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (m_stack.size() < 2)
    throw My_exception("You need a least two number in the stack");

  nb1 = m_stack.front();
  m_stack.pop_front();
  nb2 = m_stack.front();
  m_stack.pop_front();
  m_stack.push_front(*nb1 * *nb2);
  delete nb1;
  delete nb2;
}

void		Stack::check_zero(const std::string &value)
{
  unsigned int	i = 0;

  if (value[i] == '-')
    i++;
  while (value[i])
    i++;
  if (i == value.size())
    throw My_exception("You can't divide by zero");
}

void	Stack::div()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (m_stack.size() < 2)
    throw My_exception("You need a least two number in the stack");
  nb1 = m_stack.front();
  m_stack.pop_front();
  nb2 = m_stack.front();
  m_stack.pop_front();
  check_zero(nb2->toString());
  m_stack.push_front(*nb1 / *nb2);
  delete nb1;
  delete nb2;
}

void	Stack::mod()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (m_stack.size() < 2)
    throw My_exception("You need a least two number in the stack");
  nb1 = m_stack.front();
  m_stack.pop_front();
  nb2 = m_stack.front();
  m_stack.pop_front();
  if (nb2->getType() == FLOAT || nb2->getType() == DOUBLE)
    throw My_exception("You have to use int for modulo");
  check_zero(nb2->toString());
  m_stack.push_front(*nb1 % *nb2);
  delete nb1;
  delete nb2;
}

void			Stack::print()
{
  std::stringstream	s;
  int			temp;

  if (m_stack.empty())
    throw My_exception("The stack is empty");
  if (m_stack.front()->getType() == INT8)
    {
      s.str(m_stack.front()->toString());
      s >> temp;
      std::cout <<  static_cast<signed char>(temp) << std::endl;
    }
  else
    throw(My_exception("There is no type INT8 at the top of the stack"));
}
