#include "GLShader.hpp"

namespace Argo::System {
const char *simpleVertexShader = R"(
 #version 410 core
 layout (location = 0) in vec4 aColor;
 layout (location = 1) in vec3 aPosition;
 out vec4 fColor;
 void main()
 {
     fColor = aColor;
     gl_Position = vec4(aPosition, 1.0);
 })";

const char *simpleFragmentShader = R"(
 #version 410 core
 out vec4 FragColor;
 in vec4 fColor;
 void main()
 {
     FragColor = fColor;
 })";

void GLShader::Compile() {
  int success;
  char infoLog[512];

  // Build Vertex Shader
  uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &simpleVertexShader, nullptr);
  glCompileShader(vertexShader);

  // Check for Shader Compile Errors
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
    fprintf(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n '%s'", infoLog);
  }

  // Build Fragment Shader
  uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &simpleFragmentShader, nullptr);
  glCompileShader(fragmentShader);

  // Check for Shader Compile Errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
    fprintf(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n '%s'", infoLog);
  }

  // Link Compiled Shaders
  ProgramId = glCreateProgram();
  glAttachShader(ProgramId, vertexShader);
  glAttachShader(ProgramId, fragmentShader);
  glLinkProgram(ProgramId);

  // Check for Linking Errors
  glGetProgramiv(ProgramId, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(ProgramId, 512, nullptr, infoLog);
    fprintf(stderr, "ERROR::SHADER::PROGRAM::LINKING_FAILED\n '%s'", infoLog);
  }

  // Delete the no Longer Needed Shader Data
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void GLShader::Bind() {
  glUseProgram(ProgramId);
}
}// namespace Argo::System