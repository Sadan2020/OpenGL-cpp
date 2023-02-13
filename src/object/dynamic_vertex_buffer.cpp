#include "dynamic_vertex_buffer.h"

namespace openGL_cpp {

dynamic_vertex_buffer::dynamic_vertex_buffer(uint_t count, size_t size_per_vertex):
  m_size_per_vertex(size_per_vertex)
{
  glGenBuffers(1, &m_ID);
  glBindBuffer(GL_ARRAY_BUFFER, m_ID);
  glBufferData(GL_ARRAY_BUFFER, count * size_per_vertex, nullptr, GL_DYNAMIC_DRAW);
}

void dynamic_vertex_buffer::push_back(const void* const data, uint_t count) noexcept {
  insert(m_offset, data, count);
  m_offset += count;
}

void dynamic_vertex_buffer::insert(uint_t offset, const void* const data, uint_t count) noexcept {
  bind();
  glBufferSubData(GL_ARRAY_BUFFER, offset * m_size_per_vertex, count * m_size_per_vertex, data);
}

}
