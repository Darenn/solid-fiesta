#ifndef __AGENT_HPP_
#define __AGENT_HPP_

#include "entity.hpp"

class Agent : public Entity {
public:
  Agent(int _x, int _y) : Entity(_x, _y){};

  virtual ~Agent();
};

#endif
