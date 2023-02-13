#ifndef OPENGL_CPP_VERTEX_BUFFER_LAYOUT_H_
#define OPENGL_CPP_VERTEX_BUFFER_LAYOUT_H_

#include "../system/type.h"

#include <vector>

namespace openGL_cpp {

class vertex_buffer_layout final {
public:
  vertex_buffer_layout() = default;
  ~vertex_buffer_layout() = default;

  struct vertex_buffer_element {
    type_id type;
    uint_t count;
    bool_t normalized;
  };

  template<typename T>
  void push(uint_t count) {
    m_elements.push_back({
      get_type_id<T>(), count, false // TO DO
    });
    m_stride += sizeof(T) * count;
  }

  auto get_stride() const noexcept { return m_stride; }
  const auto& get_elements() const noexcept { return m_elements; }

private:
  std::vector<vertex_buffer_element> m_elements;
  uint_t m_stride = 0;
};

}

#endif