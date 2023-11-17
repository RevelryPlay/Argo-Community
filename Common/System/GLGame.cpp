#include "GLGame.hpp"

#include <iostream>

namespace Argo::System {
GLGame::GLGame() = default;

GLGame::~GLGame() { GLGame::Cleanup(); };

bool GLGame::Setup( const char *title, const int width, const int height, const function< int() > &setup_callback ) {
    window = new GLWindow();
    window->init( title, width, height );

    if ( setup_callback != nullptr ) {
        setup_callback();
    }

    return window->isOpen;
}

void GLGame::Run( const function< int() > &run_callback,
    const function< int( float ) > &update_callback,
    const function< int( float ) > &delta_callback ) {
    // TODO: Investigate if this is reliable for games
    auto previousTime = std::chrono::high_resolution_clock::now();
    float constexpr targetTime = 1.0F / Argo::Common::TARGET_FPS * 1000;

    if ( run_callback != nullptr ) {
        run_callback();
    }

    // Update the window before the run loop begins
    window->update( 0, update_callback );

    while ( window->isOpen ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Game loop events
        // handleEvents();

        // Update the caller every iteration
        if ( update_callback != nullptr ) {
            update_callback( deltaTime );
        }

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            window->update( deltaTime, delta_callback );
            previousTime = currentTime;
        }
    }
}

void GLGame::Cleanup() {
    // NOTE: Destroy instances in reverse order of creation
    window->cleanup();
}

}  // namespace Argo::System
