//
// MyInput.hpp for  in /home/chatea_s/cpp_bomberman
//
// Made by
// Login   <chatea_s@epitech.net>
//
// Started on  Sun May 18 15:12:44 2014
// Last update Fri Jun 13 15:39:22 2014 
//

#ifndef MYINPUT_H_
# define MYINPUT_H_

# include "SdlContext.hh"

extern double g_current_time;

namespace in
{
  class Input
  {
  public:
    Input();
    ~Input();

  public:
    void	updateEvents();
    bool	quit() const;
    bool	getKey(const SDL_Scancode) const;
    bool	getKeyUp(const SDL_Scancode) const;
    bool	getMouseButton(const Uint8) const;
    bool	mouseMove() const;
    int		getX() const;
    int		getY() const;
    int		getXRel() const;
    int		getYRel() const;
    void	printPointer(bool) const;
    void	capturePointer(bool) const;

  private:
    SDL_Event	_events;
    bool	_keys[SDL_NUM_SCANCODES];
    bool	_mouse[8];

  private:
    int		_x;
    int		_y;
    int		_xRel;
    int		_yRel;
    bool	_quit;
  };
}

#endif /* !MYINPUT_H_*/
