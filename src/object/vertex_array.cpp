#include "vertex_array.h"

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "index_buffer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace openGL_cpp {

void vertex_array::add_buffer(const base_vertex_buffer& buffer, const vertex_buffer_layout& layout) {
  bind();

  buffer.bind();
  const auto& elements = layout.get_elements();
  for(uint_t i = 0, offset = 0; const auto& element : elements) {
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i++, element.count, static_cast<enum_t>(element.type), 
                          element.normalized, layout.get_stride(), reinterpret_cast<const void*>(offset));
    offset += element.count * get_size_of_type(element.type);
  }

  unbind();
}

void vertex_array::add_buffer(const index_buffer& buffer) {
  bind();

  buffer.bind();
  m_count = buffer.count();

  unbind();
}

}