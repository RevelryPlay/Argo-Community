#pragma once
#include "Graphics/OpenGL/GLScene.hpp"
#include "System/Game.hpp"

namespace Argo {
class Runner {
  public:
    int run();

  private:
    System::Game< System::GLGame > game = *new System::Game< System::GLGame >();
    Graphics::GLScene scene = *new Graphics::GLScene();
    Graphics::GLCamera camera = *new Graphics::GLCamera();

    Graphics::GLEntity entity = *new Graphics::GLEntity();
    Graphics::GLSprite sprite = *new Graphics::GLSprite();

    void setup_callback(float /*unused*/);
    void run_callback(float /*unused*/);
    void update_callback( float deltaTime );
    void delta_callback( float deltaTime );
    void close_callback(float /*unused*/);
};
}  // namespace Argo
