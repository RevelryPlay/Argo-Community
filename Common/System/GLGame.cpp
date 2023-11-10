#include "GLGame.hpp"

#include <chrono>
#include <iostream>

namespace Argo::System {
GLGame::GLGame() = default;

GLGame::~GLGame() { GLGame::cleanup(); };

bool GLGame::init( const char *title, const int width, const int height, const function< int() > &initCallback ) {
    window = *new GLWindow();
    window.init( title, width, height );

    if ( initCallback != nullptr ) {
        initCallback();
    }

    return window.isOpen;
}

void GLGame::run( const function< int( float ) > &runCallback ) {
    // TODO: Investigate if this is reliable for games
    auto previousTime = std::chrono::high_resolution_clock::now();
    float const targetTime = 1.0F / Argo::Common::TARGET_FPS * 1000;

    // Update the window before the run loop begins
    window.update( 0, UpdateCallback );

    while ( window.isOpen ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        GLGame::deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Game loop events
        handleEvents();

        // Update the caller every iteration
        update( GLGame::deltaTime, runCallback );

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            window.update( deltaTime, UpdateCallback );
            previousTime = currentTime;
        }
    }
}

void GLGame::handleEvents() {}

void GLGame::update( float deltaTime, const function< int( float ) > &updateCallback ) {
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

void GLGame::cleanup() {
    // NOTE: Destroy instances in reverse order of creation
    window.cleanup();
}

}  // namespace Argo::System
