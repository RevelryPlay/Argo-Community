#include "GL2DScene.hpp"
#include <algorithm>

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

std::vector< GL2DCamera * > GL2DScene::GetCameras() { return cameras_; }

void GL2DScene::RemoveCamera( GL2DCamera *camera ) {
    const auto ind = std::ranges::find( cameras_, camera );

    if ( ind != cameras_.end() ) {
        cameras_.erase( ind );
    }
}

GL2DEntity *GL2DScene::CreateEntity() {
    auto *entity = new GL2DEntity();
    entities_.push_back( entity );
    return entity;
}

std::vector< GL2DEntity * > GL2DScene::GetEntities() { return entities_; }

void GL2DScene::RemoveEntity( const GL2DEntity *entity ) {
    const auto ind = std::ranges::find( entities_, entity );

    if ( ind != entities_.end() ) {
        entities_.erase( ind );
    }
}

GL2DLight *GL2DScene::CreateLight() {
    auto *light = new GL2DLight();
    lights_.push_back( light );
    return light;
}

std::vector< GL2DLight * > GL2DScene::GetLights() { return lights_; }

void GL2DScene::RemoveLight( GL2DLight *light ) {
    const auto ind = std::ranges::find( lights_, light );

    if ( ind != lights_.end() ) {
        lights_.erase( ind );
    }
}

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
