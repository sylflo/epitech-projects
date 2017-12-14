//
// Menu.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 17:27:33 2014 Julian Caille
// Last update Tue Jul  1 18:38:20 2014 Julian Caille
//

#include "Menu.hpp"
#include <unistd.h>
#include <boost/lexical_cast.hpp>

Menu::Menu(sf::RenderWindow *window, Sound &sound, sf::Event &event,
	   sf::View *view)
{
  _window = window;
  _sound = sound;
  _event = event;
  _view = view;
  _soundOn = true;
  _decrease = false;
  _current_frame = 0;
  _logoSpeed = 450;
  _easterEgg = false;
  _onEnter = false;
  _accepted = false;
  _info = false;
  _current_back = 0;
}

Menu::~Menu()
{
}

bool	Menu::initialize()
{
  if (!_sound.newChannel("./sound/menu.ogg", "menu_main"))
    return (false);
  if (!_sound.newChannel("./sound/easter.flac", "Easter egg"))
    return (false);
  _sound.pauseChannel("Easter egg");
  if (!_font.loadFromFile("./Fonts/mojito.ttf"))
    return (false);
  _text.setFont(_font);
  if (!_textures.newTexture("Texture/menu/sound_on.png", "sound_on",
			    sf::IntRect(92, 92, 68, 68))
      || !_textures.newTexture("Texture/menu/background.png", "background1",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/sound_off.png", "sound_off",
			       sf::IntRect(92, 92, 68, 68))
      || !_textures.newTexture("Texture/menu/egg.tga", "Renard!",
			       sf::IntRect(0, 0, 300, 421))
      || !_textures.newTexture("Texture/menu/egg.tga", "Renard2!",
			       sf::IntRect(0, 0, 300, 421))
      || !_textures.newTexture("Texture/menu/egg.tga", "Renard3!",
			       sf::IntRect(0, 0, 300, 421))
      || !_textures.newTexture("Texture/menu/enter_dull.png", "enter dull",
			       sf::IntRect(0, 0, 658, 77))
      || !_textures.newTexture("Texture/menu/enter_bright.png", "enter bright",
			       sf::IntRect(0, 0, 671, 83))
      || !_textures.newTexture("Texture/menu/box.png", "box",
			       sf::IntRect(0, 0, 78, 59))
      || !_textures.newTexture("Texture/menu/info.png", "info",
			       sf::IntRect(0, 0, 80, 80))
      || !_textures.newTexture("Texture/menu/info_popup.png", "info_panel",
			       sf::IntRect(0, 0, 450, 600))
      || !_textures.newTexture("Texture/menu/animated_logo.png", "logo",
			       sf::IntRect(0, 0, 1000, 1000)))
    return (false);

  if (!_textures.newTexture("Texture/menu/anim_background/frame-1.gif", "1",
			    sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/anim_background/frame-2.gif", "2",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/anim_background/frame-3.gif", "3",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/anim_background/frame-4.gif", "4",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/anim_background/frame-5.gif", "5",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/anim_background/frame-6.gif", "6",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/menu/anim_background/frame-7.gif", "7",
			       sf::IntRect(0, 0, 1024, 768)))
    return (false);


  _anim.push_back("1");
  _anim.push_back("2");
  _anim.push_back("3");
  _anim.push_back("4");
  _anim.push_back("5");
  _anim.push_back("6");
  _anim.push_back("7");

  _textures.spriteLabel("sound_on")->setPosition(sf::Vector2f(950, 680));
  _textures.spriteLabel("sound_off")->setPosition(sf::Vector2f(950, 680));
  _textures.spriteLabel("logo")->setPosition(sf::Vector2f(300, 50));
  _textures.spriteLabel("info")->setPosition(sf::Vector2f(20, 680));
  _textures.spriteLabel("Renard!")->setPosition(sf::Vector2f(250, 200));
  _textures.spriteLabel("Renard2!")->setPosition(sf::Vector2f(800, 200));
  _textures.spriteLabel("Renard3!")->setPosition(sf::Vector2f(400, 250));
  _textures.spriteLabel("enter dull")->setPosition(sf::Vector2f(190, 400));
  _textures.spriteLabel("enter bright")->setPosition(sf::Vector2f(190, 400));
  _textures.spriteLabel("info_panel")->setPosition(sf::Vector2f(300, 70));

  _textures.spriteLabel("Renard2!")->setOrigin(sf::Vector2f(150, 210));
  _textures.spriteLabel("Renard!")->setOrigin(sf::Vector2f(150, 210));

  _frames.push_back(sf::IntRect(0, 0, 378, 108));
  _frames.push_back(sf::IntRect(370, 0, 378, 108));
  _frames.push_back(sf::IntRect(0, 110, 360, 108));
  _frames.push_back(sf::IntRect(360 , 110, 378, 108));
  _frames.push_back(sf::IntRect(0, 220, 355, 108));
  _frames.push_back(sf::IntRect(360 , 220, 378, 108));
  _frames.push_back(sf::IntRect(0, 330, 355, 108));
  _frames.push_back(sf::IntRect(360 , 330, 378, 108));
  _frames.push_back(sf::IntRect(0, 440, 360, 108));
  _frames.push_back(sf::IntRect(360 , 440, 378, 108));
  _frames.push_back(sf::IntRect(0, 550, 360, 108));
  _frames.push_back(sf::IntRect(360 , 550, 378, 108));

  return (true);
}

void		Menu::animateBackground()
{
  if (_current_back < 5)
    _current_back++;
  else
    _current_back = 0;
}

void	Menu::animateLogo()
{
  static int kek = 0;

  if ((_clock.getElapsedTime().asMilliseconds() >=_logoSpeed / 2) && kek != 1 &&
      !_easterEgg)
    {
      animateBackground();
      kek++;
    }
  if (_clock.getElapsedTime().asMilliseconds() >= _logoSpeed)
    {
      if (!_easterEgg)
	kek = 0;
      if (_current_frame < _frames.size() && !_decrease)
	_current_frame++;
      if (_current_frame >= _frames.size() || _decrease)
	{
	  if (_current_frame > 0)
	    {
	      _decrease = true;
	      _current_frame--;
	    }
	  else
	    _decrease = false;
	}
      _textures.spriteLabel("logo")->setTextureRect(_frames[_current_frame]);
      if (_easterEgg)
	{
	  if (_clock.getElapsedTime().asMilliseconds() >= 450)
	    {
	      _textures.spriteLabel("Renard!")->rotate(25);
	      _textures.spriteLabel("Renard2!")->rotate(-25);
	      _clock.restart();
	      if (!kek)
		{
		  _view->zoom(0.5f);
		  kek++;
		}
	      else
		{
		  _view->zoom(2.0f);
		  kek--;
		}
	    }
	}
      else
	{
	  _view->reset(sf::FloatRect(0, 0, 1024, 768));
	  _clock.restart();
	}
    }
}

void	Menu::formatIp()
{
  unsigned int i;
  unsigned int pos;

  i = 0;
  pos = 285;
  if (!_ip.empty())
    {
      while (i < _ip.size())
	{
	  _text.setPosition(pos, 305);
	  _text.setString(_ip[i]);
	  _window->draw(_text);
	  if (i == 4)
	    pos += 85;
	  else
	    pos += 100;
	  i++;
	}
    }
}

void	Menu::writeInfos()
{
  _text.setColor(sf::Color::Red);
  _text.setPosition(330, 130);
  _text.setString("Bienvenue sur le Zappy !");
  _window->draw(_text);
  _text.setColor(sf::Color::Blue);
  _text.setPosition(360, 190);
  _text.setString("Pour rentrer une IP");
  _window->draw(_text);
  _text.setPosition(360, 220);
  _text.setString("appuyez directement");
  _window->draw(_text);
  _text.setPosition(330, 250);
  _text.setString("sur les chiffres du clavier");
  _window->draw(_text);
  _text.setPosition(310, 280);
  _text.setString("ou appuyez soit sur espace");
  _window->draw(_text);
  _text.setPosition(320, 310);
  _text.setString("soit point pour passer a");
  _window->draw(_text);
  _text.setPosition(410, 340);
  _text.setString("l\'autre bulle !");
  _window->draw(_text);
  _text.setPosition(360, 410);
  _text.setString("Le menu contient un");
  _window->draw(_text);
  _text.setPosition(380, 440);
  _text.setString("easter egg cache !");
  _window->draw(_text);
  _text.setColor(sf::Color::White);
}

void	Menu::show()
{
  _window->clear();
  _window->draw(*_textures.spriteLabel(_anim[_current_back].c_str()));
  animateLogo();
  if (_easterEgg)
    {
      _window->draw(*_textures.spriteLabel("Renard!"));
      _window->draw(*_textures.spriteLabel("Renard2!"));
    }
  _textures.spriteLabel("box")->setPosition(sf::Vector2f(280, 300));
  _window->draw(*_textures.spriteLabel("box"));
  _textures.spriteLabel("box")->setPosition(sf::Vector2f(380, 300));
  _window->draw(*_textures.spriteLabel("box"));
  _textures.spriteLabel("box")->setPosition(sf::Vector2f(480, 300));
  _window->draw(*_textures.spriteLabel("box"));
  _textures.spriteLabel("box")->setPosition(sf::Vector2f(580, 300));
  _window->draw(*_textures.spriteLabel("box"));
  _textures.spriteLabel("box")->setPosition(sf::Vector2f(680, 300));
  _window->draw(*_textures.spriteLabel("box"));
  _text.setPosition(400, 250);
  _text.setString("Adresse IP");
  _window->draw(_text);
  _text.setPosition(680, 250);
  _text.setString("Port");
  _window->draw(_text);
  formatIp();
  if (_soundOn)
    _window->draw(*_textures.spriteLabel("sound_on"));
  else
    _window->draw(*_textures.spriteLabel("sound_off"));
  _window->draw(*_textures.spriteLabel("info"));
  _window->draw(*_textures.spriteLabel("logo"));
  if (_onEnter)
    _window->draw(*_textures.spriteLabel("enter bright"));
  else
    _window->draw(*_textures.spriteLabel("enter dull"));
  if (_easterEgg)
    _window->draw(*_textures.spriteLabel("Renard3!"));
  if (_info)
    {
      _window->draw(*_textures.spriteLabel("info_panel"));
      writeInfos();
    }
  _window->setView(*_view);
  _window->display();
}

void	Menu::fillIp(char c, const int &add, const int &dotreceived)
{
  unsigned int i;

  i = 0;
  if (add)
    {
      _ip.size() <= 1 ? i = 0 : i = _ip.size() - 1;
      if (i < 5)
	{
	  if (dotreceived == 1)
	    {
	      if (!_ip.empty())
		{
		  if (i + 1 < 5)
		    {
		      if (!_ip[i].empty())
			_ip.push_back(&c);
		    }
		}
	      return ;
	    }
	  if (i != 4)
	    {
	      if (_ip.empty() || _ip[i].size() >= 3)
		_ip.push_back(boost::lexical_cast<std::string>(c));
	      else
		_ip[i] += boost::lexical_cast<std::string>(c);
	    }
	  else
	    {
	      if (_ip[i].size() <= 4)
		_ip[i] += boost::lexical_cast<std::string>(c);
	    }
	}
    }
  else
    {
      _ip.size() <= 1 ? i = 0 : i = _ip.size() - 1;
      if (!_ip.empty())
	{
	  if (!_ip[i].empty())
	    {
	      _ip[i].resize(_ip[i].size() - 1);
	      if (_ip[i].empty())
		_ip.pop_back();
	    }
	}
    }
}

std::string	Menu::formatedIp() const
{
  unsigned int i;
  std::string finished;

  i = 0;
  while (i < _ip.size())
    {
      finished += _ip[i];
      if (i == 3)
	finished += ":";
      else if (i < 3)
	finished += ".";
      i++;
    }
  return (finished);
}

std::string	Menu::events()
{
  sf::Vector2i _localPosition = sf::Mouse::getPosition(*_window);

  if (_window->isOpen())
    {
      if (_window->pollEvent(_event))
	{
	  if (_event.type == sf::Event::Closed ||
	      ((_event.type == sf::Event::KeyPressed) &&
	      (_event.key.code == sf::Keyboard::Escape)))
	    {
	      _window->close();
	      return ("quit");
	    }
	  if (((_event.type == sf::Event::KeyPressed) &&
	       _event.key.code == sf::Keyboard::BackSpace))
	    fillIp(0, 0, 0);
	  if (_event.type == sf::Event::TextEntered)
	    {
	      if (_event.text.unicode >= 48 && _event.text.unicode <= 57)
		fillIp(static_cast<char>(_event.text.unicode), 1, 0);
	      else if (_event.text.unicode == 46 || _event.text.unicode == 32)
		fillIp(0, 1, 1);
	    }
	  if ((_event.type == sf::Event::KeyPressed) &&
	      (_event.key.code == sf::Keyboard::Return))
	    {
	      if (!_ip.empty())
		_accepted = true;
	    }
	  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 64 &&
	      _localPosition.y >= 680 && _localPosition.y <= 680 + 64 &&
	      sf::Mouse::isButtonPressed(sf::Mouse::Left))
	    {
	      usleep(100000);
	      _soundOn = !_soundOn;
	      _soundOn == false ? _sound.pauseChannel("menu_main") :
		_sound.resumeChannel("menu_main");
	    }
	  if (_localPosition.x >= 20 && _localPosition.x <= 20 + 80 &&
	      _localPosition.y >= 680 && _localPosition.y <= 680 + 80 &&
	      sf::Mouse::isButtonPressed(sf::Mouse::Left))
	    {
	      usleep(100000);
	      _info = !_info;
	    }
	  if (_localPosition.x >= 333 && _localPosition.x <= 333 + 80 &&
	      _localPosition.y >= 500 && _localPosition.y <= 570 &&
	      sf::Mouse::isButtonPressed(sf::Mouse::Left))
	    {
	      usleep(100000);
	      _easterEgg = !_easterEgg;
	      _easterEgg == true ? _logoSpeed = 1 : _logoSpeed = 450;
	      if (_easterEgg)
		{
		  _sound.resumeChannel("Easter egg");
		  _sound.pauseChannel("menu_main");
		}
	      else
		{
		  _sound.resumeChannel("menu_main");
		  _sound.pauseChannel("Easter egg");
		}
	    }
	  if (_localPosition.x >= 190 && _localPosition.x <= 190 + 658 &&
	      _localPosition.y >= 400 && _localPosition.y <= 400 + 77)
	    {
	      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		if (!_ip.empty())
		  _accepted = true;
	      _onEnter = true;
	    }
	  else
	    _onEnter = false;
	}
      if (_accepted)
	{
	  _window->clear();
	  _window->display();
	  _sound.removeAll();
	  return (formatedIp());
	}
      return ("continue");
    }
  return ("quit");
}
