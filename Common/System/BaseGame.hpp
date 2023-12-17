#pragma once

#include "Application.hpp"

namespace Argo::System {

/**
 * \brief `BaseGame` is a type of `Application` that provides game specific functionality such as an `Update` loop,
 * an input handler and the properties `isRunning` and `deltaTime`
 */
class BaseGame : public Application {
  public:
    BaseGame();
    ~BaseGame() override;

    virtual bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT );

    void Run() override;

    float deltaTime{ 1.0F / Common::TARGET_FPS };
    bool isRunning{ false };

  private:
    static float constexpr targetTime{ 1.0F / Common::TARGET_FPS * 1000 };
    void Cleanup() override;
};

}  // namespace Argo::System
