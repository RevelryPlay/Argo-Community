#pragma once

#include "../Common/System/Window.hpp"
#include "../Common/Types/BaseGame.hpp"
#include "VKScene.hpp"
#include "VKWindow.hpp"

namespace Argo::Graphics {

/**
 * \brief `GLGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
struct VKGame : Types::BaseGame {
    VKGame();
    ~VKGame() override;

    VKScene *activeScene{};
    System::Window< VKWindow > *window{ nullptr };

    bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    void Run() override;

  private:
    void Cleanup() override;
};

}  // namespace Argo::Graphics