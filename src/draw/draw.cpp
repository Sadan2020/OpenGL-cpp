#include "draw.h"

#include "../object/vertex_array.h"
#include "../object/program.h"

namespace openGL_cpp {

void draw(const program& shader, const vertex_array& VAO) {
  draw(shader, VAO, VAO.count());
}

void draw(const program& shader, const vertex_array& VAO, uint_t count) {
  shader.bind();
  VAO.bind();
  glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}


}