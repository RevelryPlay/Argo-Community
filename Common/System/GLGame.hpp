#pragma once
#include "Game.hpp"
#include "Graphics/GLWindow.hpp"

namespace Argo::System {

class GLGame : Game
{
public:
  GLGame();
  ~GLGame();

  bool init() override;
  void run() override;

private:
  GLWindow window;

  void cleanup();
  void handleEvents();
  void update();
  static int updateCallback(float deltaTime);
};

}// namespace Argo::System
