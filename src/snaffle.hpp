#ifndef __SNAFFLE_HPP_
#define __SNAFFLE_HPP_

#include "entity.hpp"

class Snaffle : public Entity {
private:
public:
  Snaffle(int _id) : Entity(_id){};

  virtual ~Snaffle(){};
};

#endif
