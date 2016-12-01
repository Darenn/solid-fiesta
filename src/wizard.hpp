#ifndef __WIZARD_HPP_
#define __WIZARD_HPP_

#include <sstream>
#include <string>
#include <vector>

#include "agent.hpp"
#include "snaffle.hpp"

class Wizard : public Agent {
protected:
  Snaffle *holding;

  std::string move(std::vector<int> pos, int power) {
    std::stringstream stream;
    stream << "MOVE " << pos[0] << " " << pos[1] << " " << power << std::endl;
    return stream.str();
  }

  std::string shoot(std::vector<int> pos, int power) {
    std::stringstream stream;
    stream << "THROW " << pos[0] << " " << pos[1] << " " << power << std::endl;
    set_holding(NULL);
    return stream.str();
  }

  std::string oblivate(Entity *e) {
    std::stringstream stream;
    stream << "OBLIVATE " << e->get_id() << std::endl;
    return stream.str();
  }

  std::string petrificus(Entity *e) {
    std::stringstream stream;
    stream << "PETRIFICUS " << e->get_id() << std::endl;
    return stream.str();
  }

  std::string accio(Entity *e) {
    std::stringstream stream;
    stream << "ACCIO " << e->get_id() << std::endl;
    return stream.str();
  }

  std::string flipendo(Entity *e) {
    std::stringstream stream;
    stream << "FLIPENDO " << e->get_id() << std::endl;
    return stream.str();
  }

public:
  Wizard(int _id) : Agent(_id), holding(0){};
  virtual ~Wizard(){};

  void set_holding(Snaffle *s) { holding = s; }
  bool is_holding() { return holding != NULL; }

  std::string intercept(Entity *e) { return move(e->get_pos(), 150); }
  std::string pass(Wizard *w) {
    if (is_holding()) {
      return shoot(w->get_pos(), 500);
    }
    return move(w->get_pos(), 150);
  }
  std::string goal(std::vector<int> goal_pos, Entity *e) {
    if (is_holding()) {
      return shoot(goal_pos, 500);
    }
    return intercept(e);
  }
};

#endif
