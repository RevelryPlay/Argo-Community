#pragma once
#include "Application.hpp"

namespace Argo::System {

/**
 * \brief `BaseGame` is a type of `Application` that provides game specific functionality such as an `Update` loop,
 * an input handler and the properties `isRunning` and `deltaTime`
 */
class BaseGame : Application {
  public:
    BaseGame();
    ~BaseGame() override;

    bool Setup() override;
    void Run() override;

    float deltaTime = 1.0F / Argo::Common::TARGET_FPS;
    bool isRunning = false;

    void Cleanup() override;
    void Update();
};

}  // namespace Argo::System
