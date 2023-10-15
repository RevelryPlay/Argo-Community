#include "GLGame.hpp"
#include <chrono>
#include <iostream>

namespace Argo::System {
GLGame::GLGame() = default;

GLGame::~GLGame() { cleanup(); };

bool GLGame::init()
{
  window = *new Argo::System::GLWindow();
  window.init("Hello World", 1024, 768);

  return true;
}

void GLGame::run()
{
  // TODO: Investigate if this is reliable for games
  auto previousTime = std::chrono::high_resolution_clock::now();

  while (window.isOpen) {
    // Handle Event Loop
    auto currentTime = std::chrono::high_resolution_clock::now();
    GLGame::deltaTime = std::chrono::duration<float, std::milli>(currentTime - previousTime).count();

    // Game loop events
    handleEvents();
    update();

    previousTime = currentTime;
  }
}

void GLGame::handleEvents() {}

void GLGame::update() { window.update(deltaTime, GLGame::updateCallback); }

int GLGame::updateCallback(float deltaTime)
{
  //  cout << "delta:" << deltaTime << '\n';
  glClearColor(0.3f, 0.5f, 0.7f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  return 0;
}

void GLGame::cleanup()
{
  // NOTE: Destroy instances in reverse order of creation
  window.cleanup();
}

}// namespace Argo::System
