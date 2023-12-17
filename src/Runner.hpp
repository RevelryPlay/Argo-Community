#pragma once
#include "OpenGL/GLGame.hpp"
#include "OpenGL/GLScene.hpp"
#include "System/Game.hpp"

namespace Argo {
class Runner {
  public:
    int run();

  private:
    System::Game< Graphics::GLGame > game{ *new System::Game< Graphics::GLGame >() };
    Graphics::GLScene scene{ *new Graphics::GLScene() };
    Graphics::GLCamera camera{ *new Graphics::GLCamera() };

    Graphics::GLEntity entity{ *new Graphics::GLEntity() };
    Graphics::GLSprite sprite{ *new Graphics::GLSprite() };

    void setup_callback();
    void run_callback();
    void update_callback( float deltaTime );
    void delta_callback( float deltaTime );
    void close_callback();

    void key_pressed_callback( float key );
    void key_released_callback( float key );
};
}  // namespace Argo
