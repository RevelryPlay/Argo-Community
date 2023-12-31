#include "GLGame.hpp"

#include <iostream>

namespace Argo::Graphics {
GLGame::GLGame() = default;

GLGame::~GLGame() { GLGame::Cleanup(); };

bool GLGame::Setup( const char *title, const int width, const int height ) {
    window = new System::Window<GLWindow>();
    window->init( title, width, height );
    window->callbacks = callbacks;

    RunCallback("setup", 0);

    return window->isOpen;
}

void GLGame::Run() {
    // TODO: Investigate if this is reliable for games
    auto previousTime = std::chrono::high_resolution_clock::now();
    float constexpr targetTime = 1.0F / Argo::Common::TARGET_FPS * 1000;

    RunCallback("run", 0);

    // Update the window before the run loop begins
    window->update( 0 );

    while ( window->isOpen ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Game loop events
        // handleEvents();

        // Update the caller every iteration
        RunCallback("update", deltaTime);

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            window->update( deltaTime );
            // RunCallback("delta", deltaTime);
            previousTime = currentTime;
        }
    }

    RunCallback("close", 0);
}

void GLGame::Cleanup() {
    // NOTE: Destroy instances in reverse order of creation
    window->cleanup();
}

}  // namespace Argo::System
