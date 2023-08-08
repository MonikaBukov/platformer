//
// Created by m2-bukovics on 14/03/2023.
//


#ifndef PLATFORMERSFML_GAMEOBJECTS_H
#define PLATFORMERSFML_GAMEOBJECTS_H
#include <SFML/Graphics.hpp>
#include <string>
# include "Collider.h"



class GameObject
{
 public:
  GameObject();
  virtual ~GameObject();

  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
  sf::Sprite* setSprite(sf::Texture& texture, sf::IntRect);
  void drawObject(sf::RenderWindow& window);
  void moveObject(const float& dt);
  bool isCollide(const GameObject& sprite1);
  float getMidPointX();
  float getMidPointY();
  int getSpeed() const;
  void setSpeed(int speed);
  bool isVisible() const;
  void setIsVisible(bool isVisible);
  sf::Vector2f direction = { 0, 0 };
  int tile_number;
  Collider getCollider(){return Collider(*getSprite());};

 protected:
  sf::Sprite* sprite;

 private:
  bool topCollide(const GameObject& sprite1);
  bool leftCollide(const GameObject& sprite1);
  bool rightCollide(const GameObject& sprite1);
  bool bottomCollide(const GameObject& sprite1);
  int speed = 0;
  float mid_point_y;
  float mid_point_x;
  bool is_visible;
};


#endif // PLATFORMERSFML_GAMEOBJECTS_H
