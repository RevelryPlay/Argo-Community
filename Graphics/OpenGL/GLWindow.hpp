#pragma once

#include "../Common/Types/BaseWindow.hpp"
#include "../Common/Constants.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

namespace Argo::Graphics {

struct GLWindow : Types::BaseWindow {
    GLWindow();
    ~GLWindow() override;

    bool isOpen{ false };

    int init( const char *title = Argo::Common::DEFAULT_WINDOW_TITLE,
        int width = Argo::Common::DEFAULT_WINDOW_WIDTH,
        int height = Argo::Common::DEFAULT_WINDOW_HEIGHT );

    void update( float deltaTime );

    static void ProcessInput( GLFWwindow *window, int key, int scancode, int action, int mods );
    void HandleKey( int key, int scancode, int action, int mods );

    void cleanup();

  private:
    GLFWwindow *window{ nullptr };

    static void resizeWindowCallback( GLFWwindow * /*window*/, int width, int height );
};

}  // namespace Argo::Graphics
