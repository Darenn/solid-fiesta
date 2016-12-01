#ifndef __ENTITY_HPP_
#define __ENTITY_HPP_

#include <vector>

class Entity {
protected:
  int id;
  int last_turn_update;
  std::vector<int> pos;
  std::vector<int> velocity;

public:
  Entity(int _id) : id(_id), last_turn_update(0) {
    pos.push_back(0);
    pos.push_back(0);
    velocity.push_back(0);
    velocity.push_back(0);
  };

  virtual ~Entity(){};

  void update(int _x, int _y, int _vx, int _vy, int _turn) {
    pos[0] = _x;
    pos[1] = _y;
    velocity[0] = _vx;
    velocity[1] = _vy;
    last_turn_update = _turn;
  }

  int get_id() { return id; }
  std::vector<int> get_pos() { return pos; };
  std::vector<int> get_velocity() { return velocity; };

  int get_last_update() { return last_turn_update; }
};

#endif
