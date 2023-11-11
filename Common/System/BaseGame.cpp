#include "BaseGame.hpp"
#include <chrono>

namespace Argo::System {

BaseGame::BaseGame() = default;

BaseGame::~BaseGame() { BaseGame::Cleanup(); };

bool BaseGame::Setup() {
    BaseGame::isRunning = true;

    return true;
}

void BaseGame::Run() {
    // TODO: Investigate if this is reliable for games
    auto previousTime = std::chrono::high_resolution_clock::now();

    // TODO: Determine what qualifies as running,
    // in a windowed environment this would be if the window is still open
    // in a consoled / headless environment this would be some other condition
    while ( BaseGame::isRunning ) {

        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        BaseGame::deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Game loop events
        Update();

        previousTime = currentTime;
    }
}

void BaseGame::Update() { }
void BaseGame::Cleanup() { }

}  // namespace Argo::System
