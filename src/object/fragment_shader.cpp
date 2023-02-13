#include "fragment_shader.h"

#include "../kit/kit.h"

namespace openGL_cpp {

fragment_shader::fragment_shader(const std::string& path) {
  m_ID = glCreateShader(GL_FRAGMENT_SHADER);
  std::string code = kit::read_file(path);
  compile(code);
}

}