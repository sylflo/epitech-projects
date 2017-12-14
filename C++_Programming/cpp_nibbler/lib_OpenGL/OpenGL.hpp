//
// OpenGL.hpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Wed Apr  2 18:22:32 2014 Sylvain Chateau
// Last update Sat Apr  5 12:43:19 2014 Sylvain Chateau
//

#ifndef OPENGL_H_
# define OPENGL_H_

# include <SFML/Graphics.hpp>
# include <GL/glu.h>
# include "../core/ILib.hpp"

# define CASE 20

class		OpenGL : public ILib
{
private:
  sf::RenderWindow	*m_win;
  GLuint		m_body;
  GLuint		m_head;
  GLuint		m_food;
  GLuint		m_rock;
  GLuint		m_background;
  GLuint		m_wall;
  int			m_height;
  int			m_width;

public:
  virtual bool		initWindow(const ILib::t_size);
  virtual void		display(const std::vector<struct s_element> &,
				const std::vector<struct s_element> &, const int);
  virtual void		closeWindow() const;
  virtual ILib::key	getEvent() const;
};

#endif /* !OPENGL_H_*/
