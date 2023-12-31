#include "GL2DScene.hpp"

namespace Argo::Graphics {
GL2DScene::GL2DScene( const int width, const int height ) {
    SetWidth( width );
    SetHeight( height );
};

GL2DScene::~GL2DScene() { Cleanup(); }

GL2DCamera *GL2DScene::CreateCamera( const int width, const int height, const int xPos, const int yPos ) {
    GL2DCamera *camera = new GL2DCamera( width, height, xPos, yPos );
    cameras_.push_back( camera );

    // Set the camera active if no other camera is already active
    if ( activeCamera_ == nullptr ) {
        activeCamera_ = camera;
    }

    return camera;
}

void GL2DScene::SetActiveCamera( GL2DCamera *camera ) { activeCamera_ = camera; }

GL2DCamera *GL2DScene::GetActiveCamera() const { return activeCamera_; }

std::list< GL2DCamera * > GL2DScene::GetCameras() { return cameras_; }

void GL2DScene::RemoveCamera( GL2DCamera *camera ) { cameras_.remove( camera ); }

GL2DEntity *GL2DScene::CreateEntity() {
    GL2DEntity *entity = new GL2DEntity();
    entities_.push_back( entity );
    return entity;
}

std::list< GL2DEntity * > GL2DScene::GetEntities() { return entities_; }

void GL2DScene::RemoveEntity( GL2DEntity *entity ) { entities_.remove( entity ); }

GL2DLight *GL2DScene::CreateLight() {
    auto *light = new GL2DLight();
    lights_.push_back( light );
    return light;
}

std::list< GL2DLight * > GL2DScene::GetLights() { return lights_; }

void GL2DScene::RemoveLight( GL2DLight *light ) { lights_.remove( light ); }

void GL2DScene::Cleanup() {
    activeCamera_ = nullptr;

    for ( const auto &camera : cameras_ ) {
        delete camera;
    }
    cameras_.clear();

    for ( const auto &entity : entities_ ) {
        delete entity;
    }
    entities_.clear();

    for ( const auto &light : lights_ ) {
        delete light;
    }
    lights_.clear();
}

}  // namespace Argo::Graphics
