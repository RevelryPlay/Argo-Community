#pragma once

#include "../../Common/Constants.hpp"
#include "../../Common/Types/BaseWindow.hpp"
#include "../../Common/Types/CommonColor.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

namespace Argo::Graphics {

struct GL2DWindow : Types::BaseWindow {
    GL2DWindow();
    ~GL2DWindow() override;

    int init( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    void update( float deltaTime ) override;

    static void ProcessInput( GLFWwindow *window, int key, int scancode, int action, int mods );
    void HandleKey( int key, int scancode, int action, int mods ) override;

    void SetClearColor( const Types::CommonColor color );

    [[nodiscard]] GLFWwindow *GetPipelineWindow() const;

    int Cleanup() override;

  private:
    Types::CommonColor clearColor_{ 0.0F, 0.0F, 0.0F, 1.0F };
    GLFWwindow *window{ nullptr };

    static void resizeWindowCallback( GLFWwindow * /*window*/, int width, int height );
};

}  // namespace Argo::Graphics
