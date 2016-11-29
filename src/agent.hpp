#ifndef __AGENT_HPP_
#define __AGENT_HPP_

#include "entity.hpp"

class Agent : public Entity {
public:
  Agent(int _id) : Entity(_id){};

  virtual ~Agent(){};
};

#endif
