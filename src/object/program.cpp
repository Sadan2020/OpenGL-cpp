#include "program.h"

#include "vertex_shader.h"
#include "fragment_shader.h"

#include <stdexcept>

namespace openGL_cpp {

program::program(const vertex_shader& vs, const fragment_shader& fs) {
  m_ID = glCreateProgram();
  glAttachShader(m_ID, vs.ID());
  glAttachShader(m_ID, fs.ID());
  link();
}

void program::link() const {
  glLinkProgram(m_ID);
  glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(m_ID, LOG_SIZE, nullptr, log);
    error("LINKING_FAILED");
    throw std::runtime_error("program can't be linked");
  }
}

}