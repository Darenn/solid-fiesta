#ifndef __WIZARD_HPP_
#define __WIZARD_HPP_

#include "agent.hpp"
#include "snaffle.hpp"

class Wizard : public Agent {
protected:
  Snaffle *holding;

public:
  Wizard(int _id, int _x, int _y) : Agent(_id, _x, _y), holding(0){};

  virtual ~Wizard();
};

#endif
