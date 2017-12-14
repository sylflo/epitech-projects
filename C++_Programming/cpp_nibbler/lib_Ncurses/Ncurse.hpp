#ifndef NCURSE_H
# define NCURSE_H

# include <ncurses.h>
# include "../core/ILib.hpp"
# include <stdlib.h>

class			Ncurse : public ILib
{
private:
  WINDOW		*win;
  int			size_x;
  int			size_y;
  int			pos_x;
  int			pos_y;
public:
  virtual bool          initWindow(const ILib::t_size);
  virtual void          display(const std::vector<struct s_element> &list,
				const std::vector<struct s_element> &food, const int);
  virtual void          closeWindow() const;
  virtual key           getEvent() const;
  virtual void		draw_wall() const;
  virtual void		del_ncu() const;
};

#endif // NCURSE
