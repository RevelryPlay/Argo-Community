#include "BaseGame.hpp"

#include <chrono>

namespace Argo::System {

BaseGame::BaseGame() = default;

BaseGame::~BaseGame() { BaseGame::Cleanup(); }
bool BaseGame::Setup( const char * /*title*/,
    int /*width*/,
    int /*height*/,
    const std::function< int() > &setup_callback ) {
    if ( setup_callback != nullptr ) {
        setup_callback();
    }

    isRunning = true;

    return true;
}

void BaseGame::Run( const std::function< int() > &run_callback,
    const std::function< int( float ) > &update_callback,
    const std::function< int( float ) > &delta_callback ) {

    auto previousTime = std::chrono::high_resolution_clock::now();

    if ( run_callback != nullptr ) {
        run_callback();
    }

    // Update  before the run loop begins
    update_callback( 0 );

    while ( isRunning ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Update the caller every iteration
        if ( update_callback != nullptr ) {
            update_callback( deltaTime );
        }

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            delta_callback( deltaTime );
            previousTime = currentTime;
        }
    }
};

void BaseGame::Cleanup() {}

}  // namespace Argo::System
