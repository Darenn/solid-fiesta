#ifndef __SNAFFLE_HPP_
#define __SNAFFLE_HPP_

#include "entity.hpp"

class Snaffle : public Entity {
private:
public:
  Snaffle(int _id, int _x, int _y) : Entity(_id, _x, _y){};
  virtual ~Snaffle();
};

#endif
