#pragma once
#if OPTS_USE_OPENGL
#include "OpenGL/GLEntity.hpp"
#include "OpenGL/GLGame.hpp"
#include "OpenGL/GLSprite.hpp"
#endif

#if OPTS_USE_VULKAN
#include "Vulkan/VKGame.hpp"
#include "Vulkan/VKScene.hpp"
#endif

namespace Argo {
struct Runner {
    int run();

  private:
#if OPTS_USE_OPENGL
    Graphics::GLGame game{ *new Graphics::GLGame() };
    Graphics::GLSprite sprite{ *new Graphics::GLSprite() };
#endif

#if OPTS_USE_VULKAN
    System::Game< Graphics::VKGame > game{ *new System::Game< Graphics::VKGame >() };
    System::Scene< Graphics::VKScene > scene{ *new System::Scene< Graphics::VKScene >() };
    System::Camera< Graphics::VKCamera > camera{ *new System::Camera< Graphics::VKCamera >() };

    System::Entity< Graphics::VKEntity > entity{ *new System::Entity< Graphics::VKEntity >() };
    System::Sprite< Graphics::VKSprite > sprite{ *new System::Sprite< Graphics::VKSprite >() };
#endif

    void setup_callback();
    void setup_callback_2();
    void run_callback();
    void update_callback( float deltaTime );
    void delta_callback( float deltaTime );
    void close_callback();

    void key_pressed_callback( float key );
    void key_released_callback( float key );
};
}  // namespace Argo
