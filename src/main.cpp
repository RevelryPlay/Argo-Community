#include "System/GLGame.hpp"

#include <iostream>

using namespace Argo::System;

int main(int /*unused*/, char ** /*unused*/)
{
    auto game = *new GLGame();

    if (!game.init()) {
      fprintf(stderr, "Failed to initialize the game. See the logs about for more details.");
      return -1;
    }
    game.run();

  return 0;
}
