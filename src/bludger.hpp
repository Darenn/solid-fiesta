#ifndef __BLUDGER_HPP_
#define __BLUDGER_HPP_

#include "agent.hpp"

class Bludger : public Agent {
public:
  Bludger(int _id, int _x, int _y) : Agent(_id, _x, _y){};

  virtual ~Bludger();
};

#endif
