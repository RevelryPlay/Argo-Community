#include "Runner.hpp"

namespace Argo {

int Runner::run() {
    camera.width = 300;
    camera.height = 200;
    camera.xPos = 10;
    camera.yPos = 20;

    scene.width = 12000;
    scene.height = 500;

    entity.height = 250;
    entity.width = 100;
    entity.xPos = 100;
    entity.yPos = 75;

    sprite.height = 512;
    sprite.width = 250;

    game.activeScene = &scene;
    scene.camera = &camera;
    entity.sprite = &sprite;
    scene.entities.push_back( &entity );

    game.RegisterCallback( "setup", [ this ]( float delta ) { Runner::setup_callback( delta ); } );
    game.RegisterCallback( "run", [ this ]( float delta ) { Runner::run_callback( delta ); } );
    game.RegisterCallback( "update", [ this ]( float delta ) { Runner::update_callback( delta ); } );
    game.RegisterCallback( "delta", [ this ]( float delta ) { Runner::delta_callback( delta ); } );
    game.RegisterCallback( "close", [ this ]( float delta ) { Runner::close_callback( delta ); } );

    if ( !game.Setup( Common::DEFAULT_WINDOW_TITLE, Common::DEFAULT_WINDOW_WIDTH, Common::DEFAULT_WINDOW_HEIGHT ) ) {
        fprintf( stderr, "Failed to initialize the game. See the logs about for more details." );
        return -1;
    }

    game.Run();

    return 0;
};

void Runner::setup_callback( float /*unused*/ ){
    //    fprintf( stdout, "initCallback\n" );
};

void Runner::run_callback( float /*unused*/ ) {
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
};

void Runner::update_callback( float deltaTime ){
    // cout << "delta:" << deltaTime << '\n';
    //     fprintf( stdout, "updateCallback\n" );
};

void Runner::delta_callback( float deltaTime ) {
    // cout << "delta:" << deltaTime << '\n';
    //     fprintf( stdout, "deltaCallback\n" );
    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    std::vector< Types::Vertex2D > const vertices =
        sprite.calculateRecVertices( Common::DEFAULT_WINDOW_WIDTH, Common::DEFAULT_WINDOW_HEIGHT );

    unsigned int const indices[] = {
        // note that we start from 0!
        0, 1, 3,  // first triangle
        1, 2, 3  // second triangle
    };

    unsigned int VBO;
    glGenBuffers( 1, &VBO );

    unsigned int VAO;
    glGenVertexArrays( 1, &VAO );

    unsigned int EBO;
    glGenBuffers( 1, &EBO );

    glBindVertexArray( VAO );
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof( Types::Vertex2D ) * vertices.size(), vertices.data(), GL_STATIC_DRAW );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), ( void * ) 0 );
    glEnableVertexAttribArray( 0 );

    glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );

    glBindVertexArray( 0 );

    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}

void Runner::close_callback( float /*unused*/ ) {
    //    fprintf(stdout, "Will Close");
}

}  // namespace Argo
