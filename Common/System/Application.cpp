#include "Application.hpp"

namespace Argo::System {

Application::Application() = default;
Application::~Application() { Application::Cleanup(); }

bool Application::Setup() { return true; }
int Application::Run() { return 0; }

void Application::RegisterCallback( const std::string &title, const DeltaCallback &callback ) {
    if ( callbacks.contains( title ) ) {
        // add the callback to the sub list of callbacks
        callbacks[ title ].push_back( callback );
    } else {
        // create a new sub list of callbacks
        callbacks[ title ] = std::list< DeltaCallback >{ callback };
    }
}

int Application::RunCallback( const std::string &title, const float deltaTime ) {
    if ( !callbacks.contains( title ) ) {
        return -1;
    }

    // run all callbacks in the sub list of callbacks
    for ( auto &callback : callbacks[ title ] ) {
        callback( deltaTime );
    }

    return 0;
}

void Application::RemoveCallback( const std::string &title, const DeltaCallback &callback ) {
    // if ( !callbacks.contains( title ) ) {
    //     return;
    // }
    //
    // callbacks[ title ].remove( callback );
}

void Application::RemoveAllCallbacks() { callbacks.clear(); }

void Application::RemoveAllCallbacksWithTitle( const std::string &title ) { callbacks.erase( title ); }


int Application::Cleanup() { return 0; }


}  // namespace Argo::System
