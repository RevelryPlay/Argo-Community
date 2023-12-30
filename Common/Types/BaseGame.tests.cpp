#include "BaseGame.hpp"
#include <gtest/gtest.h>

TEST( BaseGame, BaseGameSetup ) {
    Argo::Types::BaseGame *game = new Argo::Types::BaseGame();
    EXPECT_TRUE( game->Setup( "Test Game", 800, 600 ) );

    EXPECT_EQ( game->GetWidth(), 800 );
    EXPECT_EQ( game->GetHeight(), 600 );
}

TEST( BaseGame, BaseGameSetWidth ) {
    Argo::Types::BaseGame *game = new Argo::Types::BaseGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetWidth(), 800 );
    game->SetWidth( 1024 );
    EXPECT_EQ( game->GetWidth(), 1024 );
}

TEST( BaseGame, BaseGameSetHeight ) {
    Argo::Types::BaseGame *game = new Argo::Types::BaseGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_EQ( game->GetHeight(), 600 );
    game->SetHeight( 768 );
    EXPECT_EQ( game->GetHeight(), 768 );
}

TEST( BaseGame, BaseGameIsRunning ) {
    Argo::Types::BaseGame *game = new Argo::Types::BaseGame();
    game->Setup( "Test Game", 800, 600 );

    EXPECT_TRUE( game->GetIsRunning() );
    game->Cleanup();
    EXPECT_FALSE( game->GetIsRunning() );
}
