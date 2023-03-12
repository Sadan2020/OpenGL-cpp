#include "window.h"

#include <stdexcept>
#include <algorithm>

namespace openGL_cpp {

window::window(int width, int height, const std::string& title) {
  m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  window_index[m_window] = this;
  if(m_window == nullptr) {
    throw std::runtime_error("Failed to create openGL window.");
  }
}

window::~window() {
  window_index.erase(m_window);
  glfwDestroyWindow(m_window);
}

std::unordered_map<GLFWwindow*, window*> window::window_index;

/* Callback Functions */

window::callback_index_type window::callback_index = 0;

  /* Key Callback */

void window::key_callback(GLFWwindow* win, int key, int scancode, int action, int mods) {
  auto window = window_index.find(win);
  if(window != window_index.end()) {
    for(const auto& k : window->second->m_key_callback_functions) {
      k.second(*window->second, static_cast<key_token>(key), scancode, static_cast<key_action>(action), mods);
    }
  }
}

auto window::register_key_callback(func_key_callback func) -> callback_index_type {
  if(m_key_callback_functions.empty()) {
    glfwSetKeyCallback(m_window, key_callback);
  }
  auto index = callback_index++;
  m_key_callback_functions.emplace_front(index, func);
  return index;
}

bool window::unregister_key_callback(callback_index_type index) {
  auto iter = std::find_if(m_key_callback_functions.cbegin(), m_key_callback_functions.cend(), 
    [index](const std::pair<callback_index_type, func_key_callback>& member)  {
      return member.first == index;
    });
  bool ret = (iter == m_key_callback_functions.cend());
  m_key_callback_functions.erase(iter);
  if(m_key_callback_functions.empty()) {
    glfwSetKeyCallback(m_window, nullptr);
  }
  return ret;
}

  /* Mouse Callback */

void window::mouse_button_callback(GLFWwindow* win, int button, int action, int mods) {
  auto window = window_index.find(win);
  if(window != window_index.end()) {
    for(const auto& k : window->second->m_mouse_button_callback_functions) {
      k.second(*window->second, static_cast<mouse_button_token>(button), 
               static_cast<mouse_button_action>(action), mods);
    }
  }
}

auto window::register_mouse_button_callback(func_mouse_button_callback func) -> callback_index_type {
  if(m_mouse_button_callback_functions.empty()) {
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);
  }
  auto index = callback_index++;
  m_mouse_button_callback_functions.emplace_front(index, func);
  return index;
}

bool window::unregister_mouse_button_callback(callback_index_type index) {
  auto iter = std::find_if(m_mouse_button_callback_functions.cbegin(), m_mouse_button_callback_functions.cend(), 
    [index](const std::pair<callback_index_type, func_mouse_button_callback>& member)  {
      return member.first == index;
    });
  bool ret = (iter == m_mouse_button_callback_functions.cend());
  m_mouse_button_callback_functions.erase(iter);
  if(m_mouse_button_callback_functions.empty()) {
    glfwSetMouseButtonCallback(m_window, nullptr);
  }
  return ret;
}

  /* Framebuffer Size */

void window::framebuffer_size_callback(GLFWwindow* win, int width, int height) {
  auto window = window_index.find(win);
  if(window != window_index.end()) {
    for(const auto& k : window->second->m_framebuffer_size_callback_functions) {
      k.second(*window->second, width, height);
    }
  }
}

auto window::register_framebuffer_size_callback(func_framebuffer_size_callback func) -> callback_index_type {
  if(m_framebuffer_size_callback_functions.empty()) {
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
  }
  auto index = callback_index++;
  m_framebuffer_size_callback_functions.emplace_front(index, func);
  return index;
}

bool window::unregister_framebuffer_size_callback(callback_index_type index) {
  auto iter = std::find_if(m_framebuffer_size_callback_functions.cbegin(), m_framebuffer_size_callback_functions.cend(), 
    [index](const std::pair<callback_index_type, func_framebuffer_size_callback>& member)  {
      return member.first == index;
    });
  bool ret = (iter == m_framebuffer_size_callback_functions.cend());
  m_framebuffer_size_callback_functions.erase(iter);
  if(m_framebuffer_size_callback_functions.empty()) {
    glfwSetMouseButtonCallback(m_window, nullptr);
  }
  return ret;
}

}