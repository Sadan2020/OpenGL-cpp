#ifndef OPENGL_CPP_BASE_OBJECT_H_
#define OPENGL_CPP_BASE_OBJECT_H_

#include "../kit/kit.h"
#include "../system/type.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <string>

namespace openGL_cpp {

class base_object {
public:
  base_object() = default;

  base_object(const base_object&) = delete;
  base_object& operator=(const base_object&) = delete;

  base_object(base_object&& rhs) noexcept { kit::move_to(rhs.m_ID, m_ID, 0);  }
  base_object& operator=(base_object&& rhs) noexcept {
    kit::move_to(rhs.m_ID, m_ID, 0u);
    return *this;
  }

  virtual ~base_object() noexcept = 0;

  auto ID() const noexcept {  return m_ID;  }

protected:
  uint_t m_ID = 0;
};

inline base_object::~base_object() {}

}

#endif