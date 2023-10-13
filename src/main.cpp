#include "System/Graphics/GLWindow.hpp"

// This works but needs a delta value param
int updateCallback()
{
  glClearColor(0.7f, 0.2f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

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
