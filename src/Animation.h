//
// Created by monik on 14/03/2023.
//

#ifndef PLATFORMERSFML_ANIMATION_H
#define PLATFORMERSFML_ANIMATION_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Animation
{
 public:
  Animation();
  ~Animation();

  void initAnim (sf::Texture* texture, sf::Vector2u imageCount, float switch_time);

  void Update(int row, float dt,bool faceRight);

  sf::IntRect rect;

 private:
  sf::Vector2u image_count;
  sf::Vector2u current_image;

  float total_time;
  float switch_time;



};

#endif // PLATFORMERSFML_ANIMATION_H
