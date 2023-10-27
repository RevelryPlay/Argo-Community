#pragma once

#include <glad/glad.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/integer.hpp>

#include <iostream>

namespace Argo::Graphics {
class GLShader {
  public:
    uint32_t ProgramId;

    void Compile();
    void Bind();
};
};  // namespace Argo::Graphics
