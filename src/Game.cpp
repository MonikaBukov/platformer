
#include <iostream>
#include "Game.h"

void Game::loadingTextures()
{
  //
  if (!player_texture.loadFromFile("Data/Images/Owlet_Monster_Idle_4.png") ||
      (!player_run_texture.loadFromFile("Data/Images/Owlet_Monster_Run_6.png"))
      ||!player_jump_texture.loadFromFile("Data/Images/Owlet_Monster_Jump_8.png")
      ||!player_attack_texture.loadFromFile("Data/Images/Owlet_Monster_Throw_4.png"))
  {
    std::cout << "player texture did not load";
  }

  if (!red_enemy_texture.loadFromFile("Data/Images/red_endsega64.png") ||
      (!blue_enemy_texture.loadFromFile("Data/Images/blue_endsega64.png"))
      ||!yellow_enemy_texture.loadFromFile("Data/Images/yellow_endsega64.png")
      ||!green_enemy_texture.loadFromFile("Data/Images/green_endsega64.png"))
  {
    std::cout << "enemy texture did not load";
  }
}

void Game::loadingFonts()
{
  if (!pixel_font.loadFromFile("Data/Fonts/Planes_ValMore.ttf"))
  {
    std::cout << "font did not load";
  }
}

void Game::loadingSounds()
{
  if (!background_music.openFromFile("Data/Sounds/frozen_winter.wav"))
  {
    std::cout << "sound did not open";
  }

  if (
    !attack_buffer.loadFromFile("Data/Sounds/attack1.wav") ||
    !collect_buffer.loadFromFile("Data/Sounds/collect.wav") ||
    !enemy_defeated_buffer.loadFromFile("Data/Sounds/dead_enemy.wav") ||
    !dead_buffer.loadFromFile("Data/Sounds/loose.wav") ||
    !win_buffer.loadFromFile("Data/Sounds/game-level-complete.wav") ||
    !jumps_buffer.loadFromFile("Data/Sounds/Jump 1.wav") ||
    !hit_buffer.loadFromFile("Data/Sounds/hit.wav"))
  {
    std::cout << "sound did not open";
  }

  attack_sound.setBuffer(attack_buffer);
  collect_sound.setBuffer(collect_buffer);
  enemy_defeated_sound.setBuffer(enemy_defeated_buffer);
  dead_sound.setBuffer(dead_buffer);
  win_sound.setBuffer(win_buffer);
  jumps_sound.setBuffer(jumps_buffer);
  hit_sound.setBuffer(hit_buffer);
  hit_sound.setVolume(9.0f);
  background_music.setLoop(true);
  background_music.play();
}

void Game::menuSetText()
{
  menu_text.setFont(pixel_font);
  menu_text.setCharacterSize(100);
  menu_text.setFillColor(sf::Color::White);

  start_text.setFont(pixel_font);
  start_text.setCharacterSize(60);
  start_text.setFillColor(sf::Color::White);

  high_score_t.setFont(pixel_font);
  high_score_t.setCharacterSize(60);
  high_score_t.setFillColor(sf::Color::White);

  instruction_pic.initialiseSprite(instruction_tx, "Data/Images/instructions.png");
  instruction_pic.getSprite()->setScale(0.75f, 0.75f);
  instruction_pic.getSprite()->setPosition(window.getSize().x / 2 - instruction_pic.getSprite()->getGlobalBounds().width/2, window.getSize().y/2);
}

void Game::sateTexts()
{
  if (game_state == GameStates::MENU)
  {
    menu_text.setString("Platformer");
    start_text.setString("Press enter to start");
  }

  if (game_state == GameStates::GAME_OVER)
  {
    start_text.setString("Press Enter to go back to Menu");
    menu_text.setString("GAME OVER");
  }

  if (game_state == GameStates::WIN_GAME)
  {
    start_text.setString("Press Enter to go back to Menu");
    menu_text.setString("YOU WON");
  }

  if (game_state == GameStates::PAUSE_GAME)
  {
    start_text.setString("Press Enter to continue");
    menu_text.setString("PAUSE");
  }

  high_score_t.setString(
    "high score: " + std::to_string(high_score) + "\n" +
    "your score: " + std::to_string(score));

  high_score_t.setPosition(
    window.getSize().x * 0.5f - high_score_t.getGlobalBounds().width * 0.5f,
    window.getSize().y * 0.60f);

  start_text.setPosition(
    window.getSize().x / 2 - start_text.getGlobalBounds().width / 2.,
    window.getSize().y * 0.4 - start_text.getGlobalBounds().height / 2);

  menu_text.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2.,
    window.getSize().y / 4 - menu_text.getGlobalBounds().height / 2);
}

void Game::setTiles()
{
  const int level[] = {
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  0,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  183, 184, 185, -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    81,  82,  83,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  87,  88,  89,  -1,  -1,  -1,  0,   -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  123, -1,  -1,  -1,  0,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  177,
    178, 179, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  0,   -1,  -1,  -1,  -1,  -1,  139, -1,  -1,  119, 120, 121, -1,  -1,
    -1,  -1,  -1,  17,  18,  19,  -1,  -1,  -1,  -1,  -1,  81,  82,  83,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  113, 114, 115,
    -1,  -1,  -1,  -1,  -1,  87,  89,  -1,  -1,  -1,  -1,  -1,  155, 120, 121,
    135, 136, 137, -1,  -1,  17,  18,  19,  33,  34,  35,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  113,
    114, 115, 129, 130, 131, 113, 114, 115, -1,  -1,  -1,  -1,  -1,  -1,  23,
    24,  25,  135, 136, 137, 119, 120, 119, 120, 121, 33,  34,  35,  33,  34,
    35,  17,  18,  19,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  129, 130, 131, 113, 114, 115, 129, 130, 131, -1,  -1,
    -1,  -1,  -1,  -1,  39,  40,  41,  119, 120, 121, 135, 136, 135, 136, 137,
    49,  50,  51,  49,  50,  51,  33,  34,  35,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  145, 146, 147, 129, 130, 131,
    145, 146, 147, -1,  -1,  -1,  -1,  -1,  -1,  55,  56,  57,  135, 136, 137,
    151, 152, 151, 152, 153,
  };

  candy_map.load(
    "Data/Images/Tiles+Ladders.png",
    sf::Vector2u(16, 16),
    level,
    50,
    10,
    5.0f,
    TileMap::TILE);

  int spawn_count = 0;
  for (int i = 0; i < candy_map.MAX_TILE_COUNT && spawn_count < 4; i++)
  {
    if (candy_map.tile_array[i]->tile_number == 0)
    {
      enemy_spawn_positions[spawn_count] =
      {candy_map.tile_array[i]->getSprite()->getPosition().x + candy_map.tile_array[i]->getSprite()->getGlobalBounds().width, candy_map.tile_array[i]->getSprite()->getPosition().y + candy_map.tile_array[i]->getSprite()->getGlobalBounds().height} ;
      spawn_count++;
    }
  }
}

void Game::setItems()
{
  const int level[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 5,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 22, 31, 22, 12, -1, 31, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 22, 22, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    12, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, 7,  22, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 31, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, 22, 22, 22, -1, -1, -1, -1, -1, 22, 22, 22, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, 22, 31, -1, -1, -1, -1, -1,
    22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 31, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 22, 22, 22, -1, -1, -1, 22, 22, 7,  -1, -1, -1, -1, -1, -1, -1, 22, 22,
    -1, -1, -1, -1, -1, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1, 22, 7,  -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1,
  };
  candy_items.load(
    "Data/Images/CandyItems.png",
    sf::Vector2u(16, 16),
    level,
    50,
    10,
    5.0f,
    TileMap::ITEM);

  for (int i = 0; i < candy_items.MAX_TILE_COUNT; i++)
    switch (candy_items.tile_array[i]->tile_number)
    {
      case (22):
      {
        static_cast<Collectible*>(candy_items.tile_array[i])->type =
          Collectible::Type::SCORE;
        candy_items.tile_array[i]->getSprite()->setScale(3, 3);
        break;
      }

      case (7):
      {
        static_cast<Collectible*>(candy_items.tile_array[i])->type =
          Collectible::Type::SPAWN_POINT;
        break;
      }

      case (12):
      {
        static_cast<Collectible*>(candy_items.tile_array[i])->type =
          Collectible::Type::HEALTH;
        break;
      }

      case (15):
      {
        static_cast<Collectible*>(candy_items.tile_array[i])->type =
          Collectible::Type::DOUBLE_SCORE;
        break;
      }

      case (31):
      {
        static_cast<Collectible*>(candy_items.tile_array[i])->type =
          Collectible::Type::AMMUNITION;
        break;
      }

      case (5):
      {
        static_cast<Collectible*>(candy_items.tile_array[i])->type =
          Collectible::Type::GAME_OBJECTIVE;
        break;
      }
    }
}

void Game::setLvl2Tiles()
{
  const int level[] = {
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,   -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  155, 156, 157, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  25,  26,  27,
    28,  29,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    25,  26,  27,  28,  29,  -1,  -1,  -1,  -1,  -1,  -1,  0,   -1,  -1,  -1,
    -1,  -1,  155, 156, 157, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  0,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    155, 156, 157, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  0,   -1,  -1,  -1,  -1,  -1,  25,  26,  27,  28,  29,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  150, 151, 152, 153, 154, -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  25,  26,  27,  28,  29,
    -1,  -1,  -1,  -1,  -1,  25,  26,  27,  28,  29,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  150, 151, 152, 153, 278, 176, 177, 178, 152, 153,
    154, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    50,  51,  52,  53,  54,  -1,  -1,  -1,  -1,  -1,  50,  51,  52,  53,  54,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  175, 176, 177, 178, 177,
    177, 177, 177, 177, 178, 179, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,
  };
  forrest_map.load(
    "Data/Images/Tiles.png",
    sf::Vector2u(16, 16),
    level,
    50,
    10,
    5.0f,
    TileMap::TILE);

  int spawn_count = 0;

  for (int i = 0; i < forrest_map.MAX_TILE_COUNT && spawn_count < 4; i++)
  {
    if (forrest_map.tile_array[i]->tile_number == 0)
    {
      enemy_spawn_positions_2[spawn_count] =
        {forrest_map.tile_array[i]->getSprite()->getPosition().x + forrest_map.tile_array[i]->getSprite()->getGlobalBounds().width, forrest_map.tile_array[i]->getSprite()->getPosition().y + forrest_map.tile_array[i]->getSprite()->getGlobalBounds().height} ;
      spawn_count++;
    }
  }
}

void Game::setLvl2Items()
{
  const int level[] = {
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  540, 590,
    540, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  540, 540, -1,  -1,  515, -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  540, 540, 590, 421, 540,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  540, 540, 540,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  421, -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  540, 540, -1,  -1,  618, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  421, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  540, 540, 540, 540, 540, -1,  -1,  -1,  -1,  -1,
    540, 540, 540, 415, 540, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  415, -1,  590, -1,  -1,  -1,  -1,  -1,  415, -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,
  };

  forrest_item.load(
    "Data/Images/Tiles.png",
    sf::Vector2u(16, 16),
    level,
    50,
    10,
    5.0f,
    TileMap::ITEM);

  //setting the items Type
  for (int i = 0; i < forrest_item.MAX_TILE_COUNT; i++)
    switch (forrest_item.tile_array[i]->tile_number)
    {
      case (540):
      {
        static_cast<Collectible*>(forrest_item.tile_array[i])->type =
          Collectible::Type::SCORE;
        forrest_item.tile_array[i]->getSprite()->setScale(3, 3);
        break;
      }
      case (421):
      {
        static_cast<Collectible*>(forrest_item.tile_array[i])->type =
          Collectible::Type::SPAWN_POINT;
        break;
      }
      case (590):
      {
        static_cast<Collectible*>(forrest_item.tile_array[i])->type =
          Collectible::Type::HEALTH;
        break;
      }
      case (618):
      {
        static_cast<Collectible*>(forrest_item.tile_array[i])->type =
          Collectible::Type::DOUBLE_SCORE;
        break;
      }
      case (415):
      {
        static_cast<Collectible*>(forrest_item.tile_array[i])->type =
          Collectible::Type::AMMUNITION;
        break;
      }
      case (515):
      {
        static_cast<Collectible*>(forrest_item.tile_array[i])->type =
          Collectible::Type::GAME_OBJECTIVE;
        break;
      }
    }
}

//functions for collecting item
void Game::increaseScore(int score)
{
  this->score = this->score + score;
}

void Game::increaseHealth(int health)
{
  NUMBER_OF_LIVES = NUMBER_OF_LIVES + health;
}

void Game::doubleTheScore(int multiplier)
{
  this->score = this->score * multiplier;
}

void Game::increaseAmmunition(int ammo)
{
  this->ammo = this->ammo + ammo;
}

void Game::setNewSpawn(sf::Vector2f position)
{
  spawn_position = position;
}

void Game::levelAchieved(bool game_won)
{
  win_sound.play();
  setPlayer();
  setLives();
  setRocks();
  ammo = 5;
  if (!level1_complete)
  {
    level1_complete = game_won;
    setEnemies();
  }
  else
  {
    level1_complete = false;
    highScoreGet();
    game_state = GameStates::WIN_GAME;
    setEnemies();
  }
}

void Game::setPlayer()
{
  player_animation.initAnim(&player_texture ,sf::Vector2u(4,1),0.3f);
  player_run_animation.initAnim(&player_run_texture, sf::Vector2u(6,1),0.3f);
  player_jump_animation.initAnim(&player_jump_texture, sf::Vector2u(8,1),0.5f);
  player_attack_animation.initAnim(&player_attack_texture, sf::Vector2u(4,1),0.2f);
  player.initialiseSprite(player_texture, "Data/Images/Owlet_Monster_Idle_4.png");
  player.getSprite()->setScale(2.5,2.5);
  player.setSpeed(250);
  spawn_position = {10,50};
  player.getSprite()->setPosition(spawn_position);
}

void Game::setEnemies()
{
  green_enemy_anim.initAnim(&green_enemy_texture, sf::Vector2u(8, 20), 0.5f);
  enemies[0].initialiseEnSprite(red_enemy_texture, Enemy::Type::WEAK);
  enemies[1].initialiseEnSprite(green_enemy_texture, Enemy::Type::WEAK);
  enemies[2].initialiseEnSprite(blue_enemy_texture, Enemy::Type::STRONG);
  enemies[3].initialiseEnSprite(yellow_enemy_texture, Enemy::Type::BOSS);

  //setting up enemies type and variables
  for (int i = 0; i < 4; i++)
  {
    switch (enemies[i].getType())
    {
      case Enemy::WEAK:
      {
        enemies[i].health = 1;
        enemies[i].setWorth(3);
        enemies[i].getSprite()->setScale(1.5f, 1.5f);
        break;
      }
      case Enemy::STRONG:
      {
        enemies[i].health = 2;
        enemies[i].getSprite()->setScale(2.0f, 2.0f);
        enemies[i].setWorth(5);
        break;
      }
      case Enemy::BOSS:
      {
        enemies[i].health = 3;
        enemies[i].getSprite()->setScale(3.0f, 3.0f);
        enemies[i].setWorth(10);
        break;
      }
    }
    enemies[i].getSprite()->setTextureRect(green_enemy_anim.rect);

    sf::FloatRect bounds = enemies[i].getSprite()->getLocalBounds();
    float scaleX         = enemies[i].getSprite()->getScale().x;
    float scaleY         = enemies[i].getSprite()->getScale().y;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (!level1_complete)
    {
      enemies[i].getSprite()->setPosition(
        enemy_spawn_positions[i].x - bounds.width,
        enemy_spawn_positions[i].y - bounds.height * 0.6);
    }
    else
    {
      enemies[i].getSprite()->setPosition(
        enemy_spawn_positions_2[i].x - bounds.width,
        enemy_spawn_positions_2[i].y - bounds.height * 0.6);
    }
    enemies[i].setSpeed(100);
    enemies[i].setIsVisible(true);
  }
}

void Game::updateEnemiesAnim(const float& dt)
{
  for (auto& enemy : enemies)
  {
    green_enemy_anim.Update(1, dt, player.faceRight);
    enemy.getSprite()->setTextureRect(green_enemy_anim.rect);
  }

  for (int i = 0; i < 4; i++)
  {
    if (enemies[i].health <= 0 && enemies[i].isVisible())
    {
      enemies[i].health = -1;
      green_enemy_anim.Update(3, dt, player.faceRight);
      enemies[i].getSprite()->setTextureRect(green_enemy_anim.rect);
      enemies[i].direction.x = 0;
      enemies[i].direction.y = 5;
      enemies[i].moveObject(dt);
      if (enemies[i].getSprite()->getPosition().y > window.getSize().y)
      {
        enemy_defeated_sound.play();
        score += enemies[i].getWorth();
        enemies[i].setIsVisible(false);
      }
    }

    // colliding with enemy or falling down kills player and if run out of lives game over
    if (
      player.isCollide(enemies[i]) ||
      player.getSprite()->getPosition().y > window.getSize().y)
    {
      playerDied();
      if (NUMBER_OF_LIVES <= 0)
      {
        highScoreGet();
        game_state = GameStates::GAME_OVER;
      }
    }
  }
}

//reset everything to visible
void Game::resetItems()
  {
  for (int i = 0; i < candy_items.MAX_TILE_COUNT; i++)
  {
    if (candy_items.tile_array[i]->tile_number >= 1)
    {
      candy_items.tile_array[i]->setIsVisible(true);
    }
    if (forrest_item.tile_array[i]->tile_number >= 1)
    {
      forrest_item.tile_array[i]->setIsVisible(true);
    }
  }
}

void Game::playerDied()
{
  dead_sound.play();
  NUMBER_OF_LIVES--;
  player.getSprite()->setPosition(spawn_position);
}

void Game::updatePlayerAnim(const float& dt)
{
  static float attackTimer = 0.0f;

  if (throwing)
  {
      attackTimer = 0.5f;
  }
  if (attackTimer > 0.0f) {
    attackTimer -= dt;
    player_attack_animation.Update(0, dt, player.faceRight);
    player.getSprite()->setTexture(player_attack_texture);
    player.getSprite()->setTextureRect(player_attack_animation.rect);
  }
  else if(player.velocity.x == 0 && player.isGrounded())
  {
    player_animation.Update(0, dt, player.faceRight);
    player.getSprite()->setTexture(player_texture);
    player.getSprite()->setTextureRect(player_animation.rect);
  }
  else if((player.velocity.y > 0.1f || player.velocity.y < 0.1f) && !player.isGrounded() )
  {
    player_jump_animation.Update(0, dt, player.faceRight);
    player.getSprite()->setTexture(player_jump_texture);
    player.getSprite()->setTextureRect(player_jump_animation.rect);
  }
  else
  {
    player_run_animation.Update(0, dt, player.faceRight);
    player.getSprite()->setTexture(player_run_texture);
    player.getSprite()->setTextureRect(player_run_animation.rect);
  }
}

void Game::setRocks()
{
  if (!rock_texture.loadFromFile("Data/Images/Rock2.png"))
  {
    std::cout << "Error\n";
  }

  for (auto & rock : rocks)
  {
    rock.getSprite()->setTexture(rock_texture);
    rock.setIsVisible(false);
    rock.direction.x = 0;
    rock.direction.y = 0;
  }
}

void Game::throwRock(const float& dt)
{
  static float now      = 0.0f;
  now += dt;

  for (auto& rock : rocks)
  {
    rock.getSprite()->move(rock.direction * dt);

    // check if the current rock is not visible and there is ammo left
    if (!rock.isVisible() && ammo > 0 && now >= shot_delay)
    {

      // check if a rock has not already been thrown
      if (!rockThrew && throwing)
      {
        attack_sound.play();

        // calculate the rock's direction based on the player's facing direction
        if (player.faceRight)
        {
          rock.direction.x = 300;
        }
        else
        {
          rock.direction.x = -300;
        }

        rock.direction.y = (-sqrt(2.0f * player.getGravity() * 50));
        rock.setIsVisible(true);
        rock.setSpeed(200);
        rock.getSprite()->setPosition(player.getMidPointX(), player.getMidPointY());
        rockThrew = true;
        now       = 0;
        ammo--;

        // exit the loop when rock is thrown
        break;
      }
    }

    // Check if the rock is visible on the screen
    if (rock.isVisible())
    {
      rock.direction.y += player.getGravity() * dt;
    }
    // Check if the rock is no longer visible on the screen
    if (!rock.isVisible())
    {
      // Reset the flag to allow for another rock to be thrown
      rockThrew = false;
    }

    for (auto & enemy : enemies)
    {
      if (rock.isCollide(enemy) && rock.isVisible())
      {
        hit_sound.play();
        rock.setIsVisible(false);
        enemy.health --;
      }
    }
  }
}

void Game::setLives()
{
  NUMBER_OF_LIVES = 6;
  for (int i = 0; i < NUMBER_OF_LIVES; i++)
  {
    lives[i].initialiseSprite(hearts,"Data/Images/heart.png");
    lives[i].getSprite()->setScale(0.15f, 0.15f);
  }
  NUMBER_OF_LIVES = 3;
}

void Game::scoreSetText()
{
  score_text.setString("0");
  score_text.setFont(pixel_font);
  score_text.setCharacterSize(45);score_text.setPosition( view.getSize().x - score_text.getGlobalBounds().width - 30, 10);
  score_text.setFillColor(sf::Color::White);
}

void Game::ammoSetText()
{
  display_rock.setTexture(rock_texture);
  display_rock.setScale(3,3);
  ammo_text.setString("0");
  ammo_text.setFont(pixel_font);
  ammo_text.setCharacterSize(45);
  ammo_text.setFillColor(sf::Color::White);
}

void Game::UI_FixPosition(const float& dt)
{
  sf::Vector2f playerPosition = player.getSprite()->getPosition();
  sf::Vector2f direction      = playerPosition - cameraTarget.getPosition();

  // Normalize the direction vector to smooth the camera movement
  float length =
    std::sqrt(direction.x * direction.x + direction.y * direction.y);
  if (length > 0.0f)
  {
    direction /= length;
  }

  // Move the cameraTarget towards the player in the x-direction
  float movementSpeed = 700.0f;
  cameraTarget.move(direction.x * movementSpeed * dt, 0);

  sf::Vector2f halfScreen  = view.getSize() / 2.0f;
  sf::Vector2f relativePos = view.getCenter() - halfScreen;

  // Update the view center to follow the player on the X-axis
  view.setCenter(cameraTarget.getPosition().x, halfScreen.y);

  // Set the position of the texts to the relative position based on the updated view center
  score_text.setPosition(
    view.getCenter().x + halfScreen.x - 50.0f -
      score_text.getGlobalBounds().width,
    15);
  display_rock.setPosition(
    view.getCenter().x + display_rock.getGlobalBounds().width - 15.0f, 15.0f);
  ammo_text.setPosition(
    view.getCenter().x - ammo_text.getGlobalBounds().width + 15.0f, 15.0f);
  background.getSprite()->setPosition(relativePos);
  forrest_background.getSprite()->setPosition(relativePos);
  for (int i = 0; i < NUMBER_OF_LIVES; i++)
  {
    lives[i].getSprite()->setPosition(
      relativePos.x + 10.0f + 30.0f * i, relativePos.y);
  }
}

void Game::uiDraw(sf::RenderWindow& window)
{
  window.draw(score_text);
  window.draw(ammo_text);
  score_text.setString(std::to_string(score));
  ammo_text.setString(std::to_string(ammo));
  for (int i = 0; i < NUMBER_OF_LIVES; i++)
  {
    lives[i].drawObject(window);
  }
}

void Game::setupLevel1()
{
  background.initialiseSprite(background_texture,"Data/Images/lvl3.png");
  background.getSprite()->setScale(0.7,0.7);
  background.getSprite()->setColor(sf::Color(255, 255, 255, 220));
  setTiles();
  setItems();
}

void Game::level1Draw(sf::RenderWindow& window)
{
  background.drawObject(window);
  window.draw(candy_map);
  window.draw(candy_items);
}

void Game::level1GamePlay()
{
  for (int i = 0; i < candy_map.MAX_TILE_COUNT; ++i)
  {
    if (candy_map.tile_array[i]->getCollider().checkCollision(
          player.getCollider(),
          player.direction,
          candy_map.tile_array[i]->isVisible()))
    {
      player.onCollision(player.direction);
    }
  }

  for (int i = 0; i < candy_items.MAX_TILE_COUNT; ++i)
  {
    if (candy_items.tile_array[i]->getCollider().checkCollision(
          player.getCollider(),
          player.direction,
          candy_items.tile_array[i]->isVisible()))
    {
      collect_sound.play();
      candy_items.tile_array[i]->setIsVisible(false);
      static_cast<Collectible*>(candy_items.tile_array[i])->collect(this);
    }
  }
}

void Game::setupLevel2()
{
  forrest_background.initialiseSprite(forrest_background_texture,"Data/Images/lvl1.png");
  forrest_background.getSprite()->setScale(0.7,0.7);
  forrest_background.getSprite()->setColor(sf::Color(255, 255, 255, 220));
  setLvl2Tiles();
  setLvl2Items();
}

void Game::level2Draw(sf::RenderWindow& window)
{
  forrest_background.drawObject(window);
  window.draw(forrest_map);
  window.draw(forrest_item);
}

void Game::level2GamePlay()
{
  for (int i = 0; i < forrest_map.MAX_TILE_COUNT; ++i)
  {
    //on colision moves the player back to ensure it is not moving inside the platforms
    if (forrest_map.tile_array[i]->getCollider().checkCollision(
          player.getCollider(),
          player.direction,
          forrest_map.tile_array[i]->isVisible()))
    {
      player.onCollision(player.direction);
    }
  }

  //collecting items
  for (int i = 0; i < forrest_item.MAX_TILE_COUNT; ++i)
  {
    if (forrest_item.tile_array[i]->getCollider().checkCollision(
          player.getCollider(),
          player.direction,
          forrest_item.tile_array[i]->isVisible()))
    {
      collect_sound.play();
      forrest_item.tile_array[i]->setIsVisible(false);
      static_cast<Collectible*>(forrest_item.tile_array[i])->collect(this);
    }
  }
}

void Game::highScoreGet()
{
  std::ifstream readFile;
  readFile.open("Data/Highscore.txt");

  if (readFile.is_open())
  {
    readFile >> high_score;
    readFile.close();
  }

  //put the new score in the txt file if it is bigger than previous high-sore
  if (score > high_score)
  {
    high_score = score;
    std::ofstream  writeFile("Data/Highscore.txt");
    if(writeFile.is_open())
    {
      writeFile << high_score;
      writeFile.close();
    }
  }
}

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{}

bool Game::init()
{
  game_state = GameStates::MENU;
  menuSetText();
  sateTexts();
  loadingTextures();
  loadingFonts();
  loadingSounds();
  setupLevel1();
  setupLevel2();
  setPlayer();
  setEnemies();
  setLives();
  setRocks();
  scoreSetText();
  ammoSetText();
  view = sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
  window.setView(view);
  cameraTarget.setSize(sf::Vector2f(1.0f, 1.0f));
  cameraTarget.setOrigin(cameraTarget.getSize().x / 2.0f, cameraTarget.getSize().y / 2.0f);

  return true;
}

void Game::update(float dt)
{
  if(game_state == GameStates::PLAY_GAME)
  {
    UI_FixPosition(dt);
    throwRock(dt);
    updateEnemiesAnim(dt);
    player.movePlayer(dt);
    updatePlayerAnim(dt);
    if (!level1_complete)
    {
      level1GamePlay();
    }
    else
    {
      level2GamePlay();
    }
  }
}

void Game::render()
{
  window.clear();
  if (game_state == GameStates::PLAY_GAME)
  {


    //window.setView(sf::View(view));
    if (!level1_complete)
    {
      level1Draw(window);
    }
    else
    {
      level2Draw(window);
    }
    window.draw(display_rock);
    player.drawObject(window);
    for (int i = 0; i < 10; i++)
    {
      if (rocks[i].isVisible())
      {
        rocks[i].drawObject(window);
      }
    }
    for (auto& enemy : enemies)
    {
      enemy.drawObject(window);
    }
    uiDraw(window);
  }
  else
  {
    if (game_state == GameStates::MENU || game_state == GameStates::PAUSE_GAME)
    {
      instruction_pic.drawObject(window);
    }
    else if (game_state == GameStates::GAME_OVER || game_state == GameStates::WIN_GAME)
    {
      window.draw(high_score_t);
    }

    view = sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    //window.setView(view);
    sateTexts();
    window.draw(menu_text);
    window.draw(start_text);
  }
  window.setView(view);
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::keyPressed(sf::Event event)
{
  if (game_state == GameStates::PLAY_GAME)
  {
    if (event.key.code == sf::Keyboard::Q && event.type == sf::Event::KeyPressed)
    {
      throwing = true;
    }
    else if (
      event.key.code == sf::Keyboard::Escape)
    {
      game_state = GameStates::PAUSE_GAME;
    }
    else if (
      event.key.code == sf::Keyboard::Space && player.isGrounded())
    {
      jumps_sound.play();
    }
  }
  else if (game_state == GameStates::PAUSE_GAME)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      game_state = GameStates::PLAY_GAME;
    }
    else if (
      event.key.code == sf::Keyboard::Escape)
    {

      game_state = GameStates::MENU;
    }
  }
  else if (game_state == GameStates::MENU)
  {
    score = 0;
    level1_complete = false;
    resetItems();
    setPlayer();
    setLives();
    setRocks();
    ammo = 5;
    setEnemies();
    if (event.key.code == sf::Keyboard::Enter)
    {
      game_state = GameStates::PLAY_GAME;
    }
    else if (
      event.key.code == sf::Keyboard::Escape)
    {
      window.close();
    }
  }
  else if (game_state == GameStates::GAME_OVER || game_state == GameStates::WIN_GAME)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      game_state = GameStates::MENU;
    }
    else if (
      event.key.code == sf::Keyboard::Escape)
    {
      window.close();
    }
  }
}
void  Game::keyReleased(sf::Event event)
{
  if (game_state == GameStates::PLAY_GAME)
  {
    if (event.key.code == sf::Keyboard::Q && event.type == sf::Event::KeyReleased)
    {
      throwing = false;
    }
  }

}
