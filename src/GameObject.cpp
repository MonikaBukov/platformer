//
// Created by m2-bukovics on 14/03/2023.
//

#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
  : sprite(nullptr)
{
  sprite = new sf::Sprite();
};

GameObject::~GameObject()
{
  delete sprite;
};

bool GameObject::initialiseSprite(sf::Texture &texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout << "Error\n";
    return false;
  }
  sprite->setTexture(texture);
  return true;
}

sf::Sprite* GameObject::setSprite(sf::Texture& texture,sf::IntRect intrect){
  sprite->setTexture(texture);
  sprite->setTextureRect(intrect);

  return sprite;
}

void GameObject::drawObject(sf::RenderWindow& window)
{
  window.draw(*sprite);
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}


void GameObject::moveObject(const float& dt)
{
  sprite->move(speed * direction.x * dt, speed * direction.y * dt);
}

bool GameObject::isCollide(const GameObject& sprite1)
{
  if (topCollide(sprite1) && bottomCollide(sprite1) && rightCollide(sprite1) && leftCollide(sprite1))
  {
    return true;
  }
  else
    return false;
}

bool GameObject::topCollide(const GameObject& sprite1)
{
  if (sprite->getPosition().y + 25 <= sprite1.sprite->getPosition().y + sprite1.sprite->getGlobalBounds().height)
  {
    return true;
  }
  else
    return false;
}

bool GameObject::bottomCollide(const GameObject& sprite1)
{
  if (!sprite1.isVisible())
  {
    return false;
  }
  if (sprite->getPosition().y + sprite->getGlobalBounds().height -25 >= sprite1.sprite->getPosition().y)
  {
    return true;
  }
  else
    return false;
}

bool GameObject::leftCollide(const GameObject& sprite1)
{
  if (sprite->getPosition().x + 15 <= sprite1.sprite->getPosition().x + sprite1.sprite->getGlobalBounds().width)

  {
    return true;
  }
  else
    return false;
}

bool GameObject::rightCollide(const GameObject& sprite1)
{
  if (sprite->getPosition().x + sprite->getGlobalBounds().width - 15 >= sprite1.sprite->getPosition().x)
  {
    return true;
  }
  else
    return false;
}

float GameObject::getMidPointX()
{
  mid_point_x = sprite->getPosition().x + sprite->getGlobalBounds().width / 2;
  return mid_point_x;
}
float GameObject::getMidPointY()
{
  mid_point_y = sprite->getPosition().y + sprite->getGlobalBounds().height / 2;
  return mid_point_y;
}

int GameObject::getSpeed() const
{
  return speed;
}

void GameObject::setSpeed(int speed)
{
  GameObject::speed = speed;
}

bool GameObject::isVisible() const
{
  return is_visible;
}
void GameObject::setIsVisible(bool isVisible)
{
  is_visible = isVisible;
}

