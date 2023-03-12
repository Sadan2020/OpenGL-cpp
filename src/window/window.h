#ifndef OPENGL_CPP_WINDOW_H_
#define OPENGL_CPP_WINDOW_H_

#include "../kit/kit.h"
#include "../system/enum.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <string>
#include <functional>
#include <list>
#include <unordered_map>

namespace openGL_cpp {

class window final {
public:
  window() = delete;
  window(int width, int height, const std::string& title);

  ~window();

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

  bool press_key(key_token key) const noexcept {
    return glfwGetKey(m_window, static_cast<int>(key)) == GLFW_PRESS;
  }

  bool release_key(key_token key) const noexcept {
    return glfwGetKey(m_window, static_cast<int>(key)) == GLFW_RELEASE;
  }

  bool press_mouse_button(mouse_button_token mouse_button) const noexcept {
    return glfwGetMouseButton(m_window, static_cast<int>(mouse_button)) == GLFW_PRESS;
  }

  bool release_mouse_button(mouse_button_token mouse_button) const noexcept {
    return glfwGetMouseButton(m_window, static_cast<int>(mouse_button)) == GLFW_RELEASE;
  }

  auto get_cursor_pos() const noexcept {
    double x, y;
    glfwGetCursorPos(m_window, &x, &y);
    return std::make_pair(x, y);
  }

  void set_cursor_pos(double x, double y) noexcept {
    glfwSetCursorPos(m_window, x, y);
  }

  auto get_size() const noexcept {
    int width, height;
    glfwGetWindowSize(m_window, &width, &height);
    return std::make_pair(width, height);
  }

  static auto get_time() noexcept { return glfwGetTime(); }
  static auto get_timer_frequency() noexcept { return glfwGetTimerFrequency(); }
  static auto get_timer_value() noexcept { return glfwGetTimerValue(); }

  /*
   * Callback Functions
   */

  using callback_index_type = unsigned int;

  using func_window_close_callback          = std::function<void (window&)>;
  using func_window_size_callback           = std::function<void (window&, int width, int height)>;
  using func_framebuffer_size_callback      = std::function<void (window&, int width, int height)>;
  using func_window_content_scale_callback  = std::function<void (window&, float xscale, float yscale)>;
  using func_window_pos_callback            = std::function<void (window&, int xpos, int ypos)>;
  using func_window_iconify_callback        = std::function<void (window&, bool iconified)>;
  using func_window_maximize_callback       = std::function<void (window&, bool maximized)>;
  using func_window_focus_callback          = std::function<void (window&, bool focused)>;
  using func_window_refresh_callback        = std::function<void (window&)>;
  using func_monitor_callback               = std::function<void (window&, int event)>;
  using func_key_callback                   = std::function<void (window&, key_token, int scancode, key_action, int mods)>;
  using func_character_callback             = std::function<void (window&, unsigned int codepoint)>;
  using func_cursor_pos_callback            = std::function<void (window&, double xpos, double ypos)>;
  using func_cursor_enter_callback          = std::function<void (window&, bool entered)>;
  using func_mouse_button_callback          = std::function<void (window&, mouse_button_token, mouse_button_action, int mods)>;
  using func_scroll_callback                = std::function<void (window&, double xoffset, double yoffset)>;
  using func_joystick_callback              = std::function<void (window&, int jid, int event)>;
  using func_drop_callback                  = std::function<void (window&, int count, const char** paths)>;

  callback_index_type register_window_close_callback(func_window_close_callback func);
  callback_index_type register_window_size_callback(func_window_size_callback func);

  /**
   * @brief 向 window 中注册帧缓冲大小函数，可注册多个
   *
   * @param func 回调函数，类型为 void (window&, int width, int height)
   * @return callback_index_type 一个索引，指向注册的回调函数
   */
  callback_index_type register_framebuffer_size_callback(func_framebuffer_size_callback func);

  callback_index_type register_window_content_scale_callback(func_window_content_scale_callback func);
  callback_index_type register_window_pos_callback(func_window_pos_callback func);
  callback_index_type register_window_iconify_callback(func_window_iconify_callback func);
  callback_index_type register_window_maximize_callback(func_window_maximize_callback func);
  callback_index_type register_window_focus_callback(func_window_focus_callback func);
  callback_index_type register_window_refresh_callback(func_window_refresh_callback func);
  callback_index_type register_monitor_callback(func_monitor_callback func);

  /**
   * @brief 向 window 中注册键盘回调函数，可注册多个
   *
   * @param func 回调函数，类型为 void (window&, key_token, int scancode, key_action, int mods)
   * @return callback_index_type 一个索引，指向注册的回调函数
   */
  callback_index_type register_key_callback(func_key_callback func);

  callback_index_type register_character_callback(func_character_callback func);
  callback_index_type register_cursor_pos_callback(func_cursor_pos_callback func);
  callback_index_type register_cursor_enter_callback(func_cursor_enter_callback func);

  /**
   * @brief 向 window 中注册鼠标回调函数，可注册多个
   *
   * @param func 回调函数，类型为 void (window&, mouse_button_token, mouse_button_action, int mods)
   * @return callback_index_type 一个索引，指向注册的回调函数
   */
  callback_index_type register_mouse_button_callback(func_mouse_button_callback func);

  callback_index_type register_scroll_callback(func_scroll_callback func);
  callback_index_type register_joystick_callback(func_joystick_callback func);
  callback_index_type register_drop_callback(func_drop_callback func);

  bool unregister_window_close_callback(callback_index_type index);
  bool unregister_window_size_callback(callback_index_type index);

  /**
   * @brief 注销已注册帧缓冲大小的函数
   *
   * @param index 一个索引，指向要注销的函数
   * @return 一个 bool值，表示目标函数是否存在
   */
  bool unregister_framebuffer_size_callback(callback_index_type index);

  bool unregister_window_content_scale_callback(callback_index_type index);
  bool unregister_window_pos_callback(callback_index_type index);
  bool unregister_window_iconify_callback(callback_index_type index);
  bool unregister_window_maximize_callback(callback_index_type index);
  bool unregister_window_focus_callback(callback_index_type index);
  bool unregister_window_refresh_callback(callback_index_type index);
  bool unregister_monitor_callback(callback_index_type index);

  /**
   * @brief 注销已注册的键盘回调函数
   *
   * @param index 一个索引，指向要注销的函数
   * @return 一个 bool值，表示目标函数是否存在
   */
  bool unregister_key_callback(callback_index_type index);

  bool unregister_character_callback(callback_index_type index);
  bool unregister_cursor_pos_callback(callback_index_type index);
  bool unregister_cursor_enter_callback(callback_index_type index);

  /**
   * @brief 注销已注册的鼠标回调函数
   *
   * @param index 一个索引，指向要注销的函数
   * @return 一个 bool值，表示目标函数是否存在
   */
  bool unregister_mouse_button_callback(callback_index_type index);

  bool unregister_scroll_callback(callback_index_type index);
  bool unregister_joystick_callback(callback_index_type index);
  bool unregister_drop_callback(callback_index_type index);

  static void poll_events() noexcept { glfwPollEvents(); }

  static void default_framebuffer_size_callback(GLFWwindow*, int width, int height) noexcept {
    glViewport(0, 0, width, height);
  }

  static void set_swap_interval(int interval) noexcept { glfwSwapInterval(interval); }

private:
  static std::unordered_map<GLFWwindow*, window*> window_index;

  GLFWwindow* m_window;

  static callback_index_type callback_index;

  std::list<std::pair<callback_index_type, func_window_close_callback        >> m_window_close_callback_functions    ;
  std::list<std::pair<callback_index_type, func_window_size_callback         >> m_window_size_callback_functions     ;
  std::list<std::pair<callback_index_type, func_framebuffer_size_callback    >> m_framebuffer_size_callback_functions;
  std::list<std::pair<callback_index_type, func_window_content_scale_callback>> m_window_content_scale_callback      ;
  std::list<std::pair<callback_index_type, func_window_pos_callback          >> m_window_pos_callback_functions      ;
  std::list<std::pair<callback_index_type, func_window_iconify_callback      >> m_window_iconify_callback_functions  ;
  std::list<std::pair<callback_index_type, func_window_maximize_callback     >> m_window_maximize_callback_functions ;
  std::list<std::pair<callback_index_type, func_window_focus_callback        >> m_window_focus_callback_functions    ;
  std::list<std::pair<callback_index_type, func_window_refresh_callback      >> m_window_refresh_callback_functions  ;
  std::list<std::pair<callback_index_type, func_monitor_callback             >> m_monitor_callback_functions         ;
  std::list<std::pair<callback_index_type, func_key_callback                 >> m_key_callback_functions             ;
  std::list<std::pair<callback_index_type, func_character_callback           >> m_character_callback_functions       ;
  std::list<std::pair<callback_index_type, func_cursor_pos_callback          >> m_cursor_pos_callback_functions      ;
  std::list<std::pair<callback_index_type, func_cursor_enter_callback        >> m_cursor_enter_callback_functions    ;
  std::list<std::pair<callback_index_type, func_mouse_button_callback        >> m_mouse_button_callback_functions    ;
  std::list<std::pair<callback_index_type, func_scroll_callback              >> m_scroll_callback_functions          ;
  std::list<std::pair<callback_index_type, func_joystick_callback            >> m_joystick_callback_functions        ;
  std::list<std::pair<callback_index_type, func_drop_callback                >> m_drop_callback_functions            ;

  static void window_close_callback        (GLFWwindow*);
  static void window_size_callback         (GLFWwindow*, int width, int height);
  static void framebuffer_size_callback    (GLFWwindow*, int width, int height);
  static void window_content_scale_callback(GLFWwindow*, float xscale, float yscale);
  static void window_pos_callback          (GLFWwindow*, int xpos, int ypos);
  static void window_iconify_callback      (GLFWwindow*, int iconified);
  static void window_maximize_callback     (GLFWwindow*, int maximized);
  static void window_focus_callback        (GLFWwindow*, int focused);
  static void window_refresh_callback      (GLFWwindow*);
  static void monitor_callback             (GLFWwindow*, int event);
  static void key_callback                 (GLFWwindow*, int key, int scancode, int action, int mods);
  static void character_callback           (GLFWwindow*, unsigned int codepoint);
  static void cursor_pos_callback          (GLFWwindow*, double xpos, double ypos);
  static void cursor_enter_callback        (GLFWwindow*, int entered);
  static void mouse_button_callback        (GLFWwindow*, int button, int action, int mods);
  static void scroll_callback              (GLFWwindow*, double xoffset, double yoffset);
  static void joystick_callback            (GLFWwindow*, int jid, int event);
  static void drop_callback                (GLFWwindow*, int count, const char** paths);
};

}


#endif