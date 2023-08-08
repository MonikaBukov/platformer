//
// Created by m2-bukovics on 14/03/2023.
//

#include "Enemy.h"
Enemy::Enemy()
{

}

Enemy::~Enemy() {};

bool Enemy::initialiseEnSprite( sf::Texture& texture, Enemy::Type type1)
{
  type = type1;
  sprite->setTexture(texture);
  return true;
}

int Enemy::getWorth() const
{
  return worth;
}

void Enemy::setWorth(int worth)
{
  Enemy::worth = worth;
}

Enemy::Type Enemy::getType() const
{
  return type;
}

