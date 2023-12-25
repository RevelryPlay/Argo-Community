#include "BaseWindow.hpp"

namespace Argo::Types {
BaseWindow::BaseWindow() = default;
BaseWindow::~BaseWindow() = default;

int BaseWindow::init( const char * /*title*/, int /*width*/, int /*height*/ ) {
    isOpen = true;
    return 0;
}

void BaseWindow::update( float /*deltaTime*/ ) {}
void BaseWindow::HandleKey( int /*key*/, int /*scancode*/, int /*action*/, int /*mods*/ ) {}
void BaseWindow::Cleanup() { Application::Cleanup(); }

}  // namespace Argo::Types
