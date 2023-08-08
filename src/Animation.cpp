//
// Created by monik on 14/03/2023.
//

#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::initAnim(sf::Texture* texture, sf::Vector2u image_count, float switch_time)
{
  this->image_count = image_count;
  this->switch_time = switch_time;
  total_time = 0.0f;
  current_image.x = 0;

  rect.width = texture->getSize().x / float (image_count.x);
  rect.height = texture->getSize().y / float (image_count.y);
}

void Animation::Update(int row, float dt, bool faceRight)
{
  current_image.y = row;
  total_time += dt;

  if (total_time >= switch_time)
  {
    total_time -=switch_time;
    current_image.x ++;
    if (current_image.x >= image_count.x)
    {
      current_image.x = 0;
    }
  }
  rect.top = current_image.y * rect.height;
  if (faceRight)
  {
    rect.left = current_image.x * rect.width;
    rect.width = abs(rect.width);
  }
  else
  {
    rect.left = (current_image.x+1) * abs(rect.width);
    rect.width = -abs(rect.width);
  }

}
