#include "kit.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace openGL_cpp {

namespace kit {

std::string read_file(const std::string& path) {
  std::ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  file.open(path);
  std::stringstream stream;
  stream << file.rdbuf();
  file.close();
  return stream.str();
}

}

}