#pragma once
#include "Application.hpp"

namespace Argo::System {

class Game : Application {
  public:
    Game();
    virtual ~Game();

    bool init() override;
    void run() override;

    float deltaTime = 1.0F / Argo::Common::TARGET_FPS;

  private:
    bool isRunning = false;

    void cleanup();
    void handleEvents();
    void update();
    void render();
};

}  // namespace Argo::System
