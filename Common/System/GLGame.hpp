#pragma once

#include "BaseGame.hpp"
#include "Graphics/OpenGL/GLWindow.hpp"

namespace Argo::System {

using namespace Argo::Graphics;

/**
 * \brief `GLGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
class GLGame : BaseGame {
  public:
    GLGame();
    ~GLGame() override;

    bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT,
        int ( *setup_callback )() = nullptr );

    void Run( int ( *run_callback )() = nullptr,
        int ( *update_callback )( float ) = nullptr,
        int ( *delta_callback )( float ) = nullptr );

  private:
    GLWindow *window{};
    void Cleanup() override;
};

}  // namespace Argo::System
