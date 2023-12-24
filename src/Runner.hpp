#pragma once
#if OPTS_USE_OPENGL
#include "OpenGL/GLGame.hpp"
#include "OpenGL/GLScene.hpp"
#endif

#if OPTS_USE_VULKAN
#include "Vulkan/VKGame.hpp"
#include "Vulkan/VKScene.hpp"
#endif

#include "System/Camera.hpp"
#include "System/Entity.hpp"
#include "System/Game.hpp"
#include "System/Scene.hpp"
#include "System/Sprite.hpp"

namespace Argo {
struct Runner {
    int run();

  private:
#if OPTS_USE_OPENGL
    System::Game< Graphics::GLGame > game{ *new System::Game< Graphics::GLGame >() };
    System::Scene< Graphics::GLScene > scene{ *new System::Scene< Graphics::GLScene >() };
    System::Camera< Graphics::GLCamera > camera{ *new System::Camera< Graphics::GLCamera >() };

    System::Entity< Graphics::GLEntity > entity{ *new System::Entity< Graphics::GLEntity >() };
    System::Sprite< Graphics::GLSprite > sprite{ *new System::Sprite< Graphics::GLSprite >() };
#endif

#if OPTS_USE_VULKAN
    System::Game< Graphics::VKGame > game{ *new System::Game< Graphics::VKGame >() };
    System::Scene< Graphics::VKScene > scene{ *new System::Scene< Graphics::VKScene >() };
    System::Camera< Graphics::VKCamera > camera{ *new System::Camera< Graphics::VKCamera >() };

    System::Entity< Graphics::VKEntity > entity{ *new System::Entity< Graphics::VKEntity >() };
    System::Sprite< Graphics::VKSprite > sprite{ *new System::Sprite< Graphics::VKSprite >() };
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
