//
// InitializeAnimations.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Tue Jul  1 15:36:06 2014 Julian Caille
// Last update Sat Jul 12 20:14:55 2014 Julian Caille
//

#include "Game.hpp"

void	Animated::initializeRed(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "red", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(10, 132, 30, 45));
  _frames->push_back(sf::IntRect(37, 133, 30, 45));
  _frames->push_back(sf::IntRect(10, 132, 30, 45));
  _frames->push_back(sf::IntRect(65, 132, 30, 45));
   addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(15, 176, 27, 45));
  _frames2->push_back(sf::IntRect(37, 176, 27, 45));
  _frames2->push_back(sf::IntRect(15, 176, 27, 45));
  _frames2->push_back(sf::IntRect(60, 176, 27, 45));
  addNewAnimation("right", _frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(10, 219, 30, 46));
  _frames3->push_back(sf::IntRect(37, 220, 30, 46));
  _frames3->push_back(sf::IntRect(10, 219, 30, 46));
  _frames3->push_back(sf::IntRect(65, 219, 30, 45));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(58, 268, 27, 46));
  _frames4->push_back(sf::IntRect(36, 268, 27, 46));
  _frames4->push_back(sf::IntRect(58, 268, 27, 46));
  _frames4->push_back(sf::IntRect(13, 268, 27, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(10, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeYellow(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "yellow", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(100, 132, 29, 46));
  _frames->push_back(sf::IntRect(127, 133, 30, 46));
  _frames->push_back(sf::IntRect(100, 132, 29, 46));
  _frames->push_back(sf::IntRect(155, 132, 30, 46));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(104, 176, 27, 45));
  _frames2->push_back(sf::IntRect(126, 176, 27, 45));
  _frames2->push_back(sf::IntRect(104, 176, 27, 45));
  _frames2->push_back(sf::IntRect(149, 176, 27, 45));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(100, 219, 30, 46));
  _frames3->push_back(sf::IntRect(127, 220, 30, 46));
  _frames3->push_back(sf::IntRect(100, 219, 30, 46));
  _frames3->push_back(sf::IntRect(155, 219, 30, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(149, 267, 27, 46));
  _frames4->push_back(sf::IntRect(127, 267, 27, 46));
  _frames4->push_back(sf::IntRect(149, 267, 27, 46));
  _frames4->push_back(sf::IntRect(104, 267, 27, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(100, 132, 29, 46));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeBlue(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "blue", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(200, 132, 30, 45));
  _frames->push_back(sf::IntRect(227, 133, 30, 45));
  _frames->push_back(sf::IntRect(200, 132, 30, 45));
  _frames->push_back(sf::IntRect(255, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(204, 175, 27, 45));
  _frames2->push_back(sf::IntRect(226, 175, 27, 45));
  _frames2->push_back(sf::IntRect(204, 175, 27, 45));
  _frames2->push_back(sf::IntRect(249, 175, 27, 45));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(200, 219, 30, 46));
  _frames3->push_back(sf::IntRect(227, 220, 30, 46));
  _frames3->push_back(sf::IntRect(200, 219, 30, 46));
  _frames3->push_back(sf::IntRect(255, 219, 30, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(249, 267, 27, 46));
  _frames4->push_back(sf::IntRect(227, 267, 26, 46));
  _frames4->push_back(sf::IntRect(249, 267, 27, 46));
  _frames4->push_back(sf::IntRect(204, 267, 26, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(200, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeDarkBlue(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "purple", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(280, 132, 30, 45));
  _frames->push_back(sf::IntRect(307, 133, 30, 45));
  _frames->push_back(sf::IntRect(280, 132, 30, 45));
  _frames->push_back(sf::IntRect(335, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(287, 177, 27, 45));
  _frames2->push_back(sf::IntRect(309, 177, 27, 45));
  _frames2->push_back(sf::IntRect(287, 177, 27, 45));
  _frames2->push_back(sf::IntRect(332, 177, 27, 45));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(280, 219, 30, 46));
  _frames3->push_back(sf::IntRect(307, 220, 30, 46));
  _frames3->push_back(sf::IntRect(280, 219, 30, 46));
  _frames3->push_back(sf::IntRect(335, 219, 30, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(329, 267, 27, 46));
  _frames4->push_back(sf::IntRect(307, 267, 27, 46));
  _frames4->push_back(sf::IntRect(329, 267, 27, 46));
  _frames4->push_back(sf::IntRect(284, 267, 27, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(280, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeGrey(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "grey", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(374, 132, 28, 45));
  _frames->push_back(sf::IntRect(401, 133, 30, 45));
  _frames->push_back(sf::IntRect(374, 132, 28, 45));
  _frames->push_back(sf::IntRect(429, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(378, 177, 25, 45));
  _frames2->push_back(sf::IntRect(423, 177, 25, 45));
  _frames2->push_back(sf::IntRect(378, 177, 25, 45));
  _frames2->push_back(sf::IntRect(400, 177, 25, 45));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(374, 219, 27, 46));
  _frames3->push_back(sf::IntRect(401, 220, 27, 46));
  _frames3->push_back(sf::IntRect(374, 219, 27, 46));
  _frames3->push_back(sf::IntRect(429, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(423, 267, 25, 46));
  _frames4->push_back(sf::IntRect(378, 267, 25, 46));
  _frames4->push_back(sf::IntRect(423, 267, 25, 46));
  _frames4->push_back(sf::IntRect(401, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(374, 132, 28, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeLightBlue(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "light blue", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(454, 132, 30, 45));
  _frames->push_back(sf::IntRect(481, 133, 30, 45));
  _frames->push_back(sf::IntRect(454, 132, 30, 45));
  _frames->push_back(sf::IntRect(509, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(458, 177, 25, 45));
  _frames2->push_back(sf::IntRect(503, 177, 25, 45));
  _frames2->push_back(sf::IntRect(458, 177, 25, 45));
  _frames2->push_back(sf::IntRect(480, 177, 25, 45));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(454, 219, 27, 46));
  _frames3->push_back(sf::IntRect(481, 220, 27, 46));
  _frames3->push_back(sf::IntRect(454, 219, 27, 46));
  _frames3->push_back(sf::IntRect(509, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(503, 267, 25, 46));
  _frames4->push_back(sf::IntRect(458, 267, 25, 46));
  _frames4->push_back(sf::IntRect(503, 267, 25, 46));
  _frames4->push_back(sf::IntRect(481, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(454, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeBrown(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "brown", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(544, 132, 30, 45));
  _frames->push_back(sf::IntRect(571, 133, 30, 45));
  _frames->push_back(sf::IntRect(544, 132, 30, 45));
  _frames->push_back(sf::IntRect(599, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(553, 177, 25, 45));
  _frames2->push_back(sf::IntRect(598, 177, 25, 45));
  _frames2->push_back(sf::IntRect(553, 177, 25, 45));
  _frames2->push_back(sf::IntRect(575, 177, 25, 45));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(544, 219, 27, 46));
  _frames3->push_back(sf::IntRect(571, 220, 27, 46));
  _frames3->push_back(sf::IntRect(544, 219, 27, 46));
  _frames3->push_back(sf::IntRect(599, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(593, 267, 25, 46));
  _frames4->push_back(sf::IntRect(548, 267, 25, 46));
  _frames4->push_back(sf::IntRect(593, 267, 25, 46));
  _frames4->push_back(sf::IntRect(571, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(544, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeOrange(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "brown", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(634, 132, 30, 45));
  _frames->push_back(sf::IntRect(661, 133, 30, 45));
  _frames->push_back(sf::IntRect(634, 132, 30, 45));
  _frames->push_back(sf::IntRect(689, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(641, 177, 25, 44));
  _frames2->push_back(sf::IntRect(686, 177, 25, 44));
  _frames2->push_back(sf::IntRect(641, 177, 25, 44));
  _frames2->push_back(sf::IntRect(663, 177, 25, 44));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(634, 219, 27, 46));
  _frames3->push_back(sf::IntRect(661, 220, 27, 46));
  _frames3->push_back(sf::IntRect(634, 219, 27, 46));
  _frames3->push_back(sf::IntRect(689, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(683, 267, 25, 46));
  _frames4->push_back(sf::IntRect(638, 267, 25, 46));
  _frames4->push_back(sf::IntRect(683, 267, 25, 46));
  _frames4->push_back(sf::IntRect(661, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(634, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializePink(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "pink", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(724, 132, 30, 45));
  _frames->push_back(sf::IntRect(751, 133, 30, 45));
  _frames->push_back(sf::IntRect(724, 132, 30, 45));
  _frames->push_back(sf::IntRect(779, 132, 30, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(731, 177, 25, 44));
  _frames2->push_back(sf::IntRect(776, 177, 25, 44));
  _frames2->push_back(sf::IntRect(731, 177, 25, 44));
  _frames2->push_back(sf::IntRect(753, 177, 25, 44));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(724, 219, 27, 46));
  _frames3->push_back(sf::IntRect(751, 219, 27, 46));
  _frames3->push_back(sf::IntRect(724, 219, 27, 46));
  _frames3->push_back(sf::IntRect(779, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(773, 267, 25, 46));
  _frames4->push_back(sf::IntRect(728, 267, 25, 46));
  _frames4->push_back(sf::IntRect(773, 267, 25, 46));
  _frames4->push_back(sf::IntRect(751, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(724, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeGreen(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "green", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(814, 132, 28, 45));
  _frames->push_back(sf::IntRect(841, 133, 29, 45));
  _frames->push_back(sf::IntRect(814, 132, 28, 45));
  _frames->push_back(sf::IntRect(869, 132, 29, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(821, 177, 24, 44));
  _frames2->push_back(sf::IntRect(866, 177, 24, 44));
  _frames2->push_back(sf::IntRect(821, 177, 24, 44));
  _frames2->push_back(sf::IntRect(843, 177, 24, 44));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(814, 219, 27, 46));
  _frames3->push_back(sf::IntRect(841, 220, 27, 46));
  _frames3->push_back(sf::IntRect(814, 219, 27, 46));
  _frames3->push_back(sf::IntRect(869, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(863, 267, 25, 46));
  _frames4->push_back(sf::IntRect(818, 267, 25, 46));
  _frames4->push_back(sf::IntRect(863, 267, 25, 46));
  _frames4->push_back(sf::IntRect(841, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(814, 132, 28, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeBlack(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "green", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(904, 132, 29, 45));
  _frames->push_back(sf::IntRect(931, 133, 29, 45));
  _frames->push_back(sf::IntRect(904, 132, 29, 45));
  _frames->push_back(sf::IntRect(959, 132, 29, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(911, 177, 24, 44));
  _frames2->push_back(sf::IntRect(956, 177, 24, 44));
  _frames2->push_back(sf::IntRect(911, 177, 24, 44));
  _frames2->push_back(sf::IntRect(933, 177, 24, 44));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(904, 219, 27, 46));
  _frames3->push_back(sf::IntRect(931, 220, 27, 46));
  _frames3->push_back(sf::IntRect(904, 219, 27, 46));
  _frames3->push_back(sf::IntRect(959, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(953, 267, 25, 46));
  _frames4->push_back(sf::IntRect(908, 267, 25, 46));
  _frames4->push_back(sf::IntRect(953, 267, 25, 46));
  _frames4->push_back(sf::IntRect(931, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(904, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializePurple(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "green", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(984, 132, 29, 45));
  _frames->push_back(sf::IntRect(1011, 133, 29, 45));
  _frames->push_back(sf::IntRect(984, 132, 29, 45));
  _frames->push_back(sf::IntRect(1039, 132, 29, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(991, 177, 24, 44));
  _frames2->push_back(sf::IntRect(1036, 177, 24, 44));
  _frames2->push_back(sf::IntRect(991, 177, 24, 44));
  _frames2->push_back(sf::IntRect(1013, 177, 24, 44));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(984, 219, 27, 46));
  _frames3->push_back(sf::IntRect(1011, 220, 27, 46));
  _frames3->push_back(sf::IntRect(984, 219, 27, 46));
  _frames3->push_back(sf::IntRect(1039, 219, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(1033, 267, 25, 46));
  _frames4->push_back(sf::IntRect(988, 267, 25, 46));
  _frames4->push_back(sf::IntRect(1033, 267, 25, 46));
  _frames4->push_back(sf::IntRect(1011, 267, 25, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(984, 132, 30, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeWhite(sf::Sprite sprite, int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;

  setSprite(sprite, "green", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(1074, 132, 29, 45));
  _frames->push_back(sf::IntRect(1101, 133, 29, 45));
  _frames->push_back(sf::IntRect(1074, 132, 29, 45));
  _frames->push_back(sf::IntRect(1129, 132, 29, 45));
  addNewAnimation("forward", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(1081, 177, 21, 44));
  _frames2->push_back(sf::IntRect(1126, 177, 21, 44));
  _frames2->push_back(sf::IntRect(1081, 177, 21, 44));
  _frames2->push_back(sf::IntRect(1103, 177, 21, 44));
  addNewAnimation("right",_frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(1074, 220, 27, 46));
  _frames3->push_back(sf::IntRect(1101, 220, 27, 46));
  _frames3->push_back(sf::IntRect(1074, 220, 27, 46));
  _frames3->push_back(sf::IntRect(1129, 220, 27, 46));
  addNewAnimation("backward", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(1123, 267, 24, 46));
  _frames4->push_back(sf::IntRect(1078, 267, 24, 46));
  _frames4->push_back(sf::IntRect(1123, 267, 24, 46));
  _frames4->push_back(sf::IntRect(1101, 267, 24, 46));
  addNewAnimation("left", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(1074, 132, 29, 45));
  addNewAnimation("static", _frames5);
}

void	Animated::initializeShit(sf::Sprite sprite,
				 int const &timer)
{
  std::vector<sf::IntRect > *_frames;

  setSprite(sprite, "shit", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(0, 0, 29, 43));
  _frames->push_back(sf::IntRect(29, 0, 29, 43));
  _frames->push_back(sf::IntRect(58, 0, 29, 43));
  _frames->push_back(sf::IntRect(87, 0, 29, 43));
  _frames->push_back(sf::IntRect(116, 0, 29, 43));
  addNewAnimation("shit", _frames);
}

void	Animated::initializeEggImature(sf::Sprite sprite,
				int const &timer)
{
  std::vector<sf::IntRect > *_frames;

  setSprite(sprite, "egg", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(0, 0, 32, 36));
  getSprite()->scale(sf::Vector2f(0.5f, 0.5f));
  getSprite()->setColor(sf::Color(100, 100, 100));
  addNewAnimation("egg_close", _frames);
}

void	Animated::initializeEggMature(sf::Sprite sprite,
				int const &timer)
{
  std::vector<sf::IntRect > *_frames;

  setSprite(sprite, "egg", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(0, 0, 32, 36));
  _frames->push_back(sf::IntRect(32, 0, 32, 36));
  _frames->push_back(sf::IntRect(0, 0, 32, 36));
  _frames->push_back(sf::IntRect(64, 0, 32, 36));
  getSprite()->scale(sf::Vector2f(0.5f, 0.5f));
  addNewAnimation("egg", _frames);
}

void	Animated::initializeLevel(sf::Sprite sprite,
				int const &timer)
{
  std::vector<sf::IntRect > *_frames;
  std::vector<sf::IntRect > *_frames2;
  std::vector<sf::IntRect > *_frames3;
  std::vector<sf::IntRect > *_frames4;
  std::vector<sf::IntRect > *_frames5;
  std::vector<sf::IntRect > *_frames6;
  std::vector<sf::IntRect > *_frames7;

  setSprite(sprite, "levels", timer);
  getSprite()->setOrigin(4.0f, 40.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(6, 7, 26, 26));
  addNewAnimation("level2", _frames);
  _frames2 = new std::vector<sf::IntRect >;
  _frames2->push_back(sf::IntRect(34, 7, 26, 26));
  addNewAnimation("level3", _frames2);
  _frames3 = new std::vector<sf::IntRect >;
  _frames3->push_back(sf::IntRect(60, 7, 26, 26));
  addNewAnimation("level4", _frames3);
  _frames4 = new std::vector<sf::IntRect >;
  _frames4->push_back(sf::IntRect(86, 7, 26, 26));
  addNewAnimation("level5", _frames4);
  _frames5 = new std::vector<sf::IntRect >;
  _frames5->push_back(sf::IntRect(114, 7, 26, 26));
  addNewAnimation("level6", _frames5);
  _frames6 = new std::vector<sf::IntRect >;
  _frames6->push_back(sf::IntRect(135, 6, 26, 26));
  addNewAnimation("level7", _frames6);
  _frames7 = new std::vector<sf::IntRect >;
  _frames7->push_back(sf::IntRect(165, 6, 26, 26));
  addNewAnimation("level8", _frames7);
}

void	Animated::initializeIncant(sf::Sprite sprite,
				int const &timer)
{
  std::vector<sf::IntRect > *_frames;

  setSprite(sprite, "incant", timer);
  getSprite()->setOrigin(10.0f, 30.0f);
  getSprite()->setScale(2.0f, 2.0f);
  _frames = new std::vector<sf::IntRect >;
  _frames->push_back(sf::IntRect(191, 7, 36, 36));
  getSprite()->scale(sf::Vector2f(0.5f, 0.5f));
  addNewAnimation("incant", _frames);
}

void	Animated::initializeAnimation(sf::Sprite sprite,
				      int const &team, int const &timer)
{
  if (team == SHITTY)
    initializeShit(sprite, timer);
  else if (team == EGG_MATURE)
    initializeEggMature(sprite, timer);
  else if (team == EGG_IMATURE)
    initializeEggImature(sprite, timer);
  else if (team == RED)
    initializeRed(sprite, timer);
  else if (team == YELLOW)
    initializeYellow(sprite, timer);
  else if (team == BLUE)
    initializeBlue(sprite, timer);
  else if (team == DARK_BLUE)
    initializeDarkBlue(sprite, timer);
  else if (team == GREY)
    initializeGrey(sprite, timer);
  else if (team == LIGHT_BLUE)
    initializeLightBlue(sprite, timer);
  else if (team == BROWN)
    initializeBrown(sprite, timer);
  else if (team == ORANGE)
    initializeOrange(sprite, timer);
  else if (team == PINK)
    initializePink(sprite, timer);
  else if (team == GREEN)
    initializeGreen(sprite, timer);
  else if (team == BLACK)
    initializeBlack(sprite, timer);
  else if (team == PURPLE)
    initializePurple(sprite, timer);
  else if (team == WHITE)
    initializeWhite(sprite, timer);
  else if (team == LEVEL)
    initializeLevel(sprite, timer);
  else if (team == INCANT)
    initializeIncant(sprite, timer);
}
