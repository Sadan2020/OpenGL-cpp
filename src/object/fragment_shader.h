#ifndef OPENGL_CPP_FRAGMENT_SHADER_H_
#define OPENGL_CPP_FRAGMENT_SHADER_H_

#include "base_shader.h"

#include <string>

namespace openGL_cpp {

class fragment_shader final: public base_shader {
public:
  fragment_shader() = delete;
  explicit fragment_shader(const std::string& path);

private:
  const std::string& profile_pre() const override {
    static std::string s = "ERROR::SHADER::FRAGMENT";
    return s;
  }
};

}

#endif