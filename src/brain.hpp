#ifndef __BRAIN_HPP_
#define __BRAIN_HPP_
#pragma once

#include <iostream>
#include <map>
#include <string>

#include "world.hpp"

class Brain {
private:
  World world;
  int team_id, turn;

public:
  Brain(int _team_id) : team_id(_team_id) {}
  virtual ~Brain(){};

  void next_turn() {
    turn++;
    world.get_team(team_id)->update_power(1);
    world.get_team(!team_id)->update_power(1);
  }

  void update_entity(int entity_id, const std::string entityType, int x, int y,
                     int vx, int vy, int state) {
    if (entityType == "WIZARD") {
      world.update_wizard(team_id, entity_id, x, y, vx, vy, state, turn);
    } else if (entityType == "OPPONENT_WIZARD") {
      world.update_wizard(!team_id, entity_id, x, y, vx, vy, state, turn);
    } else if (entityType == "SNAFFLE") {
      world.update_snaffle(entity_id, x, y, vx, vy, turn);
    } else if (entityType == "BLUDGER") {
      world.update_bludger(entity_id, x, y, vx, vy, turn);
    }
  }

  void remove_old_entity() { world.remove_old_entity(turn); }

  void play() {
    int d;
    Team *t = world.get_team(team_id);
    Snaffle *s = world.get_close_snaffle(t->get_goal_pos(), &d);
    if (d < 500) {
      std::cout << world.get_team(team_id)->defend(t->get_goal_pos(), s);
    } else {
      std::cout << world.get_team(team_id)->goal(
          world.get_team(!team_id)->get_goal_pos(), s);
    }
  }
};

#endif
