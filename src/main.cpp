#include "System/Game.hpp"
#include "System/GLGame.hpp"

#include <iostream>

using namespace Argo::System;

int setup_callback() {
//    fprintf( stdout, "initCallback\n" );
    return 0;
}

int run_callback( float deltaTime ) {
    //    cout << "delta:" << deltaTime << '\n';
    //    fprintf( stdout, "runCallback\n" );
    return 0;
};

int main( int /*unused*/, char ** /*unused*/ ) {
    Game<GLGame> game = *new Game<GLGame>();

    if ( !game.Setup( Argo::Common::DEFAULT_WINDOW_TITLE,
             Argo::Common::DEFAULT_WINDOW_WIDTH,
             Argo::Common::DEFAULT_WINDOW_HEIGHT,
             setup_callback ) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.Run( run_callback );

    return 0;
}
