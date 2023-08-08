//
// Created by m2-bukovics on 14/03/2023.
//

#ifndef PLATFORMERSFML_TILEMAP_H
#define PLATFORMERSFML_TILEMAP_H

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Collectible.h"
#include "Enemy.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
 public:
  TileMap();
  ~TileMap();

  enum tileType
  {
    ITEM,
    ENEMY,
    TILE,
  };

  bool load(
    const std::string& tileset, sf::Vector2u tile_size, const int* tiles,
    int width, int height, float scale, tileType my_tile_type);

  GameObject** tile_array = nullptr;
  int MAX_TILE_COUNT;
  sf::IntRect uvRect;
  tileType tile_type;

 private:
  sf::VertexArray m_vertices;
  sf::Texture m_tileset;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif // PLATFORMERSFML_TILEMAP_H
