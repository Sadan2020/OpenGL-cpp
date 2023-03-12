#include "window.h"

#include <stdexcept>

namespace openGL_cpp {

window::window(int width, int height, const std::string& title) {
  m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if(m_window == nullptr) {
    throw std::runtime_error("Failed to create openGL window.");
  }
}

window::~window() {
  glfwDestroyWindow(m_window);
}

}