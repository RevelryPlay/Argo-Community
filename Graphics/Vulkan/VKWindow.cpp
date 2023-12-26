#include "VKWindow.hpp"

namespace Argo::Graphics {
VKWindow::VKWindow() = default;
VKWindow::~VKWindow() { VKWindow::Cleanup(); };
int VKWindow::init( const char *title, const int width, const int height ) {
    return BaseWindow::init( title, width, height );
}
void VKWindow::update( const float deltaTime ) { BaseWindow::update( deltaTime ); }
// void VKWindow::HandleKey( const int key, const int scancode, const int action, const int mods ) {
//     BaseWindow::HandleKey( key, scancode, action, mods );
// }
// void VKWindow::ProcessInput( auto *window, int key, int scancode, int action, int mods ) {}
void VKWindow::Cleanup() { BaseWindow::Cleanup(); }
}  // namespace Argo::Graphics
