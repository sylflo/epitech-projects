//
// Exception.hpp for exception in /home/storm/spaceshooter/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Mon Jul 21 18:27:33 2014 Julian Caille
// Last update Mon Jul 21 18:30:38 2014 Julian Caille
//

#ifndef _EXCEPION_HPP_
# define _EXCEPION_HPP_

# include <iostream>
# include <stdexcept>

class	Exception : public std::runtime_error
{
public:
  Exception(const std::string &msg="") : std::runtime_error(msg) {}
};

#endif /* !_EXCEPTION_HPP_ */
