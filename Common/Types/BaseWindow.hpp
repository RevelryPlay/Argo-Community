#pragma once
#include "../System/Application.hpp"

namespace Argo::Types {
struct BaseWindow : System::Application {
    BaseWindow();
    ~BaseWindow() override;

    bool isOpen{ false };

    virtual int init( const char *title = Common::DEFAULT_WINDOW_TITLE,
        int width = Common::DEFAULT_WINDOW_WIDTH,
        int height = Common::DEFAULT_WINDOW_HEIGHT );

    virtual void update( float deltaTime );

    virtual void HandleKey( int key, int scancode, int action, int mods );

    int Cleanup() override;
};
}  // namespace Argo::Types
