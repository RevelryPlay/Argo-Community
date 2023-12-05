#pragma once

#include <functional>
#include <unordered_map>
#include <string>


#include "../Constants.hpp"

namespace Argo::System {

using CallbackFunction = std::function<void (float deltaTime)>;

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

    void RegisterCallback( const std::string title, const CallbackFunction &callback );
    int RunCallback(const std::string  title, float deltaTime);
    void RemoveCallback(const std::string title);

    virtual void Cleanup();

  private:
    std::unordered_map<std::string, CallbackFunction> callbacks;

};

}  // namespace Argo::System
