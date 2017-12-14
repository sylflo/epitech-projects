//
// Read.cpp for  in /home/chatea_s/project/c++/vm/vm_in_building
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri Feb 28 13:39:17 2014 Sylvain Chateau
// Last update Fri Feb 28 13:40:31 2014 Sylvain Chateau
//

class Read
{
public:
  Read();
  ~Read();

public:
  bool    read_from_file(char **argv);
  bool    read_from_entry_standard(void);
};
