
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObject.h"
#include "Animation.h"
#include "TileMap.h"
#include "Player.h"
#include "Tile.h"
#include "Collectible.h"
#include "IItemConfig.h"
#include <cmath>
#include "fstream"


class Game : public IItemConfig
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

  enum GameStates
  {
    MENU = 1,
    PLAY_GAME = 2,
    GAME_OVER = 3,
    WIN_GAME = 4,
    PAUSE_GAME = 5
  };
  GameStates game_state;

  virtual void increaseScore(int score) override;
  virtual void increaseHealth(int health) override;
  virtual void setNewSpawn(sf::Vector2f position) override;
  virtual void levelAchieved(bool game_won) override;
  virtual void increaseAmmunition(int ammo) override;
  virtual void doubleTheScore(int multiplier) override;
  sf::Vector2f spawn_position;
  bool level1_complete= false;

 private:

  sf::RenderWindow& window;

  void loadingTextures();
  void loadingFonts();
  void loadingSounds();

  //sounds
  sf::Music background_music;
  sf::SoundBuffer jumps_buffer;
  sf::SoundBuffer attack_buffer;
  sf::SoundBuffer hit_buffer;
  sf::SoundBuffer win_buffer;
  sf::SoundBuffer dead_buffer;
  sf::SoundBuffer collect_buffer;
  sf::SoundBuffer enemy_defeated_buffer;
  sf::Sound jumps_sound;
  sf::Sound attack_sound;
  sf::Sound hit_sound;
  sf::Sound win_sound;
  sf::Sound dead_sound;
  sf::Sound collect_sound;
  sf::Sound enemy_defeated_sound;

  //menu
  void menuSetText();
  void sateTexts();
  sf::Text menu_text;
  sf::Text start_text;
  sf::Texture instruction_tx;
  GameObject instruction_pic;

  //UI
  void scoreSetText();
  void UI_FixPosition(const float& dt);
  void uiDraw(sf::RenderWindow& window);
  sf::View view;
  sf::Text score_text;
  int score = 0;
  void highScoreGet();
  int high_score;
  sf::Text high_score_t;
  sf::RectangleShape cameraTarget;

  //lvl1
  void setItems();
  void setTiles();
  void level1Draw(sf::RenderWindow& window);
  void setupLevel1();
  void level1GamePlay();
  TileMap candy_map;
  TileMap candy_items;
  GameObject background;
  sf::Texture background_texture;

  //lvl2
  void setLvl2Items();
  void setLvl2Tiles();
  void level2Draw(sf::RenderWindow& window);
  void setupLevel2();
  void level2GamePlay();
  sf::Vector2f enemy_spawn_positions_2[4];
  TileMap forrest_map;
  TileMap forrest_item;
  GameObject forrest_background;
  sf::Texture forrest_background_texture;

  //lives
  void setLives();
  int NUMBER_OF_LIVES = 0;
  GameObject lives[6];
  sf::Texture hearts;

  //fonts
  sf::Font pixel_font;

  //player
  void setPlayer();
  void updatePlayerAnim(const float& dt);
  Player player;
  sf::Texture player_texture;
  sf::Texture player_run_texture;
  sf::Texture player_jump_texture;
  sf::Texture player_attack_texture;
  Animation player_jump_animation;
  Animation player_animation;
  Animation player_run_animation;
  Animation player_attack_animation;
  void playerDied();

  //enemies
  sf::Vector2f enemy_spawn_positions[4];
  Enemy enemies[4];
  void setEnemies();
  void updateEnemiesAnim(const float& dt);
  sf::Texture blue_enemy_texture;
  sf::Texture red_enemy_texture;
  sf::Texture yellow_enemy_texture;
  sf::Texture green_enemy_texture;
  Animation green_enemy_anim;

  //ammo
  void setRocks();
  void throwRock(const float& dt);
  GameObject rocks[10];
  sf::Texture rock_texture;
  sf::Sprite display_rock;
  sf::Text ammo_text;
  int ammo = 5;
  const float shot_delay = 1.0f;
  bool  throwing = false;
  bool rockThrew = false;
  void ammoSetText();
  void resetItems();

};

#endif // PLATFORMER_GAME_H
