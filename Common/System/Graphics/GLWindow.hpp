#pragma once

#include "constants.hpp"

#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

namespace Argo::System {

class GLWindow {
  public:
    GLWindow();
    virtual ~GLWindow();

    bool isOpen = false;

    int init( const char *title = "Window",
        int width = Argo::Common::WINDOW_WIDTH,
        int height = Argo::Common::WINDOW_HEIGHT );
    void update( float deltaTime, const function< int( float ) > &updateCallback );

    void cleanup();

  private:
    GLFWwindow *window{};

    static void resizeWindowCallback( GLFWwindow * /*window*/, int width, int height );

    void processInput();
};

}  // namespace Argo::System
