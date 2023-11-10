#pragma once

#include "Game.hpp"
#include "Graphics/GLWindow.hpp"

namespace Argo::System {

using namespace Argo::Graphics;

class GLGame : Game {
  public:
    GLGame();
    ~GLGame() override;

    bool init( const char *title = Argo::Common::DEFAULT_WINDOW_TITLE,
        int width = Argo::Common::DEFAULT_WINDOW_WIDTH,
        int height = Argo::Common::DEFAULT_WINDOW_HEIGHT,
        const function< int() > &initCallback = nullptr );

    void run( const function< int( float ) > &runCallback = nullptr );

    GLWindow window;

    void cleanup() override;

    void handleEvents() override;

    static void update( float deltaTime, const function< int( float ) > &updateCallback = nullptr );

    static int UpdateCallback( float deltaTime );
};

}  // namespace Argo::System
