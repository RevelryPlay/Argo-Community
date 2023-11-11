#include "Application.hpp"

namespace Argo::System {

Application::Application() = default;
Application::~Application() { Application::Cleanup(); }

bool Application::Setup() { return true; }
void Application::Run() {}


void Application::Cleanup() {}

}  // namespace Argo::System
