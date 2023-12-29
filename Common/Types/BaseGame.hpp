#pragma once

#include "../System/Application.hpp"
#include "BaseScene.hpp"
#include <chrono>

namespace Argo::Types {

using namespace Argo::System;

/**
 * \brief `BaseGame` is a type of `Application` that provides game specific functionality such as an `Update` loop,
 * an input handler and the properties `isRunning` and `deltaTime`
 */
struct BaseGame : Application {
    BaseGame();
    ~BaseGame() override;

    bool Setup() override;
    virtual bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT );

    void Run() override;

    int AddScene( BaseScene *scene );
    void UpdateFPS();
    [[nodiscard]] float GetFPS() const;

    float deltaTime{ 1.0F / Common::TARGET_FPS };

    bool isRunning{ false };

  private:
    static float constexpr targetTime_{ 1.0F / Common::TARGET_FPS * 1000 };

    float fpsCounter{ 0 };
    float fps{ 0 };
    std::chrono::time_point< std::chrono::steady_clock > fpsPreviousTime{ std::chrono::high_resolution_clock::now() };

    void Cleanup() override;
};

}  // namespace Argo::Types
