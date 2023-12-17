#pragma once

#include "Window.hpp"

#include <functional>
#include <string>
#include <unordered_map>

#include "../Constants.hpp"

namespace Argo::System {

using BaseCallback = std::function< void() >;
using DeltaCallback = std::function< void( float deltaTime ) >;
using KeyPressCallback = std::function< void( unsigned int key ) >;
// using WindowResizeCallback = std::function<void (Window<Graphics::GLWindow>, float width, float height)>;

template< typename T > class Callback : public T {};

/**
 * \brief An Application provides a minimal structure for running a program.
 * Consisting of a `Setup` -> `Run` -> `Cleanup` cycle
 */
class Application {
  public:
    Application();
    virtual ~Application();

    virtual bool Setup();
    virtual void Run();

    void RegisterCallback( const std::string &title, const DeltaCallback &callback );
    int RunCallback( const std::string &title, float deltaTime );
    void RemoveCallback( const std::string &title );

    virtual void Cleanup();

    // Normally I would not make this public. I am doing so as a shortcut to be able to set windows to use the same
    // callbacks as Application
    std::unordered_map< std::string, DeltaCallback > callbacks;
};

}  // namespace Argo::System
