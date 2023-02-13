#ifndef OPENGL_CPP_VERTEX_BUFFER_H_
#define OPENGL_CPP_VERTEX_BUFFER_H_

#include "base_vertex_buffer.h"

namespace openGL_cpp {

class vertex_buffer final: public base_vertex_buffer {
public:
  vertex_buffer() = delete;
  vertex_buffer(const void* const data, unsigned int size);
  ~vertex_buffer() = default;
};

}

#endif