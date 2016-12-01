#ifndef __BLUDGER_HPP_
#define __BLUDGER_HPP_
#pragma once

#include "agent.hpp"

class Bludger : public Agent {
public:
  Bludger(int _id) : Agent(_id){};

  virtual ~Bludger(){};
};

#endif
