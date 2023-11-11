#pragma once

#include "Constants.hpp"

namespace Argo::System {

/**
 * \brief An Application provides a minimal structure for running a program.
 * Consistenting of a `Setup` -> `Run` -> `Cleanup` cycle
 */
class Application {
  public:
    Application();
    virtual ~Application();

    virtual bool Setup();
    virtual void Run();

    virtual void Cleanup();
};

}  // namespace Argo::System
