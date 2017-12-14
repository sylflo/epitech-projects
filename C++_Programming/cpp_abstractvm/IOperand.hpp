//
// IOperand.hh for  in /home/chatea_s/project/c++/abstrac_vm_part_1
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Wed Feb 19 12:34:05 2014 Sylvain Chateau
// Last update Sun Mar  2 21:20:35 2014 Sylvain Chateau
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

#include <iostream>

enum	eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
  };

class	IOperand
{
public:

  virtual std::string const & toString() const = 0;

  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;

  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand * operator-(const IOperand &rhs) const = 0;
  virtual IOperand * operator*(const IOperand &rhs) const = 0;
  virtual IOperand * operator/(const IOperand &rhs) const = 0;
  virtual IOperand * operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {}
};

#endif /* IOPERAND_HH_ */
