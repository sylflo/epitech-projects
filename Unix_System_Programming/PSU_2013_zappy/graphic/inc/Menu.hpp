//
// Menu.hpp for zappy in /home/storm/zappy/zappy
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 17:31:42 2014 Julian Caille
// Last update Tue Jul  1 18:19:32 2014 Julian Caille
//

#ifndef _MENU_HPP_
# define _MENU_HPP_

# include "Display.hpp"

class	Menu : public Display
{
public:
  Menu(sf::RenderWindow *window, Sound &sound, sf::Event &event,
       sf::View *view);
  ~Menu();
  virtual bool	initialize();
  virtual std::string	events();
  virtual void	show();
  void		animateLogo();
  void		animateBackground();
  void		easterEgg();
  void		faseOut();
  void		formatIp();
  void		writeInfos();
  void		fillIp(char c, const int &add, const int &dotreceived);
  std::string	formatedIp() const;
private:
  std::vector <std::string> _ip;
  sf::Clock	_clock;
  sf::Text	_text;
  sf::Font	_font;
  Texture	_textures;
  std::vector<std::string > _anim;
  std::vector<sf::IntRect > _frames;
  unsigned int		_current_frame;
  unsigned int		_current_back;
  bool		_decrease;
  bool		_soundOn;
  int		_logoSpeed;
  bool		_easterEgg;
  bool		_onEnter;
  bool		_accepted;
  bool		_info;
};

#endif /* !_MENU_HPP_ */
