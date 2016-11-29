#ifndef __ENTITY_HPP_
#define __ENTITY_HPP_

class Entity {
protected:
  int x;
  int y;

public:
  Entity(int _x, int _y) : x(_x), y(_y){};

  virtual ~Entity();
};

#endif
