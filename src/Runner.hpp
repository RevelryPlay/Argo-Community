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

    static int setup_callback();
    static int run_callback();
    static int update_callback( float deltaTime );
    static int delta_callback( float deltaTime );
};
}  // namespace Argo
