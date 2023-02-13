#ifndef OPENGL_CPP_BASE_VERTEX_BUFFER_H_
#define OPENGL_CPP_BASE_VERTEX_BUFFER_H_

#include "base_object.h"

namespace openGL_cpp {

class base_vertex_buffer: public base_object {
public:
  base_vertex_buffer() = default;

  ~base_vertex_buffer() noexcept override = 0;

  void bind() const noexcept { glBindBuffer(GL_ARRAY_BUFFER, m_ID); }
  void unbind() const noexcept { glBindBuffer(GL_ARRAY_BUFFER, 0); }
};

inline base_vertex_buffer::~base_vertex_buffer() noexcept {
  glDeleteBuffers(1, &m_ID);
}

}

#endif