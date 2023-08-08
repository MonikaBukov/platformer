//
// Created by m2-bukovics on 14/03/2023.
//

#ifndef PLATFORMERSFML_ENEMY_H
#define PLATFORMERSFML_ENEMY_H

#include "GameObject.h"

class Enemy: public GameObject
{
 public:
  Enemy();
  ~Enemy();
  enum Type
  {
    WEAK,
    STRONG,
    BOSS,
  };
  bool initialiseEnSprite(sf::Texture& texture, Type type);
  int getWorth() const;
  void setWorth(int worth);
  Type getType() const;
  int health;

 private:
  Type type;
  int worth;

};


#endif // PLATFORMERSFML_ENEMY_H
