#include "GLGame.hpp"
#include <gtest/gtest.h>

TEST( GLGame, Setup ) {
    auto *game = new Argo::Graphics::GLGame();
    EXPECT_TRUE( game->Setup( "Test Game", 800, 600 ) );

    EXPECT_EQ( game->GetWidth(), 800 );
    EXPECT_EQ( game->GetHeight(), 600 );
}

TEST( GLGame, SetWidth ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetWidth(), 800 );
    game->SetWidth( 1024 );
    EXPECT_EQ( game->GetWidth(), 1024 );
}

TEST( GLGame, SetHeight ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetHeight(), 600 );
    game->SetHeight( 768 );
    EXPECT_EQ( game->GetHeight(), 768 );
}
// This test depends on the OpenGL context being created which is not desirable in a test environment
// I will need to find a way to mock the OpenGL context
// TEST( GLGame, IsRunning ) {
//     auto *game = new Argo::Graphics::GLGame();
//     game->Setup( "Test Game", 800, 600 );
//     game->Run();
//
//     EXPECT_TRUE( game->GetIsRunning() );
//     game->Cleanup();
//     EXPECT_FALSE( game->GetIsRunning() );
// }

TEST( GLGame, GetActiveScene ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetActiveScene(), nullptr );
}

TEST( GLGame, CreateScene ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );
}

TEST( GLGame, GetScenes ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    const auto scenes = game->GetScenes();
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
}

TEST( GLGame, RemoveScene ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    auto scenes = game->GetScenes();
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );

    game->RemoveScene( scene );
    scenes = game->GetScenes();
    EXPECT_EQ( scenes.size(), 0 );
    EXPECT_EQ( game->GetActiveScene(), nullptr );
}

TEST( GLGame, SetActiveScene ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    const auto scenes = game->GetScenes();
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );

    auto *scene2 = game->CreateScene( 800, 600 );
    EXPECT_NE( scene2, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    game->SetActiveScene( scene2 );
    EXPECT_EQ( game->GetActiveScene(), scene2 );
}

// This test also needs to have a mocked OpenGL context
// TEST( GLGame, Run ) {
//     auto *game = new Argo::Graphics::GLGame();
//     game->Setup( "Test Game", 800, 600 );
//
//     auto *scene = game->CreateScene( 800, 600 );
//     EXPECT_NE( scene, nullptr );
//     EXPECT_EQ( game->GetActiveScene(), scene );
//
//     auto scenes = game->GetScenes();
//     EXPECT_EQ( scenes.size(), 1 );
//     EXPECT_EQ( scenes.front(), scene );
//
//     auto *scene2 = game->CreateScene( 800, 600 );
//     EXPECT_NE( scene2, nullptr );
//     EXPECT_EQ( game->GetActiveScene(), scene2 );
//
//     game->SetActiveScene( scene );
//     EXPECT_EQ( game->GetActiveScene(), scene );
//
//     game->Run();
//     EXPECT_FALSE( game->GetIsRunning() );
// }

TEST( GLGame, Cleanup ) {
    auto *game = new Argo::Graphics::GLGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    const auto scenes = game->GetScenes();
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );

    auto *scene2 = game->CreateScene( 800, 600 );
    EXPECT_NE( scene2, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    game->SetActiveScene( scene2 );
    EXPECT_EQ( game->GetActiveScene(), scene2 );

    game->Cleanup();
    EXPECT_EQ( game->GetActiveScene(), nullptr );
    EXPECT_EQ( game->GetScenes().size(), 0 );
    EXPECT_FALSE( game->GetIsRunning() );
}
