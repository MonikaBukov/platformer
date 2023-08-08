//
// Created by m2-bukovics on 14/03/2023.
//

#include "Player.h"
#include "Tile.h"
#include <cmath>


Player::Player(){}

Player::~Player() {};

bool Player::isGrounded() const
{
  return is_grounded;
}
void Player::setIsGrounded(bool isGrounded)
{
  is_grounded = isGrounded;
}

void Player::movePlayer(const float& dt)
{
  velocity.x = 0.0f;
  if (sf::Keyboard::isKeyPressed((sf::Keyboard::A)))
  {
    velocity.x -= getSpeed();
    faceRight = false;
  }

  if (sf::Keyboard::isKeyPressed((sf::Keyboard::D)))
  {
    velocity.x += getSpeed();
    faceRight = true;
  }

  if (sf::Keyboard::isKeyPressed((sf::Keyboard::Space)) && isGrounded())
  {
    setIsGrounded(false);
    velocity.y = -sqrtf(2.0f * gravity * jump_height);
  }

  sprite->move(velocity * dt);
  velocity.y += gravity * dt;
}
void Player::onCollision(sf::Vector2f direction) {
  if (direction.x < 0.0f)
  {
    velocity.x = 0.0f;
  }
  else if (direction.x > 0.0f)
  {
    velocity.x = 0.0f;
  }

  if(direction.y < 0.0f)
  {
    velocity.y = 0.0f;
    setIsGrounded(true);
  }
  else if(direction.y > 0.0f)
  {
    velocity.y = 0.0f;
  }

  if (direction.y > 0.0f && isGrounded()) {
    velocity.y = 0.0f;
  }
}

const float Player::getGravity() const
{
  return gravity;
}
