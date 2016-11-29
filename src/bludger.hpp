#ifndef __BLUDGER_HPP_
#define __BLUDGER_HPP_

#include "agent.hpp"

class Bludger : public Agent {
public:
  Bludger(int _id) : Agent(_id){};

  virtual ~Bludger(){};
};

#endif
