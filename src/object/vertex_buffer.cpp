#include "vertex_buffer.h"

namespace openGL_cpp {
  
vertex_buffer::vertex_buffer(const void* const data, unsigned int size) {
  glGenBuffers(1, &m_ID);
  glBindBuffer(GL_ARRAY_BUFFER, m_ID);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

}