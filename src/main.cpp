#include <algorithm>
#include <iostream>
#include <string>

#include "brain.hpp"

using namespace std;

int main() {
  int myTeamId;
  cin >> myTeamId;
  cin.ignore();

  Brain brain = Brain(myTeamId);

  // game loop
  while (1) {
    int nb_entities;
    cin >> nb_entities;
    cin.ignore();
    for (int i = 0; i < nb_entities; i++) {
      int entityId, x, y, vx, vy, state;
      string entityType;
      cin >> entityId >> entityType >> x >> y >> vx >> vy >> state;
      cin.ignore();

      brain.update_entity(entityId, entityType, x, y, vx, vy, state);
    }

    brain.remove_old_entity();
    brain.play();
    brain.next_turn();
  }
}
