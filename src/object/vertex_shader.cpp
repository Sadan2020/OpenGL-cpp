#include "vertex_shader.h"

#include "../kit/kit.h"

namespace openGL_cpp {

vertex_shader::vertex_shader(const std::string& path) {
  m_ID = glCreateShader(GL_VERTEX_SHADER);
  std::string code = kit::read_file(path);
  compile(code);
}

}