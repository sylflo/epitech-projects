//
// Menu.hpp for Menu in /home/storm/IA/Gomoku/inc
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:36:24 2014
// Last update Tue Nov 11 12:48:45 2014 caille_j
//

#ifndef _MENU_HPP_
# define _MENU_HPP_

# include "Display.hpp"

class	Menu : public Display
{
public:
  Menu(sf::RenderWindow *, Sound *, sf::Event *);
  ~Menu();
  virtual bool		initialize();
  const std::string	events();
  const std::string	parseOptions();
  void			show();
  bool		hotKeys(const sf::Event::EventType &type);
  void		showStatic();
  void		showWritten();
  void		homeScreen();
  void		optionsScreen();
  void		verifyPos();
private:
  short		subMenu;
  short		line;
  short		_mode;
  short		_option1;
  short		_option2;
  bool		_finish;
};

#endif /* !_MENU_HPP_ */
