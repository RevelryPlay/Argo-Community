#include "System/GLGame.hpp"

#include <iostream>

using namespace Argo::System;

int main(int /*unused*/, char ** /*unused*/)
{
  auto game = *new GLGame();

  if (!game.init("Game Window", 1280, 720)) {
    fprintf(stderr, "Failed to initialize the game. See the logs about for more details.");
    return -1;
  }
  game.run();

  return 0;
}
