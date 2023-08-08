//
// Created by monik on 03/04/2023.
//

#ifndef PLATFORMERSFML_IITEMCONFIG_H
#define PLATFORMERSFML_IITEMCONFIG_H
# include <SFML/Graphics.hpp>


class IItemConfig
{
 public:
  virtual void increaseScore(int score) =0;
  virtual void increaseHealth(int health) = 0;
  virtual void increaseAmmunition(int ammo)=0;
  virtual void setNewSpawn(sf::Vector2f position)=0;
  virtual void doubleTheScore(int multiplier)=0;
  virtual void levelAchieved(bool game_won)=0;


};

#endif // PLATFORMERSFML_IITEMCONFIG_H
