//
// Created by m2-bukovics on 14/03/2023.
//

#ifndef PLATFORMERSFML_COLLECTIBLE_H
#define PLATFORMERSFML_COLLECTIBLE_H
#include "GameObject.h"
#include "IItemConfig.h"

class Collectible : public GameObject
{
 public:
  Collectible();
  enum Type
  {
    SCORE,
    HEALTH,
    SPAWN_POINT,
    GAME_OBJECTIVE,
    DOUBLE_SCORE,
    AMMUNITION,
  };
  void collect(IItemConfig* collector);
  Type type;
};

#endif // PLATFORMERSFML_COLLECTIBLE_H
