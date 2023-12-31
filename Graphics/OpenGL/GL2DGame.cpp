#include "GL2DGame.hpp"

#include <iostream>

namespace Argo::Graphics {
GL2DGame::GL2DGame() = default;

GL2DGame::~GL2DGame() { GL2DGame::Cleanup(); };

bool GL2DGame::Setup( const char *title, const int width, const int height ) {
    window = new System::Window< GL2DWindow >();
    window->init( title, width, height );
    window->callbacks = callbacks;

    RunCallback( "setup", 0 );

    SetWidth( width );
    SetHeight( height );

    return window->isOpen;
}

int GL2DGame::Run() {
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
            UpdateFPS();

            window->update( deltaTime );
            // RunCallback("delta", deltaTime);
            previousTime = currentTime;
        }
    }

    RunCallback( "close", 0 );
    return 0;
}

GL2DScene *GL2DGame::CreateScene( const int width = 0, const int height = 0 ) {
    // Create a new scene
    auto *const scene{ new GL2DScene( width, height ) };

    // Add the scene to the list of scenes
    scenes_.push_back( scene );

    // Set the scene to active if no other scene is active
    if ( activeScene_ == nullptr ) {
        activeScene_ = scene;
    }

    // return the scene pointer
    return scene;
}
std::list< GL2DScene * > GL2DGame::GetScenes() { return scenes_; }

// void GL2DGame::AddScene( System::Scene< GL2DScene > *scene ) { scenes_.push_back( scene ); }

void GL2DGame::RemoveScene( GL2DScene *scene ) {
    // Remove the scene from being active
    if ( activeScene_ == scene ) {
        activeScene_ = nullptr;
    }

    // Remove the scene from the list of scenes
    scenes_.remove( scene );

    // Delete the scene
    delete scene;
}

void GL2DGame::SetActiveScene( GL2DScene *scene ) { activeScene_ = scene; }

GL2DScene *GL2DGame::GetActiveScene() const { return activeScene_; }

int GL2DGame::Cleanup() {
    // NOTE: Destroy instances in reverse order of creation
    activeScene_ = nullptr;

    // Remove all scenes
    for ( const GL2DScene *scene : scenes_ ) {
        delete scene;
    }

    scenes_.clear();

    window->Cleanup();
    window = nullptr;

    return 0;
}

}  // namespace Argo::Graphics
