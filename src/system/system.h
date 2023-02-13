#ifndef OPENGL_CPP_SYSTEM_H_
#define OPENGL_CPP_SYSTEM_H_

#include "type.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace openGL_cpp {

void init_glfw(float version) noexcept;

void load_glad();

inline double time() noexcept {  return glfwGetTime(); }

inline void terminate() noexcept { glfwTerminate();  }

inline void set_clear_color(clampf_t red, clampf_t green, clampf_t blue, clampf_t alpha) noexcept { 
  glClearColor(red, green, blue, alpha);
}

inline void enable_texture_alpha() noexcept {
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

}
#endif