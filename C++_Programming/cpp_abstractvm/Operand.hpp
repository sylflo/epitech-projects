//
// Operand.hh for  in /home/chatea_s/project/c++/vm_in_building
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri Feb 21 00:45:15 2014 Sylvain Chateau
// Last update Sun Mar  2 22:45:42 2014 Sylvain Chateau
//

#ifndef OPERAND_HH_
# define OPERAND_HH_

#include <sstream>
#include "IOperand.hpp"
#include "My_exception.hpp"

template <typename T>
class Operand : public IOperand
{
public:
  Operand(std::string value, eOperandType type);
  ~Operand();

public:
  std::string const	&toString() const;
  T const		&toValue() const;
  int			getPrecision() const;
  eOperandType		getType() const;
  Operand		*copy() const;
  void			check_overflow(const std::string &value, const int &type);
  void			check_underflow(const std::string &value, const int &type);

  IOperand		*operator+(const IOperand &rhs) const;
  IOperand		*operator-(const IOperand &rhs) const;
  IOperand		*operator*(const IOperand &rhs) const;
  IOperand		*operator/(const IOperand &rhs) const;
  IOperand		*operator%(const IOperand &rhs) const;

private:
  eOperandType		m_type;
  std::string		m_str_value;
  T			m_value_t;
};

template <typename T>
Operand<T>::Operand(std::string value, eOperandType type):
  m_type(type), m_str_value(value)
{
  std::stringstream	convert;

  check_overflow(m_str_value, getType());
  convert.str(m_str_value);
  convert >> m_value_t;
}

template <typename T>
Operand<T>::~Operand()
{

}

template <typename T>
std::string const &Operand<T>::toString() const
{

  return m_str_value;
}

template <typename T>
int	Operand<T>::getPrecision() const
{
  return m_type;
}

template <typename T>
eOperandType	Operand<T>::getType() const
{
  return m_type;
}

template <typename T>
Operand<T>		*Operand<T>::copy() const
{
  return new Operand<T>(toString(), m_type);
}



template <typename T>
IOperand		*Operand<T>::operator+(const IOperand &rhs) const
{
  std::stringstream	s;
  float			temp;
  Operand		*result;

  s.str(rhs.toString());
  s >> temp;
  if (rhs.getPrecision() > getPrecision())
    result = static_cast<const Operand &>(rhs).copy();
  else
   result = copy();
  result->m_value_t = m_value_t + temp;
  s.clear();
  s << result->m_value_t;
  result->m_str_value = s.str();
  return result;
}

template <typename T>
IOperand	*Operand<T>::operator-(const IOperand &rhs) const
{
  std::stringstream	s;
  float			temp;
  Operand		*result;

  s.str(rhs.toString());
  s >> temp;
  if (rhs.getPrecision() > getPrecision())
    result = static_cast<const Operand &>(rhs).copy();
  else
   result = copy();
  result->m_value_t = m_value_t - temp;
  s.clear();
  s << result->m_value_t;
  result->m_str_value = s.str();
  return result;
}

template <typename T>
IOperand	*Operand<T>::operator*(const IOperand &rhs) const
{
  std::stringstream	s;
  float			temp;
  Operand		*result;

  s.str(rhs.toString());
  s >> temp;
  if (rhs.getPrecision() > getPrecision())
    result = static_cast<const Operand &>(rhs).copy();
  else
   result = copy();
  result->m_value_t = m_value_t * temp;
  s.clear();
  s << result->m_value_t;
  result->m_str_value = s.str();
  return result;
}

template <typename T>
IOperand	*Operand<T>::operator/(const IOperand &rhs) const
{
  std::stringstream	s;
  float			temp;
  Operand		*result;

  s.str(rhs.toString());
  s >> temp;
  if (rhs.getPrecision() > getPrecision())
    result = static_cast<const Operand &>(rhs).copy();
  else
   result = copy();
  result->m_value_t = m_value_t / temp;
  s.clear();
  s << result->m_value_t;
  result->m_str_value = s.str();
  return result;
}

template <typename T>
IOperand	*Operand<T>::operator%(const IOperand &rhs) const
{
  std::stringstream	s;
  int			temp;
  Operand		*result;

  s.str(rhs.toString());
  s >> temp;
  if (rhs.getPrecision() > getPrecision())
    result = static_cast<const Operand &>(rhs).copy();
  else
    result = copy();
  result->m_value_t = (int)m_value_t % temp;
  s.clear();
  s << result->m_value_t;
  result->m_str_value = s.str();
  return result;
}

template <typename T>
void	Operand<T>::check_overflow(const std::string &value, const int &type)
{
  int	nb;

  if (value.size() > 10)
    throw My_exception("Overflow");
  if (value.size() == 10)
    {
      if (value[0] > 4)
	throw My_exception("Overflow");
      if (value[0] == 4 && value[1] > 2)
	throw My_exception("Overflow");
    }
  std::istringstream (value) >> nb;
  if (type == 0 && nb > 255)
    throw My_exception("Overflow on int8");
  if (type == 1 && nb > 65535)
    throw My_exception("Overflow on int16");
}

template <typename T>
void	Operand<T>::check_underflow(const std::string &value, const int &type)
{
  int	nb;

  if (value.size() > 11)
    throw My_exception("Overflow");
  if (value.size() == 11)
    {
      if (value[0] == '-' && value[1] == 4)
	throw My_exception("Overflow");
      if (value[0] == 4 && value[1] > 2)
	throw My_exception("Overflow");
    }

  std::istringstream (value) >> nb;
  if (type == 0 && nb < -255)
    throw My_exception("Overflow on int8");
  if (type == 1 && nb < -65535)
    throw My_exception("Overflow on int16");
}

#endif /* OPERAND_HH_ */
