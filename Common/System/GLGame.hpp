#pragma once

#include "Game.hpp"
#include "Graphics/GLWindow.hpp"

namespace Argo::System {

class GLGame : Game
{
public:
  GLGame();

  ~GLGame();

  bool init(const char *title = "Hello Argo", int width = 1024, int height = 768, const function<int()> &initCallback = nullptr);
  void run() override;

private:
  GLWindow window;

  void cleanup();

  void handleEvents();

  void update();

  static int updateCallback(float deltaTime);
};

}// namespace Argo::System
