#pragma once

#include "Game.hpp"
#include "Graphics/GLWindow.hpp"

namespace Argo::System {

using namespace Argo::Graphics;

class GLGame : Game {
  public:
    GLGame();
    ~GLGame();

    bool init( const char *title = Argo::Common::DEFAULT_WINDOW_TITLE,
        int width = Argo::Common::WINDOW_WIDTH,
        int height = Argo::Common::WINDOW_HEIGHT,
        const function< int() > &initCallback = nullptr );

    void run( const function< int( float ) > &runCallback = nullptr );

  private:
    GLWindow window;

    void cleanup();

    void handleEvents();

    static void update( float deltaTime, const function< int( float ) > &updateCallback = nullptr );

    static int UpdateCallback( float deltaTime );
};

}  // namespace Argo::System
