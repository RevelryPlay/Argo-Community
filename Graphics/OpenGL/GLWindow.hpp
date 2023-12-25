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

    int init( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    void update( float deltaTime ) override;

    static void ProcessInput( GLFWwindow *window, int key, int scancode, int action, int mods );
    void HandleKey( int key, int scancode, int action, int mods ) override;

    void Cleanup() override;

  private:
    GLFWwindow *window{ nullptr };

    static void resizeWindowCallback( GLFWwindow * /*window*/, int width, int height );
};

}  // namespace Argo::Graphics
