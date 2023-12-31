#include "GL2DGame.hpp"
#include <gtest/gtest.h>

TEST( GL2DGame, Setup ) {
    auto *game = new Argo::Graphics::GL2DGame();
    EXPECT_TRUE( game->Setup( "Test Game", 800, 600 ) );

    EXPECT_EQ( game->GetWidth(), 800 );
    EXPECT_EQ( game->GetHeight(), 600 );
}

TEST( GL2DGame, SetWidth ) {
    auto *game = new Argo::Graphics::GL2DGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetWidth(), 800 );
    game->SetWidth( 1024 );
    EXPECT_EQ( game->GetWidth(), 1024 );
}

TEST( GL2DGame, SetHeight ) {
    auto *game = new Argo::Graphics::GL2DGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetHeight(), 600 );
    game->SetHeight( 768 );
    EXPECT_EQ( game->GetHeight(), 768 );
}
// This test depends on the OpenGL context being created which is not desirable in a test environment
// I will need to find a way to mock the OpenGL context
// TEST( GL2DGame, IsRunning ) {
//     auto *game = new Argo::Graphics::GL2DGame();
//     game->Setup( "Test Game", 800, 600 );
//     game->Run();
//
//     EXPECT_TRUE( game->GetIsRunning() );
//     game->Cleanup();
//     EXPECT_FALSE( game->GetIsRunning() );
// }

TEST( GL2DGame, GetActiveScene ) {
    auto *game = new Argo::Graphics::GL2DGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetActiveScene(), nullptr );
}

TEST( GL2DGame, CreateScene ) {
    auto *game = new Argo::Graphics::GL2DGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );
}

TEST( GL2DGame, GetScenes ) {
    auto *game = new Argo::Graphics::GL2DGame();
    game->Setup( "Test Game", 800, 600 );

    auto *scene = game->CreateScene( 800, 600 );
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( game->GetActiveScene(), scene );

    const auto scenes = game->GetScenes();
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
}

TEST( GL2DGame, RemoveScene ) {
    auto *game = new Argo::Graphics::GL2DGame();
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

TEST( GL2DGame, SetActiveScene ) {
    auto *game = new Argo::Graphics::GL2DGame();
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
// TEST( GL2DGame, Run ) {
//     auto *game = new Argo::Graphics::GL2DGame();
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

TEST( GL2DGame, Cleanup ) {
    auto *game = new Argo::Graphics::GL2DGame();
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
