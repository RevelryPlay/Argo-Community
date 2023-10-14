#include "System/Graphics/GLWindow.hpp"

// This works but needs a delta value param
int updateCallback()
{
  return 0;
}

int main(int /*unused*/, char ** /*unused*/)
{
  //  Argo::System::Game game = *new Argo::System::Game();
  //
  //  if (!game.init()) {
  //    fprintf(stderr, "Failed to initialize the game. See the logs about for more details.");
  //    return -1;
  //  }
  //  game.run();

  Argo::System::GLWindow window = *new Argo::System::GLWindow();
  window.init("Hello World", 1024, 768);
  window.update(&updateCallback);
  window.cleanup();

  return 0;
}
