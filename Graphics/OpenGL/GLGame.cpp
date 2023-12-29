#include "GLGame.hpp"

#include <iostream>

namespace Argo::Graphics {
GLGame::GLGame() = default;

GLGame::~GLGame() { GLGame::Cleanup(); };

bool GLGame::Setup( const char *title, const int width, const int height ) {
    window = new System::Window< GLWindow >();
    window->init( title, width, height );
    window->callbacks = callbacks;

    RunCallback( "setup", 0 );

    return window->isOpen;
}

void GLGame::Run() {
    // TODO: Investigate if this is reliable for games
    auto previousTime{ std::chrono::high_resolution_clock::now() };
    float constexpr targetTime{ 1.0F / Argo::Common::TARGET_FPS * 1000 };

    RunCallback( "run", 0 );

    // Update the window before the run loop begins
    window->update( 0 );

    while ( window->isOpen ) {
        // Handle Event Loop
        auto currentTime{ std::chrono::high_resolution_clock::now() };
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Game loop events
        // handleEvents();

        // Update the caller every iteration
        RunCallback( "update", deltaTime );

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            window->update( deltaTime );
            // RunCallback("delta", deltaTime);
            previousTime = currentTime;
        }
    }

    RunCallback( "close", 0 );
}
GLScene *GLGame::CreateScene( const int width = 0, const int height = 0 ) {
    // Create a new scene
    auto *const scene{ new GLScene( width, height ) };

    // Add the scene to the list of scenes
    scenes_.push_back( scene );

    // return the scene pointer
    return scene;
}
std::list< GLScene * > GLGame::GetScenes() { return scenes_; }

// void GLGame::AddScene( System::Scene< GLScene > *scene ) { scenes_.push_back( scene ); }

void GLGame::RemoveScene( GLScene *scene ) {
    // Remove the scene from the list of scenes
    scenes_.remove( scene );

    // Delete the scene
    delete scene;
}

void GLGame::SetActiveScene( GLScene *scene ) { activeScene_ = scene; }

GLScene *GLGame::GetActiveScene() const { return activeScene_; }

void GLGame::Cleanup() {
    // NOTE: Destroy instances in reverse order of creation

    for ( GLScene *scene : scenes_ ) {
        RemoveScene( scene );
    }

    window->Cleanup();
    window = nullptr;
}

}  // namespace Argo::Graphics
