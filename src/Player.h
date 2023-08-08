//
// Created by m2-bukovics on 14/03/2023.
//

#ifndef PLATFORMERSFML_PLAYER_H
#define PLATFORMERSFML_PLAYER_H
#include "GameObject.h"
#include "Tile.h"
#include "Collider.h"

class Player: public GameObject
{
 public:
  Player();
  ~Player();

  bool isGrounded() const;
  void setIsGrounded(bool isGrounded);
  void movePlayer(const float& dt);
  void  onCollision(sf::Vector2f direction);
  bool faceRight = true;
  sf::Vector2f velocity;
  const float getGravity() const;

 private:
  float  jump_height = 300.0f;
  bool is_grounded;
  const float gravity = 981.0f;
};

#endif // PLATFORMERSFML_PLAYER_H
