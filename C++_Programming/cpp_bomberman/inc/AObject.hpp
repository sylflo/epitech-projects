//
// AObject.hpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:12:53 2014 Sylvain Chateau
// Last update Sun Jun 15 21:52:26 2014 maxime duboy
//

#ifndef AOBJECT_H_
# define AOBJECT_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <AShader.hh>
#include <SdlContext.hh>
#include <Texture.hh>
#include <Geometry.hh>
#include "Input.hpp"

class AObject
{

public:
  enum
    {
      BLOCK,
      PLAYER_ONE,
      PLAYER_TWO,
      AI,
      UNBREAK,
      BOMB,
      FIRE,
      BONUS_RANGE,
      BONUS_BEMBS,
      BONUS_SPEED
    };

public:
  AObject();
  virtual ~AObject();

  virtual bool initialize() = 0;
  virtual int update(gdl::Clock const &clockinput, in::Input &, int &) = 0;
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock,
		    gdl::Texture * = NULL , gdl::Geometry * = NULL) = 0;

  void		translate(glm::vec3 const &v);
  void		rotate(glm::vec3 const& axis, const float &angle);
  void		scale(glm::vec3 const& scale);
  void		setTranslate(const int &posX, const int &posZ);
  glm::mat4	getTransformation();

  void	setPosX(const float &);
  void	setPosZ(const float &);
  void	setPosCase(const int &);
  float	getPosX() const;
  float	getPosZ() const;
  int	getType() const;
  int	getPosCase() const;

  void	setTimeWait(double const _set);
  bool	isFadeOut();
  bool	did_it_explode(int const &_mode);
  bool	wasItCrate(int const &_mode);

protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

protected:
  int		_type;
  float		_posX;
  float		_posZ;
  int		_sizeVertices;
  float		_vertices[108];
  gdl::Geometry _geometry;
  int		_pos_case;
  double	_timeWait;
  bool		_crate;

};

#endif /* !AOBJECT_H_*/
