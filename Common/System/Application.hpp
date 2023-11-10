#pragma once

#include "Constants.hpp"

namespace Argo::System {

class Application {
  public:
    Application();
    virtual ~Application();

    virtual bool init();
    virtual void run();

    virtual void cleanup();
};

}  // namespace Argo::System
