#include "BaseGame.hpp"


#include <iostream>

namespace Argo::Types {

BaseGame::BaseGame() = default;

BaseGame::~BaseGame() { BaseGame::Cleanup(); }

bool BaseGame::Setup() { return Setup( "", 0, 0 ); }

bool BaseGame::Setup( const char * /*title*/, const int width, const int height ) {
    RunCallback( "setup", 0 );

    width_ = width;
    height_ = height;

    isRunning_ = true;
    return true;
}

void BaseGame::Run() {
    auto previousTime = std::chrono::high_resolution_clock::now();
    RunCallback( "run", 0 );

    // Update  before the run loop begins
    RunCallback( "update", 0 );

    while ( isRunning_ ) {
        // Handle Event Loop
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration< float, std::milli >( currentTime - previousTime ).count();

        // Update the caller every iteration
        RunCallback( "update", deltaTime );

        // Lock the window update calls to the target frame rate
        if ( deltaTime > targetTime_ ) {
            this->UpdateFPS();

            RunCallback( "delta", deltaTime );
            previousTime = currentTime;
        }
    }
}

int BaseGame::GetWidth() const { return width_; }
void BaseGame::SetWidth( const int width ) { width_ = width; }

int BaseGame::GetHeight() const { return height_; }
void BaseGame::SetHeight( const int height ) { height_ = height; }

bool BaseGame::GetIsRunning() const { return isRunning_; }

void BaseGame::UpdateFPS() {
    const std::chrono::time_point< std::chrono::steady_clock > currentTime = std::chrono::high_resolution_clock::now();
    const float deltaTime = std::chrono::duration< float, std::milli >( currentTime - fpsPreviousTime_ ).count();

    fpsCounter_++;

    if ( deltaTime > 1000 ) {
        fps_ = fpsCounter_;
        fpsCounter_ = 0;
        fpsPreviousTime_ = currentTime;

        std::cout << "FPS: " << fps_ << '\n';
    }
}

float BaseGame::GetFPS() const { return fps_; }


void BaseGame::Cleanup() {
    RunCallback( "cleanup", 0 );
    isRunning_ = false;
}

}  // namespace Argo::Types
