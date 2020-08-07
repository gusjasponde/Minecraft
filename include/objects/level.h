#pragma once

#include <objects/wall.h>
#include <objects/points10.h>
#include <objects/points50.h>
#include <objects/pacman.h>
#include <vector>

namespace Objects {
  class Level : public Entity {
  public:
    Level(const glm::vec2& pos, std::shared_ptr<Render::MasterRenderer> renderer);
    std::vector<std::shared_ptr<Wall>> getWalls();
    std::vector<std::shared_ptr<Points10>> getPoints10();
    std::vector<std::shared_ptr<Points50>> getPoints50();
    void draw();

  private:
    const std::vector<std::vector<int>> levelLayout {
      {10, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 42, 40, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 12},
      {59, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 65, 60, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 58},
      {59, 01, 30, 64, 64, 32, 01, 30, 64, 64, 64, 32, 01, 60, 60, 01, 30, 64, 64, 64, 32, 01, 30, 64, 64, 32, 01, 58},
      {59, 02, 65, 00, 00, 65, 01, 65, 00, 00, 00, 65, 01, 60, 60, 01, 65, 00, 00, 00, 65, 01, 65, 00, 00, 65, 02, 58},
      {59, 01, 31, 64, 64, 33, 01, 31, 64, 64, 64, 33, 01, 31, 33, 01, 31, 64, 64, 64, 33, 01, 31, 64, 64, 33, 01, 58},
      {59, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 58},
      {59, 01, 30, 64, 64, 32, 01, 30, 32, 01, 30, 64, 64, 64, 64, 64, 64, 32, 01, 30, 32, 01, 30, 64, 64, 32, 01, 58},
      {59, 01, 31, 64, 64, 33, 01, 65, 65, 01, 31, 64, 64, 32, 30, 64, 64, 33, 01, 65, 65, 01, 31, 64, 64, 33, 01, 58},
      {59, 01, 01, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 01, 01, 58},
      {11, 57, 57, 57, 57, 32, 01, 65, 31, 64, 64, 32, 00, 65, 65, 00, 30, 64, 64, 33, 65, 01, 30, 57, 57, 57, 57, 13},
      {00, 00, 00, 00, 00, 59, 01, 65, 30, 64, 64, 33, 00, 31, 33, 00, 31, 64, 64, 32, 65, 01, 50, 00, 00, 00, 00, 00},
      {00, 00, 00, 00, 00, 59, 01, 65, 65, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 65, 65, 01, 50, 00, 00, 00, 00, 00},
      {00, 00, 00, 00, 00, 59, 01, 65, 65, 00, 20, 57, 57, 57, 57, 57, 57, 22, 00, 65, 65, 01, 50, 00, 00, 00, 00, 00},
      {56, 56, 56, 56, 56, 33, 01, 31, 33, 00, 58, 00, 00, 00, 00, 00, 00, 59, 00, 31, 33, 01, 31, 56, 56, 56, 56, 56},
      {00, 00, 00, 00, 00, 00, 01, 00, 00, 00, 58, 00, 00, 00, 00, 00, 00, 59, 00, 00, 00, 01, 00, 00, 00, 00, 00, 00},
      {57, 57, 57, 57, 57, 32, 01, 30, 32, 00, 58, 00, 00, 00, 00, 00, 00, 59, 00, 30, 32, 01, 30, 57, 57, 57, 57, 57},
      {00, 00, 00, 00, 00, 59, 01, 65, 65, 00, 21, 56, 56, 56, 56, 56, 56, 23, 00, 65, 65, 01, 50, 00, 00, 00, 00, 00},
      {00, 00, 00, 00, 00, 59, 01, 65, 65, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 65, 65, 01, 50, 00, 00, 00, 00, 00},
      {00, 00, 00, 00, 00, 59, 01, 65, 65, 00, 30, 64, 64, 64, 64, 64, 64, 32, 00, 65, 65, 01, 50, 00, 00, 00, 00, 00},
      {10, 56, 56, 56, 56, 33, 01, 31, 33, 00, 31, 64, 64, 32, 30, 64, 64, 33, 00, 31, 33, 01, 31, 56, 56, 56, 56, 12},
      {59, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 58},
      {59, 01, 30, 64, 64, 32, 01, 30, 64, 64, 64, 32, 01, 65, 65, 01, 30, 64, 64, 64, 32, 01, 30, 64, 64, 32, 01, 58},
      {59, 01, 31, 64, 32, 65, 01, 31, 64, 64, 64, 33, 01, 31, 33, 01, 31, 64, 64, 64, 33, 01, 65, 30, 64, 33, 01, 58},
      {59, 02, 01, 01, 65, 65, 01, 01, 01, 01, 01, 01, 01, 00, 00, 01, 01, 01, 01, 01, 01, 01, 65, 65, 01, 01, 02, 58},
      {46, 64, 32, 01, 65, 65, 01, 30, 32, 01, 30, 64, 64, 64, 64, 64, 64, 32, 01, 30, 32, 01, 65, 65, 01, 30, 64, 43},
      {47, 64, 33, 01, 31, 33, 01, 65, 65, 01, 31, 64, 64, 32, 30, 64, 64, 33, 01, 65, 65, 01, 31, 33, 01, 31, 64, 44},
      {59, 01, 01, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 65, 65, 01, 01, 01, 01, 01, 01, 58},
      {59, 01, 30, 64, 64, 64, 64, 33, 31, 64, 64, 32, 01, 65, 65, 01, 30, 64, 64, 33, 31, 64, 64, 64, 64, 32, 01, 58},
      {59, 01, 31, 64, 64, 64, 64, 64, 64, 64, 64, 33, 01, 31, 33, 01, 31, 64, 64, 64, 64, 64, 64, 64, 64, 33, 01, 58},
      {59, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 58},
      {11, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 13},
    };

    std::vector<std::shared_ptr<Wall>> m_walls;
    std::vector<std::shared_ptr<Points10>> m_points10;
    std::vector<std::shared_ptr<Points50>> m_points50;
  };
}  // namespace Objects