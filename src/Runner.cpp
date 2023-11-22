#include "Runner.hpp"

namespace Argo {
int Runner::run() {
    camera.width = 300;
    camera.height = 200;
    camera.xPos = 10;
    camera.yPos = 20;

    scene.width = 12000;
    scene.height = 500;

    entity.height = 100;
    entity.width = 50;
    entity.xPos = 100;
    entity.yPos = 75;

    sprite.height = 100;
    sprite.width = 50;

    game.activeScene = &scene;
    scene.camera = &camera;
    entity.sprite = &sprite;
    scene.entities.push_back( &entity );

    if ( !game.Setup( Common::DEFAULT_WINDOW_TITLE,
             Common::DEFAULT_WINDOW_WIDTH,
             Common::DEFAULT_WINDOW_HEIGHT,
             setup_callback ) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.Run( run_callback, update_callback, delta_callback );

    return 0;
};

int Runner::setup_callback() {
    // fprintf( stdout, "initCallback\n" );
    return 0;
};

int Runner::run_callback() {
    // fprintf( stdout, "runCallback\n" );
    return 0;
};

int Runner::update_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
    // fprintf( stdout, "updateCallback\n" );
    return 0;
};

int Runner::delta_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
    // fprintf( stdout, "deltaCallback\n" );
    glClearColor( 0.3f, 0.3f, 0.5f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );
    return 0;
};

}  // namespace Argo
