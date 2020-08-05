#include <objects/pacman.h>

Objects::Pacman::Pacman(std::shared_ptr<Render::MasterRenderer> renderer)
    : Entity({32.0f, 32.0f}, {0.f, 0.f}, {1.f, 0.f}), m_renderer(renderer) {
  this->m_textures = std::vector<std::shared_ptr<SDL_Texture>>(PACMAN_ANIMATION_STATES);
  this->m_textures[0] = std::shared_ptr<SDL_Texture>(
      Utils::loadSDLTexture(renderer->renderer().get(), "resources/pacman_1.bmp"),
      [](SDL_Texture *t) { SDL_DestroyTexture(t); });
  this->m_textures[1] = this->m_textures[0];
  this->m_textures[2] = this->m_textures[0];
  this->m_textures[3] = this->m_textures[0];

  this->m_textures[4] = std::shared_ptr<SDL_Texture>(
      Utils::loadSDLTexture(renderer->renderer().get(), "resources/pacman_2.bmp"),
      [](SDL_Texture *t) { SDL_DestroyTexture(t); });
  this->m_textures[5] = this->m_textures[4];
  this->m_textures[6] = this->m_textures[4];
  this->m_textures[7] = this->m_textures[4];

  this->m_textures[8] = std::shared_ptr<SDL_Texture>(
      Utils::loadSDLTexture(renderer->renderer().get(), "resources/pacman_3.bmp"),
      [](SDL_Texture *t) { SDL_DestroyTexture(t); });
  this->m_textures[9] = this->m_textures[8];
  this->m_textures[10] = this->m_textures[8];
  this->m_textures[11] = this->m_textures[8];
}

void Objects::Pacman::handleInput(std::shared_ptr<Input::Input> input) {
  if (input->isKeyDown(Input::Action::UP)) {
    this->m_next_direction = UP;
  } else if (input->isKeyDown(Input::Action::DOWN)) {
    this->m_next_direction = DOWN;
  } else if (input->isKeyDown(Input::Action::LEFT)) {
    this->m_next_direction = LEFT;
  } else if (input->isKeyDown(Input::Action::RIGHT)) {
    this->m_next_direction = RIGHT;
  }
}

void Objects::Pacman::update(float dt) {
  this->hitbox.update(this->hitbox.pos += this->velocity * dt);
  this->m_animation_state += 1;
  if (this->m_animation_state == PACMAN_ANIMATION_STATES) this->m_animation_state = 0;
}

void Objects::Pacman::draw() {
  int state = this->m_animation_state % PACMAN_ANIMATION_STATES;
  SDL_Rect renderQuad{(int)this->hitbox.pos.x, (int)this->hitbox.pos.y, (int)this->hitbox.dim.x,
                      (int)this->hitbox.dim.y};

  SDL_RenderCopyEx(this->m_renderer->renderer().get(), this->m_textures[state].get(), NULL,
                   &renderQuad, 0, NULL, SDL_FLIP_NONE);
}