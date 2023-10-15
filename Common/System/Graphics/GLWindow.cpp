#include "GLWindow.hpp"

namespace Argo::System {
  GLWindow::GLWindow() = default;

  GLWindow::~GLWindow() { cleanup(); };

  int GLWindow::init(const char *title, int width, int height)
  {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) {
      std::cout << "Failed to create GLFW window" << '\n';
      glfwTerminate();
      return -1;
    }
    glfwMakeContextCurrent(window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cout << "Failed to initialize GLAD" << '\n';
      return -1;
    }

    glViewport(0, 0, width, height);

    // Window resize Callback
    glfwSetFramebufferSizeCallback(window, resizeWindowCallback);

    isOpen = true;

    return 0;
  }

  void GLWindow::update(float deltaTime, const function<int(float)> &updateCallback) {
    while (!glfwWindowShouldClose(window)) {
      processInput();

      // Render something here
      updateCallback(deltaTime);

      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    isOpen = false;
  }

  void GLWindow::resizeWindowCallback(GLFWwindow * /*window*/, int width, int height) {
    glViewport(0, 0, width, height);
  }

  void GLWindow::processInput()
  {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, true);
    }
  }

  void GLWindow::cleanup() {
    glfwTerminate();
  }
  }// namespace Argo::System