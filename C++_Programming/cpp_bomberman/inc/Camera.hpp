//
// Camera.hpp for  in /home/chatea_s/cpp_bomberman
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri May  9 14:21:27 2014 Sylvain Chateau
// Last update Wed Jun 11 19:56:11 2014 
//

#ifndef CAMERA_H_
# define CAMERA_H_

# include <vector>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <SdlContext.hh>
# include "AObject.hpp"
# include "Input.hpp"

class Camera
{
public:
  Camera(const glm::vec3 &, const glm::vec3 &, const glm::vec3 &,
	 const int &, const int &, const SDL_Scancode &, const SDL_Scancode &,
	 const SDL_Scancode &, const SDL_Scancode &);
  ~Camera();

public:
  void			move(in::Input &, const gdl::Clock &, const float &);
  void			lookAt(glm::mat4 &);
  std::list<int>	find_around(const int &posX, const int &posZ, const int &i);
  std::list<int>	down(const int &posX, const int &posY, const int &);
  std::list<int>	up(const int &posX, const int &posY, const int &);

private:
  float		_phi;
  float		_theta;
  float		_speed;
  const int	_width;
  const int	_height;
  glm::vec3	_orientation;
  glm::vec3	_verticalAxis;
  glm::vec3	_lateralMove;
  glm::vec3	_position;
  glm::vec3	_target;
  SDL_Scancode	_left;
  SDL_Scancode	_right;
  SDL_Scancode	_up;
  SDL_Scancode	_down;
};

#endif /* !CAMERA_H_*/
