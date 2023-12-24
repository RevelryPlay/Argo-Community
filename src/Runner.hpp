#pragma once
#if OPTS_USE_OPENGL
#include "OpenGL/GLGame.hpp"
#include "OpenGL/GLScene.hpp"
#endif

#if OPTS_USE_VULKAN
#include "Vulkan/VKGame.hpp"
#include "Vulkan/VKScene.hpp"
#endif

#include "System/Game.hpp"

namespace Argo {
struct Runner {
    int run();

  private:
#if OPTS_USE_OPENGL
    System::Game< Graphics::GLGame > game{ *new System::Game< Graphics::GLGame >() };
    Graphics::GLScene scene{ *new Graphics::GLScene() };
    Graphics::GLCamera camera{ *new Graphics::GLCamera() };

    Graphics::GLEntity entity{ *new Graphics::GLEntity() };
    Graphics::GLSprite sprite{ *new Graphics::GLSprite() };
#endif

#if OPTS_USE_VULKAN
    System::Game< Graphics::VKGame > game{ *new System::Game< Graphics::VKGame >() };
    Graphics::VKScene scene{ *new Graphics::VKScene() };
    Graphics::VKCamera camera{ *new Graphics::VKCamera() };
    Graphics::VKEntity entity{ *new Graphics::VKEntity() };
    Graphics::VKSprite sprite{ *new Graphics::VKSprite() };
#endif

    void setup_callback();
    void run_callback();
    void update_callback( float deltaTime );
    void delta_callback( float deltaTime );
    void close_callback();

    void key_pressed_callback( float key );
    void key_released_callback( float key );
};
}  // namespace Argo
