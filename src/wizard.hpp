#ifndef __WIZARD_HPP_
#define __WIZARD_HPP_

#include "agent.hpp"
#include "snaffle.hpp"

class Wizard : public Agent {
protected:
  Snaffle *holding;

public:
  Wizard(int _id) : Agent(_id), holding(0){};

  void set_holding(Snaffle *s) { holding = s; }

  bool is_holding() { return holding != 0; }

  virtual ~Wizard(){};
};

#endif
