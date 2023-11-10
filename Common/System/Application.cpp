#include "Application.hpp"

namespace Argo::System {

Application::Application() = default;
Application::~Application() { Application::cleanup(); }

bool Application::init() { return true; }
void Application::run() {}


void Application::cleanup() {}

}  // namespace Argo::System
