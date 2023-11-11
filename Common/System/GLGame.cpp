#include "GLGame.hpp"

#include <chrono>
#include <iostream>

namespace Argo::System {
GLGame::GLGame() = default;

GLGame::~GLGame() { GLGame::Cleanup(); };

bool GLGame::Setup( const char *title, const int width, const int height, const function< int() > &setup_callback ) {
    window = *new GLWindow();
    window.init( title, width, height );

    if ( setup_callback != nullptr ) {
        setup_callback();
    }

    return window.isOpen;
}

void GLGame::Run( const function< int( float ) > &run_callback ) {
    // TODO: Investigate if this is reliable for games
    auto previousTime = std::chrono::high_resolution_clock::now();
    float constexpr targetTime = 1.0F / Argo::Common::TARGET_FPS * 1000;

    // Update the window before the run loop begins
    window.update( 0, UpdateCallback );

    while ( window.isOpen ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Game loop events
        // handleEvents();

        // Update the caller every iteration
        Update( deltaTime, run_callback );

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            window.update( deltaTime, UpdateCallback );
            previousTime = currentTime;
        }
    }
}

void GLGame::Update( float deltaTime, const function< int( float ) > &updateCallback ) {
    if ( updateCallback != nullptr ) {
        updateCallback( deltaTime );
    }
}

int GLGame::UpdateCallback( float deltaTime ) {
    //    cout << "GLGame delta:" << deltaTime << '\n';
    //    cout << "GLGame Time:" << time( nullptr ) << '\n';
    glClearColor( 0.3f, 0.3f, 0.5f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    return 0;
}

void GLGame::Cleanup() {
    // NOTE: Destroy instances in reverse order of creation
    window.cleanup();
}

}  // namespace Argo::System
