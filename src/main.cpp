#include "System/GLGame.hpp"

#include <iostream>

int main(int /*unused*/, char ** /*unused*/)
{
    Argo::System::GLGame game = *new Argo::System::GLGame();

    if (!game.init()) {
      fprintf(stderr, "Failed to initialize the game. See the logs about for more details.");
      return -1;
    }
    game.run();

  return 0;
}
