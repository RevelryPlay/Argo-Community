#pragma once
#include "Application.hpp"

namespace Argo::System {

class Game : Application {
  public:
    Game();
    ~Game() override;

    bool init() override;
    void run() override;

    float deltaTime = 1.0F / Argo::Common::TARGET_FPS;

    bool isRunning = false;

    void cleanup() override;
    virtual void handleEvents();
    void update();
    void render();
};

}  // namespace Argo::System
