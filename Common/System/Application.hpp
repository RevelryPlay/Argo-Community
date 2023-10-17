#pragma once
namespace Argo::System {

class Application {
  public:
    Application();
    virtual ~Application();

    virtual bool init();
    virtual void run();

  private:
    void cleanup();
};

}  // namespace Argo::System
