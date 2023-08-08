//
// Created by m2-bukovics on 14/03/2023.
//
#include "TileMap.h"
#include <iostream>

TileMap::TileMap(): MAX_TILE_COUNT(1)
{}
TileMap::~TileMap()
{
  for (unsigned int i = 0; i < 500; ++i)
  {
    delete tile_array[i];
  }
  delete[] tile_array;
  tile_array = nullptr;
}

bool TileMap::load(const std::string& tileset, sf::Vector2u tile_size, const int* tiles, int width, int height, float scale, tileType my_tile_type)
{
  // load the tileset texture
  if (!m_tileset.loadFromFile(tileset))
    return false;

  // set the number of tiles
  MAX_TILE_COUNT = width * height;

  // resize the tile array to hold all the tiles
  tile_array = new GameObject*[MAX_TILE_COUNT];
  tile_type = my_tile_type;


  for (unsigned int i = 0; i < MAX_TILE_COUNT; ++i)
  {
    if (my_tile_type == tileType::ITEM)
    {
      tile_array[i] = new Collectible();
    }
    else if (my_tile_type ==tileType::ENEMY)
    {
      tile_array[i] = new Enemy();
    }
    else
    {
      tile_array[i] = new Tile();
    }
  }

  // populate the tile array, with one sprite per tile
  for (unsigned int i = 0; i < width; ++i)
    for (unsigned int j = 0; j < height; ++j)
    {
      int index = i + j * width;
      // get the current tile number
      int tmp_tile_number = tiles[i + j * width];

      // find its position in the tileset texture
      int tu = tmp_tile_number % (m_tileset.getSize().x / tile_size.x);
      int tv = tmp_tile_number / (m_tileset.getSize().x / tile_size.x);

      // store the sprite and tile number in the tile array
      sf::Sprite* mySprite = tile_array[index]->setSprite(
        m_tileset,
        sf::IntRect(tu * tile_size.x, tv * tile_size.y, tile_size.x, tile_size.y));

      // set the sprite's position, scaled based on the scale factor
      mySprite->setPosition(i * tile_size.x * scale, j * tile_size.y * scale);

      // set the sprite's scale
      mySprite->setScale(scale, scale);

      tile_array[index]->tile_number = tmp_tile_number;

      if (tmp_tile_number <= 0)
      {
        tile_array[index]->setIsVisible(false);
      }
      else if (tmp_tile_number >= 1)
      {
        tile_array[index]->setIsVisible(true);
      }
    }

  return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for (int i = 0; i < MAX_TILE_COUNT; ++i)
  {
    if (tile_array[i]->isVisible())
    {
      // draw the sprite
      target.draw(*tile_array[i]->getSprite());
    }
  }
}
