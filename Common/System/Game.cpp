#include "Game.hpp"
#include <chrono>

namespace Argo::System {

Game::Game() = default;

Game::~Game() { cleanup(); };

bool Game::init()
{
  Game::isRunning = true;

  return true;
}

void Game::run()
{
  // TODO: Investigate if this is reliable for games
  auto previousTime = std::chrono::high_resolution_clock::now();

  // TODO: Determine what qualifies as running,
  // in a windowed environment this would be if the window is still open
  // in a consoled / headless environment this would be some other condition
  while (Game::isRunning) {

    // Handle Event Loop
    auto currentTime = std::chrono::high_resolution_clock::now();
    Game::deltaTime = std::chrono::duration<float, std::milli>(currentTime - previousTime).count();


    // Game loop events
    handleEvents();
    update();
    render();


    previousTime = currentTime;
  }
}

void Game::handleEvents() {}
void Game::update() {}
void Game::render() {}

void Game::cleanup()
{
  // TODO: Destroy instances in reverse order of creation
}

} // namespace Argo::System
