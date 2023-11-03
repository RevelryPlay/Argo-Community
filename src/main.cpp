#include "System/GLGame.hpp"

#include <iostream>

using namespace Argo::System;

int initCallback() {
//    fprintf( stdout, "initCallback\n" );
    return 0;
}

int runCallback( float deltaTime ) {
    //    cout << "delta:" << deltaTime << '\n';
    //    fprintf( stdout, "runCallback\n" );
    return 0;
};

int main( int /*unused*/, char ** /*unused*/ ) {
    auto game = *new GLGame();

    if ( !game.init( Argo::Common::DEFAULT_WINDOW_TITLE,
             Argo::Common::WINDOW_WIDTH,
             Argo::Common::WINDOW_HEIGHT,
             initCallback ) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.run( runCallback );

    return 0;
}
