#pragma once

#include "../Common/Types/BaseWindow.hpp"

namespace Argo::Graphics {
struct VKWindow : Types::BaseWindow {
    VKWindow();
    ~VKWindow() override;

    int init( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT ) override;

    void update( float deltaTime ) override;

    // static void ProcessInput( auto *window, int key, int scancode, int action, int mods );
    // void HandleKey( int key, int scancode, int action, int mods ) override;

    void Cleanup() override;

  private:
    // auto *window{ nullptr };
    // static void resizeWindowCallback( auto * /*window*/, int width, int height );
};

}  // namespace Argo::Graphics
