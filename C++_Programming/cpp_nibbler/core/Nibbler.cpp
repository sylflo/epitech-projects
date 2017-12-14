//
// Nibbler.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:43:39 2014 Sylvain Chateau
// Last update Sat Apr  5 13:32:03 2014 Sylvain Chateau
//

#include <unistd.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include "Nibbler.hpp"

Nibbler::Nibbler(Objlib &obj_lib, const ILib::t_size win_size)
{
  if ((this->lib = obj_lib.getClass()) == NULL)
    {
      std::cout << "Error obj" << std::endl;
      exit(1);
    }
  this->objLib = &obj_lib;
  if ((this->lib->initWindow(win_size)) == false)
    {
      std::cout << "Error init windows" << std::endl;
      exit(1);
    }
  this->direction = ILib::RIGTH;
  this->isFeed = true;
  this->sizeWin = win_size;
  this->initSnake(win_size);
  this->counter = 0;
  this->alive = true;
  this->pause = false;
  this->time = 50000;
  this->popFood();
}

void		Nibbler::initSnake(ILib::t_size win_size)
{
  t_element     element;

  element.position.y = win_size.heigth / 2;
  element.position.x = 4;
  element.type = ILib::SNAKE_HEAD;
  while (element.position.x >= 0)
    {
      this->snake.push_back(element);
      element.type = ILib::SNAKE;
      element.position.x -= 1;
    }
}

void		Nibbler::moveUp()
{
  if (this->direction == ILib::DOWN)
    return ;
  this->direction = ILib::UP;
}

void		Nibbler::moveDown()
{
  if (this->direction == ILib::UP)
    return ;
  this->direction = ILib::DOWN;
}

void		Nibbler::moveRigth()
{
  if (this->direction == ILib::LEFT)
    return ;
  this->direction = ILib::RIGTH;
}

void		Nibbler::moveLeft()
{
  if (this->direction == ILib::RIGTH)
    return ;
  this->direction = ILib::LEFT;
}

bool		Nibbler::check_case(const unsigned int position_x,
			   const unsigned int position_y)
{
  int		index;

  index = 0;
  while (index < (int)this->snake.size())
    {
      if ((int)this->snake[index].position.x == (int)position_x &&
	  (int)this->snake[index].position.y == (int)position_y)
	return (false);
      index++;
    }
  index = 0;
  while (index < (int)this->food.size())
    {
      if ((int)this->food[index].position.x == (int)position_x &&
	  (int)this->food[index].position.y == (int)position_y)
	return (false);
      index++;
    }
  return (true);
}

void		Nibbler::popFood()
{
  t_element	food;

  food.type = ILib::FOOD;
  if (this->isFeed == false)
    return ;
  food.position.x = rand() % this->sizeWin.width;
  food.position.y = rand() % this->sizeWin.heigth;
  while (this->check_case(food.position.x, food.position.y) == false)
    {
      food.position.x = rand() % this->sizeWin.width;
      food.position.y = rand() % this->sizeWin.heigth;
    }
  this->food.push_back(food);
}

void		        Nibbler::deplaceSnake()
{
  int			index;

  index = this->snake.size();
  while (index >= 0)
    {
      if (index > 0)
	{
	  this->snake[index].position.x = this->snake[index - 1].position.x;
	  this->snake[index].position.y = this->snake[index - 1].position.y;
	}
      else if (index == 0 &&
	       (this->direction == ILib::DOWN || this->direction == ILib::UP))
	{
	  if (this->direction == ILib::DOWN)
	    this->snake[0].position.y += 1;
	  else
	    this->snake[0].position.y -= 1;
	}
      else if (index == 0 &&
	       (this->direction == ILib::LEFT || this->direction == ILib::RIGTH))
	{
	  if (this->direction == ILib::LEFT)
	    this->snake[0].position.x -= 1;
	  else
	    this->snake[0].position.x += 1;
	}
      index--;
    }
}

void			Nibbler::moveSnake(const unsigned int move)
{
  FunctionPointer	tabPtr[4];

  tabPtr[0] = &Nibbler::moveUp;
  tabPtr[1] = &Nibbler::moveDown;
  tabPtr[2] = &Nibbler::moveLeft;
  tabPtr[3] = &Nibbler::moveRigth;
  (this->*tabPtr[move % 4])();
}

void		Nibbler::feedSnake()
{
  t_element	snake_add;
  int		number_food = (rand() % 3) + 1;

  snake_add.position.x = this->snake[this->snake.size() - 1].position.x;
  snake_add.position.y = this->snake[this->snake.size() - 1].position.y;
  if (this->direction == ILib::RIGTH || this->direction == ILib::LEFT)
    {
      if (this->direction == ILib::RIGTH)
	snake_add.position.x = this->snake[this->snake.size() - 1].position.x - 1;
      else
	snake_add.position.x = this->snake[this->snake.size() - 1].position.x - 1;
    }
  else
    {
      if (this->direction == ILib::UP)
	snake_add.position.y = this->snake[this->snake.size() - 1].position.y - 1;
      else
	snake_add.position.y = this->snake[this->snake.size() - 1].position.y + 1;
    }
  while (number_food-- >= 0)
    {
      snake_add.type = ILib::SNAKE;
      this->snake.push_back(snake_add);
    }
}

void		Nibbler::addBlock()
{
  t_element	block;

  block.position.x = rand() % this->sizeWin.width;
  block.position.y = rand() % this->sizeWin.heigth;
  while (this->check_case(block.position.x, block.position.y) == false)
    {
      block.position.x = rand() % this->sizeWin.width;
      block.position.y = rand() % this->sizeWin.heigth;
    }
  block.type = ILib::BLOCK;
  this->food.push_back(block);
}

bool		Nibbler::eatFood()
{
  int		index;

  index = 0;
  while (index < (int)this->food.size())
    {
      if (this->food[index].type == ILib::FOOD &&
	  this->snake[0].position.x == this->food[index].position.x &&
	  this->snake[0].position.y == this->food[index].position.y)
	{
	  this->food.erase(this->food.begin() + index);
	  return (true);
	}
      index++;
    }
  return (false);
}

void		Nibbler::collision()
{
  int		index;

  if (this->snake[0].position.x < 0 ||
      this->snake[0].position.x > (int)this->sizeWin.width ||
      this->snake[0].position.y < 0 ||
      this->snake[0].position.y > (int)this->sizeWin.heigth)
    this->alive = false;
  index = 1;
  while (index < (int)this->snake.size())
    {
      if (this->snake[0].position.x == this->snake[index].position.x &&
	  this->snake[0].position.y == this->snake[index].position.y)
	this->alive = false;
      index++;
    }
  index = 0;
  while (index < (int)this->food.size())
    {
      if (this->food[index].type == ILib::BLOCK &&
	  this->snake[0].position.x == this->food[index].position.x &&
	  this->snake[0].position.y == this->food[index].position.y)
	this->alive = false;
      index++;
    }
  if (this->eatFood() == true)
    {
      this->time -= 1000;
      this->counter += 1;
      this->feedSnake();
      this->isFeed = true;
      this->popFood();
      if (this->counter >= 10 && rand() % 5 == 1)
	this->popFood();
      this->isFeed = false;
      if (rand() % 2 == 1)
	this->addBlock();
    }
}

bool	        Nibbler::loadLibrairy(int lib)
{
  const char	*tab_lib[3] = {(const char *)"lib_Ncurses/lib_nibbler_ncurses.so",
			       (const char *)"lib_OpenGL/lib_nibbler_opengl.so",
			       (const char *)"lib_SFML/lib_nibbler_sfml.so"};

  this->lib->closeWindow();
  this->objLib = new Objlib(tab_lib[lib]);
  if ((this->lib = this->objLib->getClass()) == NULL)
    {
      std::cout << "Error obj" << std::endl;
      return (false);
    }
  if (this->lib->initWindow(this->sizeWin) == false)
    {
      std::cout << "Error init window" << std::endl;
      return (false);
    }
  return (true);
}

void		Nibbler::endGame() const
{
  this->lib->closeWindow();
  this->objLib->closeLib();
  std::cout << "\033[1;31mG A M E  O V E R\033[0m" << std::endl;
  std::cout << "\033[32mS C O R E : " << this->counter << "\033[0m" << std::endl;
}

void		Nibbler::loop()
{
  int	        key;

  while (this->alive == true)
    {
      key = this->lib->getEvent();
      if (key == ILib::QUIT)
  	{
  	  this->lib->closeWindow();
  	  return ;
  	}
      if (key == ILib::PAUSE)
	{
	  if (this->pause == false)
	    this->pause = true;
	  else
	    this->pause = false;
	}
      if (key >= ILib::LIB1 && key <= ILib::LIB3)
	if (this->loadLibrairy(key - ILib::LIB1) == false)
	  return ;
      this->collision();
      if (this->alive == true)
	{
	  if (this->pause == false)
	    {
	      if (key >= ILib::UP && key <= ILib::RIGTH)
		this->moveSnake(key);
	      this->deplaceSnake();
	      this->collision();
	    }
	  if (this->alive == true)
	    {
	      this->lib->display(this->snake, this->food, this->counter);
	      usleep(this->time);
	    }
	}
    }
  this->endGame();
}
