#pragma once
#include "../../Common/Types/BaseScene.hpp"
#include "GL2DCamera.hpp"
#include "GL2DEntity.hpp"
#include "GL2DLight.hpp"

#include <vector>

namespace Argo::Graphics {

/**
 * \brief `GL2DScene` is a type of scene that adds OpenGL specific behaviors
 */
struct GL2DScene : Types::BaseScene {
    GL2DScene( int width, int height );
    ~GL2DScene();

    GL2DCamera *CreateCamera( const int width, const int height, const int xPos, const int yPos );
    void SetActiveCamera( GL2DCamera *camera );
    [[nodiscard]] GL2DCamera *GetActiveCamera() const;
    std::vector< GL2DCamera * > GetCameras();
    void RemoveCamera( GL2DCamera *camera );

    GL2DEntity *CreateEntity();
    std::vector< GL2DEntity * > GetEntities();
    void RemoveEntity( const GL2DEntity *entity );

    GL2DLight *CreateLight();
    std::vector< GL2DLight * > GetLights();
    void RemoveLight( GL2DLight *light );

    void Cleanup();

  private:
    GL2DCamera *activeCamera_ = nullptr;

    std::vector< GL2DCamera * > cameras_{};
    std::vector< GL2DEntity * > entities_{};
    std::vector< GL2DLight * > lights_{};
};

}  // namespace Argo::Graphics
