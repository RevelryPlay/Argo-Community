#pragma once
namespace Argo::System {

struct Program
{
  Program();
  ~Program();

  virtual bool init();
  virtual void run();

private:
  void cleanup();
};

}// namespace Argo::System
