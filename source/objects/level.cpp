#include <objects/level.h>

std::vector<Objects::Direction> buildDirections(const std::vector<std::vector<int>>& layout, int i,
                                                int j) {
  std::vector<Objects::Direction> dir = std::vector<Objects::Direction>();
  if (layout[i + 1][j] == 0 || layout[i + 1][j] == 1) dir.push_back(Objects::Direction::DOWN);
  if (layout[i - 1][j] == 0 || layout[i - 1][j] == 1) dir.push_back(Objects::Direction::UP);
  if (layout[i][j + 1] == 0 || layout[i][j + 1] == 1) dir.push_back(Objects::Direction::RIGHT);
  if (layout[i][j - 1] == 0 || layout[i][j - 1] == 1) dir.push_back(Objects::Direction::LEFT);

  return dir;
}

Objects::Level::Level(const glm::vec2& pos, std::shared_ptr<Render::MasterRenderer> renderer)
    : Entity({0.0f, 0.0f}, pos, {0.f, 0.f}, Collision::Hitbox({0.0, 0.0}, pos)) {
  this->m_walls = std::vector<std::shared_ptr<Wall>>();
  this->m_points10 = std::vector<std::shared_ptr<Points10>>();
  this->m_points50 = std::vector<std::shared_ptr<Points50>>();

  for (unsigned int i = 0; i < this->levelLayout.size(); i++) {
    for (unsigned int j = 0; j < this->levelLayout[i].size(); j++) {
      glm::vec2 tilePos = {j * 16.0f, i * 16.0f};
      tilePos += pos;
      switch (this->levelLayout[i][j]) {
        case 0:
          if (this->levelCorners[i][j])
            this->m_corners.push_back(
                std::shared_ptr<Corner>(new Corner(tilePos, buildDirections(levelLayout, i, j))));
          break;
        case 1:
          this->m_points10.push_back(std::shared_ptr<Points10>(new Points10(tilePos, renderer)));
          if (this->levelCorners[i][j])
            this->m_corners.push_back(
                std::shared_ptr<Corner>(new Corner(tilePos, buildDirections(levelLayout, i, j))));
          break;
        case 2:
          this->m_points50.push_back(std::shared_ptr<Points50>(new Points50(tilePos, renderer)));
          if (this->levelCorners[i][j])
            this->m_corners.push_back(
                std::shared_ptr<Corner>(new Corner(tilePos, buildDirections(levelLayout, i, j))));
          break;
        case 10 ... 69:
          Type type = (Type)this->levelLayout[i][j];
          this->m_walls.push_back(std::shared_ptr<Wall>(new Wall(type, tilePos, renderer)));
          break;
      }
    }
  }
}

void Objects::Level::draw() {
  for (auto wall = this->m_walls.begin(); wall != this->m_walls.end(); wall++) wall->get()->draw();
  for (auto point10 = this->m_points10.begin(); point10 != this->m_points10.end(); point10++)
    point10->get()->draw();
  for (auto point50 = this->m_points50.begin(); point50 != this->m_points50.end(); point50++)
    point50->get()->draw();
}

std::vector<std::vector<int>> Objects::Level::getLevelCorners() { return this->levelCorners; }

std::vector<std::shared_ptr<Objects::Corner>> Objects::Level::getCorners() {
  return this->m_corners;
}

std::vector<std::shared_ptr<Objects::Wall>> Objects::Level::getWalls() { return this->m_walls; }

std::vector<std::shared_ptr<Objects::Points10>> Objects::Level::getPoints10() {
  return this->m_points10;
}

std::vector<std::shared_ptr<Objects::Points50>> Objects::Level::getPoints50() {
  return this->m_points50;
}