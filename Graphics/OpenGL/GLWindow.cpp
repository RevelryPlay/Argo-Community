#include "GLWindow.hpp"

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

    // Window resize Callback
    glfwSetFramebufferSizeCallback( window, resizeWindowCallback );

    // Set the key callback
    glfwSetKeyCallback( window, ProcessInput );

    glfwSetWindowUserPointer( window, this );

    isOpen = true;
    return 0;
}

void GLWindow::update( const float deltaTime ) {
    if ( glfwWindowShouldClose( window ) != 0 ) {
        isOpen = false;
        return;
    }

    RunCallback( "windowUpdate", deltaTime );

    glfwSwapBuffers( window );
    glfwPollEvents();
}

void GLWindow::resizeWindowCallback( GLFWwindow * /*window*/, const int width, const int height ) {
    glViewport( 0, 0, width, height );
}

void GLWindow::ProcessInput( GLFWwindow *window, const int key, const int scancode, const int action, const int mods ) {

    if ( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ) {
        glfwSetWindowShouldClose( window, 1 );
    }

    // Retrieve the user pointer to the GLWindow instance
    auto *gl_window = static_cast< GLWindow * >( glfwGetWindowUserPointer( window ) );

    // Call the actual function using GLWindow instance
    gl_window->HandleKey( key, scancode, action, mods );
}

void GLWindow::HandleKey( const int key, const int /*scancode*/, const int action, const int /*mods*/ ) {
    if ( action == GLFW_PRESS ) {
        RunCallback( "keyPressed", key );
    } else if ( action == GLFW_RELEASE ) {
        RunCallback( "keyReleased", key );
    }
}

void GLWindow::cleanup() {
    if ( &window != nullptr ) {
        glfwDestroyWindow( window );
    }

    glfwTerminate();
}
}  // namespace Argo::Graphics
