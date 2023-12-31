#pragma once

#include "../../Common/Types/BaseGame.hpp"
#include "GL2DScene.hpp"
#include "GL2DWindow.hpp"
#include <list>


namespace Argo::Graphics {

/**
 * \brief `GL2DGame` expands on `BaseGame` to handle the creation and lifecycle of an OpenGL window
 */
struct GL2DGame : Types::BaseGame {
    GL2DGame();
    ~GL2DGame() override;

    System::Window< GL2DWindow > *window{ nullptr };

    bool Setup( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    int Run() override;

    // void AddScene( System::Scene< GL2DScene > *scene );
    GL2DScene *CreateScene( const int width, const int height );
    std::list< GL2DScene * > GetScenes();
    void RemoveScene( GL2DScene *scene );
    void SetActiveScene( GL2DScene *scene );
    [[nodiscard]] GL2DScene *GetActiveScene() const;

    int Cleanup() override;

  private:
    GL2DScene *activeScene_ = nullptr;
    std::list< GL2DScene * > scenes_{};
};

}  // namespace Argo::Graphics
