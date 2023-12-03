#pragma once

#include "BaseGame.hpp"
#include "Graphics/OpenGL/GLWindow.hpp"

namespace Argo::Graphics {
class GLScene;
}
namespace Argo::System {

using namespace Argo::Graphics;

/**
 * \brief `GLGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
class GLGame : public BaseGame {
  public:
    GLGame();
    ~GLGame() override;

    GLScene *activeScene;

    bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT );

    void Run();

  private:
    GLWindow *window{};
    void Cleanup() override;
};

}  // namespace Argo::System
