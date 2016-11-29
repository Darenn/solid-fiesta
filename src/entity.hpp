#ifndef __ENTITY_HPP_
#define __ENTITY_HPP_

class Entity {
protected:
  int id;
  int x;
  int y;
  int vx;
  int vy;
  int last_turn_update;

public:
  Entity(int _id) : id(_id), x(0), y(0), vx(0), vy(0), last_turn_update(0){};

  virtual ~Entity(){};

  void update(int _x, int _y, int _vx, int _vy, int _turn) {
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    last_turn_update = _turn;
  }

  int get_id() { return id; }

  int get_x() { return x; }
  int get_y() { return y; }

  int get_last_update() { return last_turn_update; }
};

#endif
