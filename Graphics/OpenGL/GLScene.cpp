#include "GLScene.hpp"

namespace Argo::Graphics {
GLScene::GLScene( int _width, const int _height ) {
    width = _width;
    height = _height;
};

GLScene::~GLScene() { Cleanup(); }

GLCamera *GLScene::CreateCamera( const int width, const int height, const int xPos, const int yPos ) {
    GLCamera *camera = new GLCamera( width, height, xPos, yPos );
    cameras_.push_back( camera );
    return camera;
}

void GLScene::SetActiveCamera( GLCamera *camera ) { activeCamera_ = camera; }

GLCamera *GLScene::GetActiveCamera() const { return activeCamera_; }

std::list< GLCamera * > GLScene::GetCameras() { return cameras_; }

void GLScene::RemoveCamera( GLCamera *camera ) { cameras_.remove( camera ); }

GLEntity *GLScene::CreateEntity() {
    GLEntity *entity = new GLEntity();
    entities_.push_back( entity );
    return entity;
}

std::list< GLEntity * > GLScene::GetEntities() { return entities_; }

void GLScene::RemoveEntity( GLEntity *entity ) { entities_.remove( entity ); }

GLLight *GLScene::CreateLight() {
    GLLight *light = new GLLight();
    lights_.push_back( light );
    return light;
}

std::list< GLLight * > GLScene::GetLights() { return lights_; }

void GLScene::RemoveLight( GLLight *light ) { lights_.remove( light ); }

void GLScene::Cleanup() {
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
