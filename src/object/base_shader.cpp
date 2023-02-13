#include "base_shader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <stdexcept>
#include <string>

namespace openGL_cpp {
  
void base_shader::compile(const std::string& code) const {
  const char* const source = code.c_str();
  glShaderSource(m_ID, 1, &source, nullptr);
  glCompileShader(m_ID);
  glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(m_ID, LOG_SIZE, nullptr, log);
    error("COMPILATION_FAILED");
    throw std::runtime_error("shader can't be compiled");
  }
}

}