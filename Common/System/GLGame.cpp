#include "GLGame.hpp"
#include "Graphics/GLShader.hpp"

#include <chrono>
#include <iostream>

namespace Argo::System {
static GLShader shader;

struct Vertex {
  std::array<float, 4> color;
  std::array<float, 3> position;
};

static std::array<Vertex, 6> colorSquares = {
  //      Color                         Position
  Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-1.0f, -1.0f, 0.0f}},
  Vertex{{0.1f,  0.9f, 0.12f, 1.0f},   {-1.0f,  1.0f, 0.0f}},
  Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 1.0f,  1.0f, 0.0f}},

  Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-1.0f, -1.0f, 0.0f}},
  Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 1.0f,  1.0f, 0.0f}},
  Vertex{{0.12f, 0.1f, 0.9f,  1.0f},   { 1.0f, -1.0f, 0.0f}}
};

static uint32_t colorSquaresVAO;
static uint32_t colorSquaresVBO;

void setupColorSquaresTest()
{
//  glCreateVertexArrays(1, &colorSquaresVAO);
  glGenVertexArrays(1, &colorSquaresVAO);
  glBindVertexArray(colorSquaresVAO);

  glGenBuffers(1, &colorSquaresVBO);
  glBindBuffer(GL_ARRAY_BUFFER, colorSquaresVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colorSquares), colorSquares.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
  glEnableVertexAttribArray(1);
}

void drawColorSquaresTest()
{
  glBindVertexArray(colorSquaresVAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void destroyColorSquaresTest()
{
  glDeleteBuffers(1, &colorSquaresVBO);
  glDeleteVertexArrays(1, &colorSquaresVAO);
}

GLGame::GLGame() = default;

GLGame::~GLGame() { cleanup(); };

bool GLGame::init()
{
  window = *new Argo::System::GLWindow();
  window.init("Hello World", 1024, 768);

  shader.Compile();
  shader.Bind();
  setupColorSquaresTest();

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

void GLGame::update() {
  window.update(deltaTime, GLGame::updateCallback);
}

int GLGame::updateCallback(float deltaTime)
{
  //  cout << "delta:" << deltaTime << '\n';
  glClearColor(0.3f, 0.5f, 0.7f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  drawColorSquaresTest();

  return 0;
}

void GLGame::cleanup()
{
  // NOTE: Destroy instances in reverse order of creation
  destroyColorSquaresTest();
  window.cleanup();
}

}// namespace Argo::System
