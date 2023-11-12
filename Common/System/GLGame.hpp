#pragma once

#include "BaseGame.hpp"
#include "Graphics/GLWindow.hpp"

namespace Argo::System {

using namespace Argo::Graphics;

/**
 * \brief `GLGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
class GLGame : BaseGame {
  public:
    GLGame();
    ~GLGame() override;

    bool Setup( const char *title = Argo::Common::DEFAULT_WINDOW_TITLE,
        int width = Argo::Common::DEFAULT_WINDOW_WIDTH,
        int height = Argo::Common::DEFAULT_WINDOW_HEIGHT,
        const std::function< int() > &setup_callback = nullptr ) override;

    void Run( const std::function< int() > &run_callback = nullptr,
        const std::function< int( float ) > &update_callback = nullptr,
        const std::function< int( float ) > &delta_callback = nullptr ) override;

  private:
    GLWindow window;
    void Cleanup() override;
};

}  // namespace Argo::System
