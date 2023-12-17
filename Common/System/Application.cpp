#include "Application.hpp"

namespace Argo::System {

Application::Application() = default;
Application::~Application() { Application::Cleanup(); }

bool Application::Setup() { return true; }
void Application::Run() {}

void Application::RegisterCallback( const std::string &title, const DeltaCallback &callback ) {
    callbacks[title] = callback;
}

int Application::RunCallback( const std::string &title, const float deltaTime ) {
    if (!callbacks.contains(title) ) {
        return -1;
    }

    callbacks[title](deltaTime);
    return 0;
}

void Application::RemoveCallback( const std::string &title ) {
    const auto iterator = callbacks.find(title);

    if (iterator == callbacks.end()) {
        return;
    }

    callbacks.erase(iterator);
}


void Application::Cleanup() {}


}  // namespace Argo::System
