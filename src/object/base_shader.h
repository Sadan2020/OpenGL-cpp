#ifndef OPENGL_CPP_BASE_SHADER_H_
#define OPENGL_CPP_BASE_SHADER_H_

#include "base_object.h"
#include "shader_error.h"

#include <string>

namespace openGL_cpp {

class base_shader: public base_object, private shader_error {
public:
  base_shader() = default;

  virtual const std::string& profile_pre() const override = 0;

   ~base_shader() noexcept override { glDeleteShader(m_ID); }

protected:
  void compile(const std::string& code) const;
};

}

#endif