#ifndef OPENGL_CPP_SHADER_ERROR_H_
#define OPENGL_CPP_SHADER_ERROR_H_

#include "../system/type.h"

#include <string>
#include <iostream>

namespace openGL_cpp {

class shader_error {
public:
  virtual ~shader_error() = 0;

protected:
  static constexpr size_t LOG_SIZE = 1024;
  static char_t log[LOG_SIZE];
  static int_t success;

  virtual const std::string& profile_pre() const = 0;

  void error(const std::string& profile) const {
    std::cerr << profile_pre() << "::" << profile << "\n" << log << std::endl;
  }
};

inline shader_error::~shader_error() {}

}

#endif