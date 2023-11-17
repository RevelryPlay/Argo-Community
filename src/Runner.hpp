#pragma once
#include "Graphics/OpenGL/GLCamera.hpp"
#include "Graphics/OpenGL/GLEntity.hpp"
#include "Graphics/OpenGL/GLScene.hpp"
#include "Graphics/OpenGL/GLSprite.hpp"
#include "System/Game.hpp"

namespace Argo {

class Runner {
  public:
    int run() {
        if ( !game.Setup( Common::DEFAULT_WINDOW_TITLE,
                 Common::DEFAULT_WINDOW_WIDTH,
                 Common::DEFAULT_WINDOW_HEIGHT,
                 setup_callback ) ) {
            fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
            return -1;
        }

        game.Run( run_callback, update_callback, delta_callback );

        return 0;
    }

  private:
    System::Game< System::GLGame > game = *new System::Game< System::GLGame >();
    Graphics::GLScene scene = *new Graphics::GLScene();
    Graphics::GLCamera camera = *new Graphics::GLCamera();

    Graphics::GLEntity entity = *new Graphics::GLEntity();
    Graphics::GLSprite sprite = *new Graphics::GLSprite();

    static int setup_callback() {
        // fprintf( stdout, "initCallback\n" );
        return 0;
    }

    static int run_callback() {
        // fprintf( stdout, "runCallback\n" );
        return 0;
    };

    static int update_callback( float deltaTime ) {
        // cout << "delta:" << deltaTime << '\n';
        // fprintf( stdout, "updateCallback\n" );
        return 0;
    };

    static int delta_callback( float deltaTime ) {
        // cout << "delta:" << deltaTime << '\n';
        // fprintf( stdout, "deltaCallback\n" );

        glClearColor( 0.3f, 0.3f, 0.5f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );
        return 0;
    };
};

}  // namespace Argo
