#pragma once
#include "../Common/Types/BaseScene.hpp"
#include "GLCamera.hpp"
#include "GLEntity.hpp"
#include "GLLight.hpp"

namespace Argo::Graphics {

/**
 * \brief `GLScene` is a type of scene that adds OpenGL specific behaviors
 */
struct GLScene : Types::BaseScene {
    GLScene( int width, int height );
    ~GLScene();

    GLCamera *CreateCamera( const int width, const int height, const int xPos, const int yPos );
    void SetActiveCamera( GLCamera *camera );
    [[nodiscard]] GLCamera *GetActiveCamera() const;
    std::list< GLCamera * > GetCameras();
    void RemoveCamera( GLCamera *camera );

    GLEntity *CreateEntity();
    std::list< GLEntity * > GetEntities();
    void RemoveEntity( GLEntity *entity );

    GLLight *CreateLight();
    std::list< GLLight * > GetLights();
    void RemoveLight( GLLight *light );

    void Cleanup();

  private:
    GLCamera *activeCamera_ = nullptr;

    std::list< GLCamera * > cameras_{};
    std::list< GLEntity * > entities_{};
    std::list< GLLight * > lights_{};
};

}  // namespace Argo::Graphics
