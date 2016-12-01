#ifndef __WORLD_HPP_
#define __WORLD_HPP_

#include <cmath>
#include <map>
#include <vector>

#include "bludger.hpp"
#include "snaffle.hpp"
#include "team.hpp"

class World {
protected:
  std::map<int, Team *> teams;
  std::map<int, Snaffle *> snaffles;
  std::map<int, Bludger *> bludgers;

public:
  World() {}
  virtual ~World() {}

  void remove_old_entity(int current_turn) {
    for (auto it = snaffles.begin(); it != snaffles.end(); ++it) {
      if (it->second->get_last_update() < current_turn) {
        snaffles.erase(it);
      }
    }
  }

  // WIZARD
  void update_wizard(int team, int entity_id, int x, int y, int vx, int vy,
                     int state, int turn) {
    if (teams.find(team) == teams.end()) {
      teams[team] = new Team(team);
    }
    teams[team]->update_wizard(entity_id, x, y, vx, vy, turn);
    if (state) {
      Wizard *w = teams[team]->get_wizard(entity_id);
      w->set_holding(get_close_snaffle(w->get_pos(), NULL));
    }
  }
  Team *get_team(int _id) { return teams[_id]; }

  // SNAFFLE
  void update_snaffle(int entity_id, int x, int y, int vx, int vy, int turn) {
    if (snaffles.find(entity_id) == snaffles.end()) {
      snaffles[entity_id] = new Snaffle(entity_id);
    }
    snaffles[entity_id]->update(x, y, vx, vy, turn);
  }
  Snaffle *get_snaffle(int _id) { return snaffles[_id]; }
  Snaffle *get_close_snaffle(std::vector<int> pos, int *d) {
    Snaffle *close_snaffle;
    int close_dist, dist;
    for (auto it = snaffles.begin(); it != snaffles.end(); ++it) {
      std::vector<int> s_pos = it->second->get_pos();
      int diff_x = pos[0] - s_pos[0];
      int diff_y = pos[1] - s_pos[1];
      dist = sqrt((diff_x * diff_x) + (diff_y * diff_y));
      if (dist < close_dist) {
        close_dist = dist;
        close_snaffle = it->second;
      }
    }
    if (d != NULL) {
      *d = dist;
    }
    return close_snaffle;
  }

  // BLUDGER
  void update_bludger(int entity_id, int x, int y, int vx, int vy, int turn) {
    if (bludgers.find(entity_id) == bludgers.end()) {
      bludgers[entity_id] = new Bludger(entity_id);
    }
    bludgers[entity_id]->update(x, y, vx, vy, turn);
  }
  Bludger *get_bludger(int _id) { return bludgers[_id]; }
};

#endif
