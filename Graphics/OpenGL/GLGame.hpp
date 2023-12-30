#pragma once

#include "../Common/System/Scene.hpp"
#include "../Common/System/Window.hpp"
#include "../Common/Types/BaseGame.hpp"
#include "GLScene.hpp"
#include "GLWindow.hpp"
#include <list>


namespace Argo::Graphics {

/**
 * \brief `GLGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
struct GLGame : Types::BaseGame {
    GLGame();
    ~GLGame() override;

    System::Window< GLWindow > *window{ nullptr };

    bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    void Run() override;

    // void AddScene( System::Scene< GLScene > *scene );
    GLScene *CreateScene( const int width, const int height );
    std::list< GLScene * > GetScenes();
    void RemoveScene( GLScene *scene );
    void SetActiveScene( GLScene *scene );
    [[nodiscard]] GLScene *GetActiveScene() const;

    void Cleanup() override;

  private:
    GLScene *activeScene_ = nullptr;
    std::list< GLScene * > scenes_{};
};

}  // namespace Argo::Graphics
