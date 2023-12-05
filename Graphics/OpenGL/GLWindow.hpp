#pragma once

#include "../../Common/System/BaseWindow.hpp"
#include "../Common/Constants.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

namespace Argo::Graphics {

class GLWindow : public System::BaseWindow{
  public:
    GLWindow();
    virtual ~GLWindow();

    bool isOpen = false;

    int init( const char *title = Argo::Common::DEFAULT_WINDOW_TITLE,
        int width = Argo::Common::DEFAULT_WINDOW_WIDTH,
        int height = Argo::Common::DEFAULT_WINDOW_HEIGHT );

    void update( float deltaTime );
    void processInput( void ( *inputCallback )( GLFWwindow *window, unsigned int key ) );

    static void cleanup();

  private:
    GLFWwindow *window{};

    static void resizeWindowCallback( GLFWwindow * /*window*/, int width, int height );
};

}  // namespace Argo::Graphics