#ifndef OPENGL_CPP_WINDOW_H_
#define OPENGL_CPP_WINDOW_H_

#include "../kit/kit.h"
#include "../system/enum.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <string>

namespace openGL_cpp {

class window final {
public:
  window() = delete;
  window(int width, int height, const std::string& title);

  ~window() = default;

  window(const window&) = delete;
  window& operator=(const window&) = delete;

  window(window&& rhs) noexcept { kit::move_to(rhs.m_window, m_window, nullptr); }
  window& operator=(window&& rhs) noexcept {
    kit::move_to(rhs.m_window, m_window, nullptr);
    return *this;
  }

  GLFWwindow* gl_window() const noexcept { return m_window; }

  void use() const noexcept { glfwMakeContextCurrent(m_window); }
  void swap_buffer() const noexcept { glfwSwapBuffers(m_window); }

  void set_should_close(bool value) noexcept { glfwSetWindowShouldClose(m_window, value); }
  bool should_close() const noexcept { return glfwWindowShouldClose(m_window); }

  bool press_key(key_id key) const noexcept {
    return glfwGetKey(m_window, static_cast<int>(key)) == GLFW_PRESS;
  }

  using fcn_framebuffer_size_callback = void(*)(GLFWwindow*, int, int);
  fcn_framebuffer_size_callback set_framebuffer_size_callback(fcn_framebuffer_size_callback fcn) noexcept {
    return glfwSetFramebufferSizeCallback(m_window, fcn);
  }

  using fcn_cursor_pos_callback = void(*)(GLFWwindow*, double, double);
  fcn_cursor_pos_callback set_cursor_pos_callback(fcn_cursor_pos_callback fcn) noexcept {
    return glfwSetCursorPosCallback(m_window, fcn);
  }

  using fcn_scroll_callback = void(*)(GLFWwindow*, double, double);
  fcn_scroll_callback set_scroll_callback(fcn_scroll_callback fcn) noexcept {
    return glfwSetScrollCallback(m_window, fcn);
  }

  static void poll_events() noexcept { glfwPollEvents(); }

  static void default_framebuffer_size_callback(GLFWwindow*, int width, int height) noexcept {
    glViewport(0, 0, width, height);
  }

  static void set_swap_interval(int interval) noexcept { glfwSwapInterval(interval); }

private:
  GLFWwindow* m_window;
};

}


#endif