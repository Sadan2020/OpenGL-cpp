#include "index_buffer.h"

#include "../system/type.h"

#include <type_traits>

namespace openGL_cpp {

index_buffer::index_buffer(const uint_t* const data, uint_t count):
  m_count(count) 
{ 
  glGenBuffers(1, &m_ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint_t) * count, data, GL_STATIC_DRAW);
}

}