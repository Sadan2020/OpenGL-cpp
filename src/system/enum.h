#ifndef OPENGL_CPP_ENUM_H_
#define OPENGL_CPP_ENUM_H_

#include "type.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace openGL_cpp {

/**
 * BOOL
 */

constexpr auto true_v = GL_TRUE;
constexpr auto false_v = GL_FALSE;

/**
 * BUFFER BIT
 */

enum class buffer_bit : bitfield_t {
  color_buffer_bit = GL_COLOR_BUFFER_BIT,
  depth_buffer_bit = GL_DEPTH_BUFFER_BIT,
#ifdef GL_ACCUM_BUFFER_BIT
  accum_buffer_bit = GL_ACCUM_BUFFER_BIT,
#endif
  stencil_buffer_bit = GL_STENCIL_BUFFER_BIT
};

inline auto operator|(buffer_bit lhs, buffer_bit rhs) {
  return static_cast<buffer_bit>(static_cast<bitfield_t>(lhs) | static_cast<bitfield_t>(rhs));
}

/**
 * KEY ID
 */

enum class key_token {
  /* The unknown key */
  key_unknown = GLFW_KEY_UNKNOWN,

  /* Printable keys */
  key_space = GLFW_KEY_SPACE,
  key_apostrophe = GLFW_KEY_APOSTROPHE,
  key_comma = GLFW_KEY_COMMA,
  key_minus = GLFW_KEY_MINUS,
  key_period = GLFW_KEY_PERIOD,
  key_slash = GLFW_KEY_SLASH,
  key_0 = GLFW_KEY_0, key_1, key_2, key, key_3, key_4, key_5, key_6, key_7, key_8, key_9,
  key_semicolon = GLFW_KEY_SEMICOLON,
  key_equal = GLFW_KEY_EQUAL,
  key_A = GLFW_KEY_A, key_B, key_C, key_D, key_E, key_F, key_G,
               key_H, key_I, key_J, key_K, key_L, key_M, key_N, 
               key_O, key_P, key_Q, key_R, key_S, key_T, 
               key_U, key_V, key_W, key_X, key_Y, key_Z,
  key_left_bracket = GLFW_KEY_LEFT_BRACKET,
  key_backslash = GLFW_KEY_BACKSLASH,
  key_right_bracket = GLFW_KEY_RIGHT_BRACKET,
  key_grave_accent = GLFW_KEY_GRAVE_ACCENT,
  key_world_1 = GLFW_KEY_WORLD_1,
  key_world_2 = GLFW_KEY_WORLD_2,

  /* Function keys */
  key_escape = GLFW_KEY_ESCAPE,
  key_enter = GLFW_KEY_ENTER,
  key_tab = GLFW_KEY_TAB,
  key_backspace = GLFW_KEY_BACKSPACE,
  key_insert = GLFW_KEY_INSERT,
  key_delete = GLFW_KEY_DELETE,
  key_right = GLFW_KEY_RIGHT,
  key_left = GLFW_KEY_LEFT,
  key_down = GLFW_KEY_DOWN,
  key_up = GLFW_KEY_UP,
  key_page_up = GLFW_KEY_PAGE_UP,
  key_page_down = GLFW_KEY_PAGE_DOWN,
  key_home = GLFW_KEY_HOME,
  key_end = GLFW_KEY_END,
  key_caps_lock = GLFW_KEY_CAPS_LOCK,
  key_scroll_lock = GLFW_KEY_SCROLL_LOCK,
  key_num_lock = GLFW_KEY_NUM_LOCK,
  key_print_screen = GLFW_KEY_PRINT_SCREEN,
  key_pause = GLFW_KEY_PAUSE,
  key_f1 = GLFW_KEY_F1,
  key_f2 = GLFW_KEY_F2,
  key_f3 = GLFW_KEY_F3,
  key_f4 = GLFW_KEY_F4,
  key_f5 = GLFW_KEY_F5,
  key_f6 = GLFW_KEY_F6,
  key_f7 = GLFW_KEY_F7,
  key_f8 = GLFW_KEY_F8,
  key_f9 = GLFW_KEY_F9,
  key_f10 = GLFW_KEY_F10,
  key_f11 = GLFW_KEY_F11,
  key_f12 = GLFW_KEY_F12,
  key_f13 = GLFW_KEY_F13,
  key_f14 = GLFW_KEY_F14,
  key_f15 = GLFW_KEY_F15,
  key_f16 = GLFW_KEY_F16,
  key_f17 = GLFW_KEY_F17,
  key_f18 = GLFW_KEY_F18,
  key_f19 = GLFW_KEY_F19,
  key_f20 = GLFW_KEY_F20,
  key_f21 = GLFW_KEY_F21,
  key_f22 = GLFW_KEY_F22,
  key_f23 = GLFW_KEY_F23,
  key_f24 = GLFW_KEY_F24,
  key_f25 = GLFW_KEY_F25,
  key_kp_0 = GLFW_KEY_KP_0,
  key_kp_1 = GLFW_KEY_KP_1,
  key_kp_2 = GLFW_KEY_KP_2,
  key_kp_3 = GLFW_KEY_KP_3,
  key_kp_4 = GLFW_KEY_KP_4,
  key_kp_5 = GLFW_KEY_KP_5,
  key_kp_6 = GLFW_KEY_KP_6,
  key_kp_7 = GLFW_KEY_KP_7,
  key_kp_8 = GLFW_KEY_KP_8,
  key_kp_9 = GLFW_KEY_KP_9,
  key_kp_decimal = GLFW_KEY_KP_DECIMAL,
  key_kp_divide = GLFW_KEY_KP_DIVIDE,
  key_kp_multiply = GLFW_KEY_KP_MULTIPLY,
  key_kp_subtract = GLFW_KEY_KP_SUBTRACT,
  key_kp_add = GLFW_KEY_KP_ADD,
  key_kp_enter = GLFW_KEY_KP_ENTER,
  key_kp_equal = GLFW_KEY_KP_EQUAL,
  key_left_shift = GLFW_KEY_LEFT_SHIFT,
  key_left_control = GLFW_KEY_LEFT_CONTROL,
  key_left_alt = GLFW_KEY_LEFT_ALT,
  key_left_super = GLFW_KEY_LEFT_SUPER,
  key_right_shift = GLFW_KEY_RIGHT_SHIFT,
  key_right_control = GLFW_KEY_RIGHT_CONTROL,
  key_right_alt = GLFW_KEY_RIGHT_ALT,
  key_right_super = GLFW_KEY_RIGHT_SUPER,
  key_menu = GLFW_KEY_MENU,
};

enum class key_action {
  press = GLFW_PRESS,
  release = GLFW_RELEASE,
  repeat = GLFW_REPEAT,
};

/**
 * MOUSE BUTTON ID
 */

enum class mouse_button_token {
  button_left = GLFW_MOUSE_BUTTON_LEFT,
  button_right = GLFW_MOUSE_BUTTON_RIGHT,
  button_middle = GLFW_MOUSE_BUTTON_MIDDLE,
};

}

#endif