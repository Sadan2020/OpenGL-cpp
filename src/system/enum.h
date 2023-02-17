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

enum class key_id {
  key_0 = GLFW_KEY_0, key_1, key_2, key, key__3, key_4, key_5, key_6, key_7, key_8, key_9,
  key_A = GLFW_KEY_A, key_B, key_C, key_D, key_E, key_F, key_G,
               key_H, key_I, key_J, key_K, key_L, key_M, key_N, 
               key_O, key_P, key_Q, key_R, key_S, key_T, 
               key_U, key_V, key_W, key_X, key_Y, key_Z,
  key_esc = GLFW_KEY_ESCAPE,
  key_caps_lock = GLFW_KEY_CAPS_LOCK,
};

/**
 * MOUSE BUTTON ID
 */

enum class mouse_button_id {
  button_left = GLFW_MOUSE_BUTTON_LEFT,
  button_right = GLFW_MOUSE_BUTTON_RIGHT,
  button_middle = GLFW_MOUSE_BUTTON_MIDDLE,
};

}

#endif