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
    void run() override;

  private:
    GLWindow window;

    void cleanup();

    void handleEvents();

    void update();

    static int updateCallback( float deltaTime );
};

}  // namespace Argo::System
