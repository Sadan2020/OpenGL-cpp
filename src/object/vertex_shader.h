#ifndef OPENGL_CPP_VERTEX_SHADER_H_
#define OPENGL_CPP_VERTEX_SHADER_H_

#include "base_shader.h"

#include <string>

namespace openGL_cpp {

class vertex_shader final: public base_shader {
public:
  vertex_shader() = delete;
  explicit vertex_shader(const std::string& path);

private:
  const std::string& profile_pre() const override {
    static std::string s = "ERROR::SHADER::VERTEX";
    return s;
  }
};

}

#endif