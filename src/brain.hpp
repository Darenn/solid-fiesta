#ifndef __BRAIN_HPP_
#define __BRAIN_HPP_

#include <iostream>
#include <map>
#include <string>

#include "bludger.hpp"
#include "snaffle.hpp"
#include "wizard.hpp"

class Brain {
private:
  int team_id, turn, but_x, but_y, power;

  std::map<int, Wizard *> wizards;
  std::map<int, Wizard *> opponent_wizards;
  std::map<int, Snaffle *> snaffles;
  std::map<int, Bludger *> bludgers;

public:
  Brain(int _team_id) : team_id(_team_id), turn(0) {
    if (team_id) {
      but_x = 0;
      but_y = 3750;
    } else {
      but_x = 16000;
      but_y = 3750;
    }
  };

  virtual ~Brain(){};

  void next_turn() {
    turn++;
    if (power < 100) {
      power++;
    }
  }

  void update_entity(int entityId, const std::string entityType, int x, int y,
                     int vx, int vy, int state) {
    if (entityType == "WIZARD") {
      if (wizards.find(entityId) == wizards.end()) {
        wizards[entityId] = new Wizard(entityId);
      }
      wizards[entityId]->update(x, y, vx, vy, turn);
      if (state) {
        wizards[entityId]->set_holding(snaffles.begin()->second);
      } else {
        wizards[entityId]->set_holding(NULL);
      }
    } else if (entityType == "OPPONENT_WIZARD") {
      if (opponent_wizards.find(entityId) == opponent_wizards.end()) {
        opponent_wizards[entityId] = new Wizard(entityId);
      }
      opponent_wizards[entityId]->update(x, y, vx, vy, turn);
    } else if (entityType == "SNAFFLE") {
      if (snaffles.find(entityId) == snaffles.end()) {
        snaffles[entityId] = new Snaffle(entityId);
      }
      snaffles[entityId]->update(x, y, vx, vy, turn);
    } else if (entityType == "BLUDGER") {
      if (bludgers.find(entityId) == bludgers.end()) {
        bludgers[entityId] = new Bludger(entityId);
      }
      bludgers[entityId]->update(x, y, vx, vy, turn);
    }
  }

  void remove_old_entity() {
    for (std::map<int, Snaffle *>::iterator it = snaffles.begin();
         it != snaffles.end(); ++it) {
      if (it->second->get_last_update() < turn) {
        snaffles.erase(it);
      }
    }
  }

  Snaffle *get_target(Wizard *w, bool left) {
    Snaffle *target = NULL;
    int dist = 160001;
    int new_dist;
    for (std::map<int, Snaffle *>::iterator it = snaffles.begin();
         it != snaffles.end(); ++it) {
      if (left) {
        new_dist = it->second->get_x();
      } else {
        new_dist = 16000 - it->second->get_x();
      }

      if (new_dist < dist) {
        dist = new_dist;
        target = it->second;
      }
    }
    return target;
  }

  void play() {
    bool left = true;
    for (std::map<int, Wizard *>::iterator it = wizards.begin();
         it != wizards.end(); ++it) {
      if (it->second->is_holding()) {
        std::cout << "THROW " << but_x << " " << but_y << " 500" << std::endl;
      } else {
        Snaffle *snaffle = get_target(it->second, left);
        if (power > 30) {
          power -= 20;
          if (team_id == 0) {
            if (snaffle->get_x() <= it->second->get_x()) {
              std::cout << "ACCIO " << snaffle->get_id() << std::endl;
            } else {
              std::cout << "FLIPENDO " << snaffle->get_id() << std::endl;
            }
          } else {
            if (snaffle->get_x() >= it->second->get_x()) {
              std::cout << "ACCIO " << snaffle->get_id() << std::endl;
            } else {
              std::cout << "FLIPENDO " << snaffle->get_id() << std::endl;
            }
          }

        } else {
          std::cout << "MOVE " << snaffle->get_x() << " " << snaffle->get_y()
                    << " 150" << std::endl;
        }
      }
      left = !left;
    }
  }
};

#endif
