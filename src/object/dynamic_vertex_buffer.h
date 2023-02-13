#ifndef OPENGL_CPP_DYNAMIC_VERTEX_BUFFER_H_
#define OPENGL_CPP_DYNAMIC_VERTEX_BUFFER_H_

#include "base_vertex_buffer.h"

namespace openGL_cpp {

class dynamic_vertex_buffer final: public base_vertex_buffer {
public:
  dynamic_vertex_buffer() = delete;
  dynamic_vertex_buffer(uint_t count, size_t size_per_vertex);

  ~dynamic_vertex_buffer() = default;

  void clear_offset() noexcept { m_offset = 0; }
  void push_back(const void* const data, uint_t count) noexcept;
  void insert(uint_t offset, const void* const data, uint_t count) noexcept;

private:
  const size_t m_size_per_vertex;
  uint_t m_offset = 0;
};

}

#endif