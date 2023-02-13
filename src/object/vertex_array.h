#ifndef OPENGL_CPP_VERTEX_ARRAY_H_
#define OPENGL_CPP_VERTEX_ARRAY_H_

#include "base_object.h"

namespace openGL_cpp {

class base_vertex_buffer;
class vertex_buffer_layout;
class index_buffer;

class vertex_array final: public base_object {
public:
  vertex_array() { glGenVertexArrays(1, &m_ID); }
  ~vertex_array() noexcept override {  glDeleteVertexArrays(1, &m_ID); }

  void add_buffer(const base_vertex_buffer& buffer, const vertex_buffer_layout& layout);
  void add_buffer(const index_buffer& buffer);

  void bind() const noexcept { glBindVertexArray(m_ID); }
  static void unbind() noexcept { glBindVertexArray(0); }

  auto count() const noexcept { return m_count; }

private:
  uint_t m_count = 0;
};

}

#endif