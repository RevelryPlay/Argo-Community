#include "Runner.hpp"

namespace Argo {

//Runner::Runner() {
//    // Setup Game
//    game = *new System::Game< System::GLGame >();
//    game.
//
//    // Register Callbacks
//};


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

    game.RegisterCallback("setup", [this](float delta) {
        Runner::setup_callback(delta);
    });

    game.RegisterCallback("run", [this](float delta) {
        Runner::run_callback(delta);
    });

    game.RegisterCallback("update", [this](float delta) {
        Runner::update_callback(delta);
    });

    game.RegisterCallback("delta", [this](float delta) {
        Runner::delta_callback(delta);
    });

    game.RegisterCallback("close", [this](float delta) {
        Runner::close_callback(delta);
    });

    if ( !game.Setup( Common::DEFAULT_WINDOW_TITLE,
             Common::DEFAULT_WINDOW_WIDTH,
             Common::DEFAULT_WINDOW_HEIGHT) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.Run();

    return 0;
};

void Runner::setup_callback(float /*unused*/) {
//    fprintf( stdout, "initCallback\n" );
};

void Runner::run_callback(float /*unused*/) {
//     fprintf( stdout, "runCallback\n" );
};

void Runner::update_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
//     fprintf( stdout, "updateCallback\n" );
};

void Runner::delta_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
//     fprintf( stdout, "deltaCallback\n" );
    glClearColor( 0.3f, 0.3f, 0.5f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );
}

void Runner::close_callback(float /*unused*/) {
//    fprintf(stdout, "Will Close");
}

}  // namespace Argo
