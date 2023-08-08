//
// Created by m2-bukovics on 14/03/2023.
//

#include "Collectible.h"

Collectible::Collectible(): GameObject() 
{

}

void Collectible::collect(IItemConfig* collector)
{
  switch (type)
  {
    case Type::SCORE:
    {
      collector->increaseScore(1);
      break;
    }

    case Type::DOUBLE_SCORE:
    {
      collector->doubleTheScore(2);
      break;
    }

    case Type::HEALTH:
    {
      collector->increaseHealth(1);
      break;
    }

    case Type::AMMUNITION:
    {
      collector->increaseAmmunition(1);
      break;
    }

    case Type::SPAWN_POINT:
    {
      collector->setNewSpawn(getSprite()->getPosition());
      break;
    }

    case Type::GAME_OBJECTIVE:
    {
      collector->levelAchieved(true);
      break;
    }

  }
}