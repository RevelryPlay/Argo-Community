#include "BaseGame.hpp"

#include <chrono>

namespace Argo::Types {

BaseGame::BaseGame() = default;

BaseGame::~BaseGame() { BaseGame::Cleanup(); }

bool BaseGame::Setup() { return Setup( "", 0, 0 ); }

bool BaseGame::Setup( const char * /*title*/, int /*width*/, int /*height*/ ) {
    RunCallback( "setup", 0 );

    isRunning = true;
    return true;
}

void BaseGame::Run() {
    auto previousTime = std::chrono::high_resolution_clock::now();
    RunCallback( "run", 0 );

    // Update  before the run loop begins
    RunCallback( "update", 0 );

    while ( isRunning ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Update the caller every iteration
        RunCallback( "update", deltaTime );

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime ) {
            RunCallback( "delta", deltaTime );
            previousTime = currentTime;
        }
    }
};

void BaseGame::Cleanup() {}

}  // namespace Argo::Types
