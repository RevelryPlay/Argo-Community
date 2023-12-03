#include "GLWindow.hpp"

void inputCallback( GLFWwindow * /* window */, const unsigned int key ) { cout << "Key Pressed: " << key << "\n"; }

namespace Argo::Graphics {
GLWindow::GLWindow() = default;
GLWindow::~GLWindow() { cleanup(); };

int GLWindow::init( const char *title, const int width, const int height ) {
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );

    window = glfwCreateWindow( width, height, title, nullptr, nullptr );
    if ( window == nullptr ) {
        std::cout << "Failed to create GLFW window" << '\n';
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent( window );

    if ( gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress ) == 0 ) {
        std::cout << "Failed to initialize GLAD" << '\n';
        return -1;
    }

    glViewport( 0, 0, width, height );

    // Window resize Callback
    glfwSetFramebufferSizeCallback( window, resizeWindowCallback );

    isOpen = true;
    return 0;
}

void GLWindow::update( const float deltaTime) {
    if ( glfwWindowShouldClose( window ) != 0 ) {
        isOpen = false;
        return;
    }

    processInput( inputCallback );

//    RunCallback("update", deltaTime);

    glfwSwapBuffers( window );
    glfwPollEvents();
}

void GLWindow::resizeWindowCallback( GLFWwindow * /*window*/, const int width, const int height ) {
    glViewport( 0, 0, width, height );
}

void GLWindow::processInput( void ( *inputCallback )( GLFWwindow *window, unsigned int key ) ) {
    if ( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ) {
        glfwSetWindowShouldClose( window, 1 );
    }

    if ( inputCallback != nullptr ) {
        glfwSetCharCallback( window, inputCallback );
    }
}

void GLWindow::cleanup() { glfwTerminate(); }
}  // namespace Argo::Graphics
