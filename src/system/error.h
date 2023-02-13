#ifndef OPENGL_CPP_ERROR_H_
#define OPENGL_CPP_ERROR_H_

#include "glad/glad.h"

#include <stdexcept>

namespace openGL_cpp {

enum class error_id {
  no_error = GL_NO_ERROR,
  invalid_enum = GL_INVALID_ENUM,
  invalid_value = GL_INVALID_VALUE,
  invalid_operation = GL_INVALID_OPERATION,
  out_of_memory = GL_OUT_OF_MEMORY,
};
  
inline void clear_error() noexcept {
  while(glGetError() != GL_NO_ERROR) continue;
}

// TO DO
inline void get_error() { 
  switch(auto error = static_cast<error_id>(glGetError()); error) {
    case error_id::invalid_enum:       throw std::runtime_error("invalid enum"); break;
    case error_id::invalid_value:      throw std::runtime_error("invalid value"); break;
    case error_id::invalid_operation:  throw std::runtime_error("invalid operation"); break;
    case error_id::out_of_memory:      throw std::runtime_error("out_of_memory"); break;
    case error_id::no_error:           break;
  }
}

}

#endif