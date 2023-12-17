#pragma once

#include "../../Common/System/Window.hpp"
#include "../Common/System/BaseGame.hpp"
#include "GLScene.hpp"
#include "GLWindow.hpp"


namespace Argo::Graphics {

/**
 * \brief `GLGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
class GLGame : public System::BaseGame {
  public:
    GLGame();
    ~GLGame() override;

    GLScene *activeScene{};
    System::Window< GLWindow > *window{ nullptr };

    bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    void Run() override;

  private:
    void Cleanup() override;
};

}  // namespace Argo::Graphics
