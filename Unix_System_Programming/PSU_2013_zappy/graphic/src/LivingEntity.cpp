//
// LivingEntity.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Thu Jun 26 10:47:26 2014 Arthur Coudert
// Last update Sun Jul 13 23:52:17 2014 Julian Caille
//

#include "LivingEntity.hh"

LivingEntity::LivingEntity(sf::Vector2u mapSize, int id, int x, int y, int o, int lvl, std::string teamName ,int type, Texture * text, Sound new_sound, int color){
  _mapSize = mapSize;
  _id = id;
  _lvl = lvl;
  _type = type;
  _pos = Vector3u(x, y, o);
  if (type == AI)
    _posRela = sf::Vector2i(rand() % 100 + 10, rand() % 100 + 10);
  else
    _posRela = sf::Vector2i(0,0);
  _color = color;
  _team = teamName;
  _incant = false;
  for (int i = 0; i < 7; i++)
    {
      _inventory.push_back(new Item(0, i));
      _inventory.back()->setPosRela(0);
    }
  _level.initializeAnimation(*text->spriteLabel("pikmin"), LEVEL, 50);
  _incantation.initializeAnimation(*text->spriteLabel("pikmin"), INCANT, 100);
  if (type == AI)
    _anim.initializeAnimation(*text->spriteLabel("pikmin"), _color, 50);
  if (type == EGG)
    _anim.initializeAnimation(*text->spriteLabel("egg"), EGG_IMATURE, 200);
  _Dir = 0;
  _nameLvl.push_back("level2");
  _nameLvl.push_back("level3");
  _nameLvl.push_back("level4");
  _nameLvl.push_back("level5");
  _nameLvl.push_back("level6");
  _nameLvl.push_back("level7");
  _nameLvl.push_back("level8");

  _caseType.push_back("grass");
  _caseType.push_back("dirt");
  _caseType.push_back("rock");
  _caseType.push_back("sand");
  _sound = new_sound;
  _animation = 0;
  _typeCase = 0;
}

LivingEntity::~LivingEntity(){
  while (_inventory.size() != 0)
    {
      delete _inventory.back();
      _inventory.pop_back();
    }
}

LivingEntity&		LivingEntity::operator+=(sf::Vector2u const &newposRela){
  _posRela.x += newposRela.x;
  _posRela.y += newposRela.y;
  if (_posRela.x >= 128)
    {
      _posRela.x -= 128;
      _pos.x++;
      if (_pos.x == _mapSize.x)
	_pos.x = 0;
    }
  if (_posRela.y >= 128)
    {
      _posRela.y -= 128;
      _pos.y++;
      if (_pos.y == _mapSize.y)
	_pos.y = 0;
    }
  return (*this);
}

LivingEntity&		LivingEntity::operator-=(sf::Vector2u const &newposRela){
  _posRela.x -= newposRela.x;
  _posRela.y -= newposRela.y;
  if (_posRela.x <= 0)
    {
      _posRela.x += 128;
      if (_pos.x >= 1)
	_pos.x--;
      else
	_pos.x = _mapSize.x - 1;
    }
  if (_posRela.y <= 0)
    {
      _posRela.y += 128;
      if (_pos.y >= 1)
	_pos.y--;
      else
	_pos.y = _mapSize.y - 1;
    }
  return (*this);
}

int		LivingEntity::getCurrentFrame() const
{
  return (_animation);
}

Sound		LivingEntity::getSound() const
{
  return (_sound);
}

int			LivingEntity::getColor() const
{
  return (_color);
}

std::string		LivingEntity::getNameLvl(int const &lvl) const
{
  return (_nameLvl[lvl]);
}
int			LivingEntity::getDir() const
{
  return (_Dir);
}

std::vector<Item*>	LivingEntity::getInventory() const{
  return (_inventory);
}

Vector3u		LivingEntity::getPos() const{
  return (_pos);
}

sf::Vector2i		LivingEntity::getPosRela() const{
  return (_posRela);
}

void			LivingEntity::setPosRela(sf::Vector2i posRela){
  _posRela = posRela;
}

Vector3u		LivingEntity::getPosDest() const{
  if (_posDest.size() == 0)
    return (Vector3u(42, 42, 42));
  return (_posDest.front());
}


int			LivingEntity::getLvl() const{
  return (_lvl);
}

int			LivingEntity::getId() const{
  return (_id);
}

std::string		LivingEntity::getLabelSound(int const &pos) const
{
  return (_caseType[pos]);
}

int			LivingEntity::getTypeCase() const
{
  return (_typeCase);
}

int			LivingEntity::getType() const{
  return (_type);
}

bool			LivingEntity::getIncant() const{
  return (_incant);
}

std::string		LivingEntity::getTeam() const{
  return (_team);
}

Animated		*LivingEntity::getAnim()
{
  return (&_anim);
}

Animated		*LivingEntity::getAnimLevel()
{
  return (&_level);
}

Animated		*LivingEntity::getAnimIncant()
{
  return (&_incantation);
}

unsigned int			LivingEntity::arrived(){
  if (_posDest.size() != 0)
    _posDest.pop_front();
  return (_posDest.size());
}

unsigned int			LivingEntity::length(){
  return (_posDest.size());
}

void			LivingEntity::setTypeCase(int const &set)
{
  _typeCase = set;
}

void			LivingEntity::setDir(int const &dir)
{
  _Dir = dir;
}

void			LivingEntity::setCurrentFrame(int const &iterator)
{
  _animation = iterator;
}

void			LivingEntity::setInventory(const std::vector<std::string> &command)
{
  for (int i = 0; i < 7; i++)
    _inventory[i]->setNbRes(atoi(command[i + 4].c_str()));
}

void			LivingEntity::setLvl(int lvl)
{
  _lvl = lvl;
}

void			LivingEntity::setPosDest(Vector3u newpos)
{
  _posDest.push_back(newpos);
}

void			LivingEntity::setIncant(bool incant){
  _incant = incant;
}

void			LivingEntity::setShit(Texture *text){
  _type = SHIT;
  _color = SHITTY;
  _team = "";
  _anim.initializeAnimation(*text->spriteLabel("shit"), _color, 200);
}

void			LivingEntity::setMature(Texture *text){
  _type = EGG;
  _color = EGG_MATURE;
  _anim.initializeAnimation(*text->spriteLabel("egg"), _color, 200);
}
