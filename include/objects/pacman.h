#pragma once

#include <deleters.h>
#include <entity.h>
#include <input.h>
#include <input/actions.h>
#include <render/masterrenderer.h>
#include <utils.h>

#include <algorithm>
#include <memory>
#include <vector>

#define PACMAN_ANIMATION_STATES 15
#define PACMAN_DEATH_ANIMATION_STATES 17

namespace Objects {
  enum Direction { UP, DOWN, LEFT, RIGHT, NONE };
  class Pacman : public Entity {
  public:
    Pacman(std::shared_ptr<Render::MasterRenderer> renderer);
    void handleInput(std::shared_ptr<Input::Input> input);
    void update(float dt);
    void checkDirection(std::vector<Direction> directions);
    void kill();
    void draw();
    void reset();

  private:
    void changeDirection(Direction dir);
    void updateVelocity(glm::vec2 vel);

    bool m_is_dead = false;
    Direction m_direction = RIGHT;
    Direction m_next_direction = NONE;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures;
    std::vector<std::shared_ptr<SDL_Texture>> m_death_textures;
    std::shared_ptr<Render::MasterRenderer> m_renderer;
    bool m_initially_stuck = true;
    bool m_stuck = true;
    int m_animation_state = 9;
    int m_death_animation_state = 0;
    float dt;
  };
}  // namespace Objects