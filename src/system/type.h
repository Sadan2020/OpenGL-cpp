#ifndef OPENGL_CPP_TYPE_H_
#define OPENGL_CPP_TYPE_H_

#include "glad/glad.h"

#include <type_traits>

namespace openGL_cpp {

enum class type_id: GLenum {
  float_t = GL_FLOAT,
  clampf_t = GL_FLOAT,
#ifdef GL_DOUBLE
  double_t = GL_DOUBLE,
#endif
  bool_t = GL_BOOL,
  byte_t = GL_BYTE,     ubyte_t = GL_UNSIGNED_BYTE,
  short_t = GL_SHORT,   ushort_t = GL_UNSIGNED_SHORT,
  int_t = GL_INT,       uint_t = GL_UNSIGNED_INT,
};

using float_t = GLfloat;
using clampf_t = GLclampf;
#ifdef GL_DOUBLE
using double_t = GLdouble;
#endif
using bool_t = GLboolean;
using char_t = GLchar;
using byte_t = GLbyte;    using ubyte_t = GLubyte;
using short_t = GLshort;  using ushort_t = GLushort;
using int_t = GLint;      using uint_t = GLuint;

using size_t = GLsizei;
using bitfield_t = GLbitfield;
using enum_t = GLenum;

template<typename T>
constexpr type_id get_type_id() noexcept {
  if constexpr(std::is_same_v<T, float_t>)      { return type_id::float_t; }
#ifdef GL_DOUBLE
  else if constexpr(std::is_same_v<T, double_t>){ return type_id::double_t; }
#endif
  else if constexpr(std::is_same_v<T, clampf_t>){ return type_id::clampf_t; }
  else if constexpr(std::is_same_v<T, bool_t>)  { return type_id::bool_t; }
  else if constexpr(std::is_same_v<T, byte_t>)  { return type_id::byte_t; }
  else if constexpr(std::is_same_v<T, ubyte_t>) { return type_id::ubyte_t; }
  else if constexpr(std::is_same_v<T, short_t>) { return type_id::short_t; }
  else if constexpr(std::is_same_v<T, ushort_t>){ return type_id::ushort_t; }
  else if constexpr(std::is_same_v<T, int_t>)   { return type_id::int_t;  }
  else if constexpr(std::is_same_v<T, uint_t>)  { return type_id::uint_t; }
  else { /* TO DO */  }
}

constexpr size_t get_size_of_type(type_id type) noexcept {
  switch(type) {
    case type_id::bool_t: 
    case type_id::byte_t:
    case type_id::ubyte_t:  return 1;
    case type_id::short_t:
    case type_id::ushort_t: return 2;
    case type_id::float_t:
    case type_id::int_t:
    case type_id::uint_t:   return 4;
#ifdef GL_DOUBLE
    case type_id::double_t: return 8;
#endif
  }
  return 0;
}

}

#endif