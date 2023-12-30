#include "GLScene.hpp"
#include <gtest/gtest.h>

TEST( GLScene, CreateCamera ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    EXPECT_NE( camera, nullptr );
}

TEST( GLScene, GetActiveCamera ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    EXPECT_EQ( scene->GetActiveCamera(), camera );
}

TEST( GLScene, GetCameras ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    const auto cameras = scene->GetCameras();
    EXPECT_EQ( cameras.size(), 1 );
    EXPECT_EQ( cameras.front(), camera );
}

TEST( GLScene, RemoveCamera ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    auto cameras = scene->GetCameras();
    EXPECT_EQ( cameras.size(), 1 );
    EXPECT_EQ( cameras.front(), camera );

    scene->RemoveCamera( camera );
    cameras = scene->GetCameras();
    EXPECT_EQ( cameras.size(), 0 );
}

TEST( GLScene, CreateEntity ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *entity = scene->CreateEntity();

    EXPECT_NE( entity, nullptr );
}

TEST( GLScene, GetEntities ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *entity = scene->CreateEntity();

    const auto entities = scene->GetEntities();
    EXPECT_EQ( entities.size(), 1 );
    EXPECT_EQ( entities.front(), entity );
}

TEST( GLScene, RemoveEntity ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *entity = scene->CreateEntity();

    auto entities = scene->GetEntities();
    EXPECT_EQ( entities.size(), 1 );
    EXPECT_EQ( entities.front(), entity );

    scene->RemoveEntity( entity );
    entities = scene->GetEntities();
    EXPECT_EQ( entities.size(), 0 );
}

TEST( GLScene, CreateLight ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *light = scene->CreateLight();

    EXPECT_NE( light, nullptr );
}

TEST( GLScene, GetLights ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *light = scene->CreateLight();

    const auto lights = scene->GetLights();
    EXPECT_EQ( lights.size(), 1 );
    EXPECT_EQ( lights.front(), light );
}

TEST( GLScene, RemoveLight ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *light = scene->CreateLight();

    auto lights = scene->GetLights();
    EXPECT_EQ( lights.size(), 1 );
    EXPECT_EQ( lights.front(), light );

    scene->RemoveLight( light );
    lights = scene->GetLights();
    EXPECT_EQ( lights.size(), 0 );
}

TEST( GLScene, Cleanup ) {
    auto *scene = new Argo::Graphics::GLScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );
    auto *entity = scene->CreateEntity();
    auto *light = scene->CreateLight();

    scene->Cleanup();

    EXPECT_EQ( scene->GetActiveCamera(), nullptr );
    EXPECT_EQ( scene->GetCameras().size(), 0 );
    EXPECT_EQ( scene->GetEntities().size(), 0 );
    EXPECT_EQ( scene->GetLights().size(), 0 );
}
