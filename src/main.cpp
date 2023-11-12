#include "System/Game.hpp"

#include <iostream>

using namespace Argo::System;

float prev_red = (rand() % 100) * 0.01;
float prev_green = (rand() % 100) * 0.01;
float prev_blue = (rand() % 100) * 0.01;


int setup_callback() {
    // fprintf( stdout, "initCallback\n" );
    return 0;
}

int run_callback( ) {
    // fprintf( stdout, "runCallback\n" );
    return 0;
};

int update_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
    // fprintf( stdout, "updateCallback\n" );
    return 0;
};

int delta_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
    // fprintf( stdout, "deltaCallback\n" );

    float red = prev_red + 0.001;
    if (red > 1.0) {
        red = 0.0;
    }
    prev_red = red;

    float green = prev_green + 0.001;
    if (green > 1.0) {
        green = 0.0;
    }
    prev_green = green;

    float blue = prev_blue + 0.001;
    if (blue > 1.0) {
        blue = 0.0;
    }
    prev_blue = blue;

    glClearColor(red, green, blue, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );
    return 0;
};

int main( int /*unused*/, char ** /*unused*/ ) {
    auto game = *new Game<GLGame>();

    if ( !game.Setup( Argo::Common::DEFAULT_WINDOW_TITLE,
             Argo::Common::DEFAULT_WINDOW_WIDTH,
             Argo::Common::DEFAULT_WINDOW_HEIGHT,
             setup_callback ) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.Run( run_callback, update_callback, delta_callback );

    return 0;
}
