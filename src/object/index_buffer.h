#ifndef OPENGL_INDEX_BUFFER_H_
#define OPENGL_INDEX_BUFFER_H_

#include "base_object.h"

namespace openGL_cpp {

class index_buffer final: public base_object {
public:
  index_buffer() = delete; 
  index_buffer(const uint_t* const data, uint_t count);

  ~index_buffer() noexcept override { glDeleteBuffers(1, &m_ID); }

  void bind() const noexcept { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID); }
  void unbind() const noexcept { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

  auto count() const noexcept { return m_count; }

private:
  uint_t m_count;
};

}

#endif