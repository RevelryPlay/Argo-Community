#pragma once
#include <cstdint>

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
    // uint8_t enum for sprite direction
    enum SpriteDirection : uint8_t {
        UP = 0,
        UP_RIGHT = 1,
        UP_LEFT = 2,
        DOWN = 3,
        DOWN_RIGHT = 4,
        DOWN_LEFT = 5,
        LEFT = 6,
        RIGHT = 7
    };

    int spriteDirection{ 0 };

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
    void run_callback();
    void update_callback( float deltaTime );
    void delta_callback( float deltaTime );
    void close_callback();

    void key_pressed_callback( float key );
    void key_released_callback( float key );
};
}  // namespace Argo
