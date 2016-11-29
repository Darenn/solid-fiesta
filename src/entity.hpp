#ifndef __ENTITY_HPP_
#define __ENTITY_HPP_

class Entity {
protected:
  int entityId;
  int x;
  int y;
  int vx;
  int vy;

public:
  Entity(int _entityId, int _x, int _y)
      : entityId(_entityId), x(_x), y(_y), vx(0), vy(0){};

  virtual ~Entity();

  void update(int _x, int _y, int _vx, int _vy) {
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
  }
};

#endif
