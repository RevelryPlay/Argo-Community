#include "GL2DScene.hpp"
#include <gtest/gtest.h>

TEST( GL2DScene, CreateCamera ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    EXPECT_NE( camera, nullptr );
}

TEST( GL2DScene, GetActiveCamera ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    EXPECT_EQ( scene->GetActiveCamera(), camera );
}

TEST( GL2DScene, GetCameras ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    const auto cameras = scene->GetCameras();
    EXPECT_EQ( cameras.size(), 1 );
    EXPECT_EQ( cameras.front(), camera );
}

TEST( GL2DScene, RemoveCamera ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );

    auto cameras = scene->GetCameras();
    EXPECT_EQ( cameras.size(), 1 );
    EXPECT_EQ( cameras.front(), camera );

    scene->RemoveCamera( camera );
    cameras = scene->GetCameras();
    EXPECT_EQ( cameras.size(), 0 );
}

TEST( GL2DScene, CreateEntity ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *entity = scene->CreateEntity();

    EXPECT_NE( entity, nullptr );
}

TEST( GL2DScene, GetEntities ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *entity = scene->CreateEntity();

    const auto entities = scene->GetEntities();
    EXPECT_EQ( entities.size(), 1 );
    EXPECT_EQ( entities.front(), entity );
}

TEST( GL2DScene, RemoveEntity ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *entity = scene->CreateEntity();

    auto entities = scene->GetEntities();
    EXPECT_EQ( entities.size(), 1 );
    EXPECT_EQ( entities.front(), entity );

    scene->RemoveEntity( entity );
    entities = scene->GetEntities();
    EXPECT_EQ( entities.size(), 0 );
}

TEST( GL2DScene, CreateLight ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *light = scene->CreateLight();

    EXPECT_NE( light, nullptr );
}

TEST( GL2DScene, GetLights ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *light = scene->CreateLight();

    const auto lights = scene->GetLights();
    EXPECT_EQ( lights.size(), 1 );
    EXPECT_EQ( lights.front(), light );
}

TEST( GL2DScene, RemoveLight ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *light = scene->CreateLight();

    auto lights = scene->GetLights();
    EXPECT_EQ( lights.size(), 1 );
    EXPECT_EQ( lights.front(), light );

    scene->RemoveLight( light );
    lights = scene->GetLights();
    EXPECT_EQ( lights.size(), 0 );
}

TEST( GL2DScene, Cleanup ) {
    auto *scene = new Argo::Graphics::GL2DScene( 800, 600 );
    auto *camera = scene->CreateCamera( 800, 600, 0, 0 );
    auto *entity = scene->CreateEntity();
    auto *light = scene->CreateLight();

    scene->Cleanup();

    EXPECT_EQ( scene->GetActiveCamera(), nullptr );
    EXPECT_EQ( scene->GetCameras().size(), 0 );
    EXPECT_EQ( scene->GetEntities().size(), 0 );
    EXPECT_EQ( scene->GetLights().size(), 0 );
}
