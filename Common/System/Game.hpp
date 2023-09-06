#pragma once
#include "Program.hpp"

namespace Argo::System {

struct Game : Program
{
  Game();
  ~Game();

  bool init() override;
  void run() override;


  // Initialize this to 60FPS, so we don't start the first frame with any
  // division by 0 errors or something
  float deltaTime = 1.0f / 60.0f;


private:
  bool isRunning = false;

  void cleanup();
  void handleEvents();
  void update();
  void render();
};

}// namespace Argo::System
