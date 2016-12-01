#ifndef __TEAM_HPP_
#define __TEAM_HPP_
#pragma once

#include <cassert>
#include <map>
#include <vector>

#include "wizard.hpp"

class Team {
protected:
  std::map<int, Wizard *> wizards;
  std::vector<int> goal_pos;
  int power, id;

public:
  Team(int _id) : power(0), id(_id) {
    goal_pos.push_back(16000 * _id);
    goal_pos.push_back(3750);
  }

  virtual ~Team() {}

  int get_id() { return id; }
  std::vector<int> get_goal_pos() { return goal_pos; }

  Wizard *get_wizard(int _id) { return wizards[_id]; }
  void update_power(int val) { power += val; }
  void update_wizard(int entity_id, int x, int y, int vx, int vy, int turn) {
    if (wizards.find(entity_id) == wizards.end()) {
      wizards[entity_id] = new Wizard(entity_id);
    }
    wizards[entity_id]->update(x, y, vx, vy, turn);
  }

  std::string defend(std::vector<int> _goal_pos, Snaffle *close) {
    std::stringstream stream;
    for (auto it = wizards.begin(); it != wizards.end(); ++it) {
      stream << it->second->intercept(close) << std::endl;
    }
    return stream.str();
  }

  std::string goal(std::vector<int> _goal_pos, Snaffle *close) {
    std::stringstream stream;
    for (auto it = wizards.begin(); it != wizards.end(); ++it) {
      stream << it->second->goal(_goal_pos, close);
    }
    return stream.str();
  }
};

#endif
