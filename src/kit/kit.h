#ifndef OPENGL_CPP_KIT_H_
#define OPENGL_CPP_KIT_H_

#include <string>

namespace openGL_cpp {

namespace kit {

template<typename T, typename Z>
void move_to(T& lhs, T& rhs, Z&& zero) {
  rhs = lhs;
  lhs = zero;
}

std::string read_file(const std::string& path);
  
}

}

#endif