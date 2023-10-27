#pragma once
#include "Application.hpp"

namespace Argo::System {

class Game : Application {
  public:
    Game();
    virtual ~Game();

    bool init() override;
    void run() override;

    // Initialize this to 60FPS, so we don't start the first frame with any
    // division by 0 errors or something
    float deltaTime = 1.0F / Argo::Common::TARGET_FPS;

  private:
    bool isRunning = false;

    void cleanup();
    void handleEvents();
    void update();
    void render();
};

}  // namespace Argo::System
