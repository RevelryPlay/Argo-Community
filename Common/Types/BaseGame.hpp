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

    [[nodiscard]] int GetWidth() const;
    void SetWidth( const int width );

    [[nodiscard]] int GetHeight() const;
    void SetHeight( const int height );

    float deltaTime{ 1.0F / Common::TARGET_FPS };

    [[nodiscard]] bool GetIsRunning() const;

    // virtual BaseScene *CreateScene( const int width, const int height );
    // virtual std::list< BaseScene * > GetScenes();
    // virtual void RemoveScene( BaseScene *scene );
    // virtual void SetActiveScene( BaseScene *scene );
    // [[nodiscard]] virtual BaseScene *GetActiveScene() const;

    void UpdateFPS();
    [[nodiscard]] float GetFPS() const;

    void Cleanup() override;

  private:
    static float constexpr targetTime_{ 1.0F / Common::TARGET_FPS * 1000 };

    float fpsCounter_{ 0 };
    float fps_{ 0 };
    std::chrono::time_point< std::chrono::steady_clock > fpsPreviousTime_{ std::chrono::high_resolution_clock::now() };

    int width_{ 0 };
    int height_{ 0 };

    bool isRunning_{ false };
};

}  // namespace Argo::Types
