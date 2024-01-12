#include "GL2DWindow.hpp"

namespace Argo::Graphics {
GL2DWindow::GL2DWindow() = default;
GL2DWindow::~GL2DWindow() { GL2DWindow::Cleanup(); };

int GL2DWindow::init( const char *title, const int width, const int height ) {
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
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

void GL2DWindow::update( const float deltaTime ) {
    if ( glfwWindowShouldClose( window ) != 0 ) {
        isOpen = false;
        return;
    }

    const auto [ red, green, blue, alpha ]{ clearColor_ };
    glClearColor( red, green, blue, alpha );
    glClear( GL_COLOR_BUFFER_BIT );

    RunCallback( "windowUpdate", deltaTime );

    glfwSwapBuffers( window );
    glfwPollEvents();
}

void GL2DWindow::resizeWindowCallback( GLFWwindow * /*window*/, const int width, const int height ) {
    glViewport( 0, 0, width, height );
}

void GL2DWindow::ProcessInput( GLFWwindow *window,
    const int key,
    const int scancode,
    const int action,
    const int mods ) {

    if ( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ) {
        glfwSetWindowShouldClose( window, 1 );
    }

    // Retrieve the user pointer to the GL2DWindow instance
    auto *gl_window = static_cast< GL2DWindow * >( glfwGetWindowUserPointer( window ) );

    // Call the actual function using GL2DWindow instance
    gl_window->HandleKey( key, scancode, action, mods );
}

void GL2DWindow::HandleKey( const int key, const int /*scancode*/, const int action, const int /*mods*/ ) {
    if ( action == GLFW_PRESS ) {
        RunCallback( "keyPressed", key );
    } else if ( action == GLFW_RELEASE ) {
        RunCallback( "keyReleased", key );
    }
}

void GL2DWindow::SetClearColor( const Types::CommonColor color ) { clearColor_ = color; }

GLFWwindow *GL2DWindow::GetPipelineWindow() const { return window; }

int GL2DWindow::Cleanup() {
    if ( window != nullptr ) {
        glfwDestroyWindow( window );
    }

    glfwTerminate();

    return 0;
}
}  // namespace Argo::Graphics
