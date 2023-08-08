//
// Created by monik on 31/03/2023.
//

#ifndef PLATFORMERSFML_COLLIDER_H
#define PLATFORMERSFML_COLLIDER_H
# include <SFML/Graphics.hpp>

class Collider
{
 public:
  Collider(sf::Sprite& body);
  ~Collider();

  void  move(float  dx, float  dy) const;
  bool checkCollision(const Collider& other, sf::Vector2f& direction, const bool& visible);
  sf::Vector2f getPosition() const;
  sf::Vector2f getHalfSize() const;

 private:
  sf::Sprite& body;


};

#endif // PLATFORMERSFML_COLLIDER_H
