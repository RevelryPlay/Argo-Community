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
        const function< int() > &setup_callback = nullptr );

    void Run( const function< int( float ) > &run_callback = nullptr );

    GLWindow window;

    void Cleanup() override;

    static void Update( float deltaTime, const function< int( float ) > &updateCallback = nullptr );

    static int UpdateCallback( float deltaTime );
};

}  // namespace Argo::System
