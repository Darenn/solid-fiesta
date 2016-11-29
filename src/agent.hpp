#ifndef __AGENT_HPP_
#define __AGENT_HPP_

#include "entity.hpp"

class Agent : public Entity {
public:
  Agent(int _id, int _x, int _y) : Entity(_id, _x, _y){};

  virtual ~Agent();
};

#endif
