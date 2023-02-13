#ifndef OPENGL_CPP_DRAW_H_
#define OPENGL_CPP_DRAW_H_

#include "../system/enum.h"

namespace openGL_cpp {

class program;
class vertex_array;

inline void clear(buffer_bit mask) noexcept {  glClear(static_cast<bitfield_t>(mask)); }

void draw(const program& shader, const vertex_array& VAO);
void draw(const program& shader, const vertex_array& VAO, uint_t count);
  
}


#endif