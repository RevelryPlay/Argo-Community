#include "Runner.hpp"
#include <iostream>

namespace Argo {

int Runner::run() {
    auto *scene = game.CreateScene( 12000, 500 );
    game.SetActiveScene( scene );

    scene->CreateCamera( 300, 200, 10, 20 );
    scene->SetActiveCamera( scene->GetCameras().front() );

    auto *entity = scene->CreateEntity();

    // Creating a sprite is currently done in a temporary way a more permanent solution would be:
    // auto *sprite = entity->CreateSprite();

    entity->sprite = &sprite;
    entity->height = 250;
    entity->width = 100;
    entity->xPos = 100;
    entity->yPos = 75;

    sprite.height = 512;
    sprite.width = 250;

    game.RegisterCallback( "setup", [ this ]( const float /*delta*/ ) { setup_callback(); } );
    game.RegisterCallback( "setup", [ this ]( const float /*delta*/ ) { setup_callback_2(); } );
    game.RegisterCallback( "run", [ this ]( const float /*delta*/ ) { run_callback(); } );
    game.RegisterCallback( "update", [ this ]( const float delta ) { update_callback( delta ); } );
    game.RegisterCallback( "windowUpdate", [ this ]( const float delta ) { delta_callback( delta ); } );
    game.RegisterCallback( "keyPressed", [ this ]( const float key ) { key_pressed_callback( key ); } );
    game.RegisterCallback( "keyReleased", [ this ]( const float key ) { key_released_callback( key ); } );
    game.RegisterCallback( "close", [ this ]( const float /*delta*/ ) { close_callback(); } );

    if ( !game.Setup( Common::DEFAULT_WINDOW_TITLE, Common::DEFAULT_WINDOW_WIDTH, Common::DEFAULT_WINDOW_HEIGHT ) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.Run();

    return 0;
};

void Runner::setup_callback(){
    fprintf( stdout, "setup Callback 1\n" );
};

void Runner::setup_callback_2(){
    fprintf( stdout, "setup Callback 2\n" );
};

void Runner::run_callback() {
#if OPTS_USE_OPENGL
    //     fprintf( stdout, "runCallback\n" );

    const char *vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    unsigned int vertexShader = 0;
    vertexShader = glCreateShader( GL_VERTEX_SHADER );

    glShaderSource( vertexShader, 1, &vertexShaderSource, nullptr );
    glCompileShader( vertexShader );

    int success = 0;
    char infoLog[ 512 ];
    glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &success );

    if ( success == 0 ) {
        glGetShaderInfoLog( vertexShader, 512, nullptr, infoLog );
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << '\n';
    }

    const char *fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(0.5f, 0.7f, 0.9f, 1.0f);\n"
        "} \0";

    unsigned int fragmentShader = 0;
    fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( fragmentShader, 1, &fragmentShaderSource, nullptr );
    glCompileShader( fragmentShader );

    unsigned int shaderProgram = 0;
    shaderProgram = glCreateProgram();

    glAttachShader( shaderProgram, vertexShader );
    glAttachShader( shaderProgram, fragmentShader );
    glLinkProgram( shaderProgram );

    glUseProgram( shaderProgram );

    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );
#endif
};

void Runner::update_callback( float deltaTime ){
    // cout << "delta:" << deltaTime << '\n';
    //     fprintf( stdout, "updateCallback\n" );
};

void Runner::delta_callback( float deltaTime ) {
#if OPTS_USE_OPENGL
    // cout << "delta:" << deltaTime << '\n';
    // fprintf( stdout, "deltaCallback\n" );
    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    std::vector< Types::Vertex > const vertices =
        sprite.calculateRecVertices( Common::DEFAULT_WINDOW_WIDTH, Common::DEFAULT_WINDOW_HEIGHT );

    unsigned int const indices[] = {
        // note that we start from 0!
        0, 1, 3,  // first triangle
        1, 2, 3  // second triangle
    };

    unsigned int VBO = 0;
    glGenBuffers( 1, &VBO );

    unsigned int VAO = 0;
    glGenVertexArrays( 1, &VAO );

    unsigned int EBO = 0;
    glGenBuffers( 1, &EBO );

    glBindVertexArray( VAO );
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof( Types::Vertex ) * vertices.size(), vertices.data(), GL_STATIC_DRAW );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), static_cast< void * >( nullptr ) );
    glEnableVertexAttribArray( 0 );

    glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
    glBindVertexArray( 0 );

    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
#endif
}

void Runner::key_pressed_callback( const float key ) { std::cout << "Runner - Key Pressed: " << key << "\n"; }

void Runner::key_released_callback( const float key ) { std::cout << "Runner - Key Released: " << key << "\n"; }

void Runner::close_callback() {
    //    fprintf(stdout, "Will Close");
}

}  // namespace Argo
