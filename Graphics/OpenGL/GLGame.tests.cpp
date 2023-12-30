#include "GLGame.hpp"
#include <gtest/gtest.h>

using namespace Argo::Graphics;

// Basic test to ensure that the GLGame class can be instantiated
Test( GLGame, Setup ) {
    GLGame game;
    EXPECT_TRUE( game.Setup( "Test Window", 800, 600 ) );
}

// Not a useful test, but is a placeholder for now
Test( GLGame, Run ) {
    GLGame game;
    EXPECT_TRUE( game.Setup( "Test Window", 800, 600 ) );
    game.Run();
}

Test( GLGame, CreateScene ) {
    GLGame game;
    EXPECT_TRUE( game.Setup() );
    auto *scene{ game.CreateScene( 800, 600 ) };
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( scene->GetWidth(), 800 );
    EXPECT_EQ( scene->GetHeight(), 600 );
}

Test( GLGame, GetScenes ) {
    GLGame game;
    EXPECT_TRUE( game.Setup() );
    auto *scene{ game.CreateScene( 800, 600 ) };
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( scene->GetWidth(), 800 );
    EXPECT_EQ( scene->GetHeight(), 600 );
    auto scenes{ game.GetScenes() };
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
}

Test( GLGame, RemoveScene ) {
    GLGame game;
    EXPECT_TRUE( game.Setup() );
    auto *scene{ game.CreateScene( 800, 600 ) };
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( scene->GetWidth(), 800 );
    EXPECT_EQ( scene->GetHeight(), 600 );
    auto scenes{ game.GetScenes() };
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
    game.RemoveScene( scene );
    scenes = game.GetScenes();
    EXPECT_EQ( scenes.size(), 0 );
}

Test( GLGame, SetActiveScene ) {
    GLGame game;
    EXPECT_TRUE( game.Setup() );
    auto *scene{ game.CreateScene( 800, 600 ) };
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( scene->GetWidth(), 800 );
    EXPECT_EQ( scene->GetHeight(), 600 );
    auto scenes{ game.GetScenes() };
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
    game.SetActiveScene( scene );
    EXPECT_EQ( game.GetActiveScene(), scene );
}

Test( GLGame, GetActiveScene ) {
    GLGame game;
    EXPECT_TRUE( game.Setup() );
    auto *scene{ game.CreateScene( 800, 600 ) };
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( scene->GetWidth(), 800 );
    EXPECT_EQ( scene->GetHeight(), 600 );
    auto scenes{ game.GetScenes() };
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
    game.SetActiveScene( scene );
    EXPECT_EQ( game.GetActiveScene(), scene );
}

Test( GLGame, Cleanup ) {
    GLGame game;
    EXPECT_TRUE( game.Setup() );
    auto *scene{ game.CreateScene( 800, 600 ) };
    EXPECT_NE( scene, nullptr );
    EXPECT_EQ( scene->GetWidth(), 800 );
    EXPECT_EQ( scene->GetHeight(), 600 );
    auto scenes{ game.GetScenes() };
    EXPECT_EQ( scenes.size(), 1 );
    EXPECT_EQ( scenes.front(), scene );
    game.SetActiveScene( scene );
    EXPECT_EQ( game.GetActiveScene(), scene );
    game.Cleanup();
    EXPECT_EQ( game.GetActiveScene(), nullptr );
    scenes = game.GetScenes();
    EXPECT_EQ( scenes.size(), 0 );
}
