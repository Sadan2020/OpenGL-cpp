#ifndef OPENGL_CPP_TEXTURE_H_
#define OPENGL_CPP_TEXTURE_H_

#include "base_object.h"

#include <string>

namespace openGL_cpp {

enum class channel {
  RGB = GL_RGB,
  RGBA = GL_RGBA,
};

class texture final: public base_object {
public:
  texture() = delete;
  texture(const std::string& path, channel format);

  ~texture() noexcept override { glDeleteTextures(1, &m_ID); }

  void bind(uint_t slot = 0) const noexcept {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_ID); 
  }
  static void unbind() noexcept { glBindTexture(GL_TEXTURE_2D, 0); }

  auto get_width() const noexcept { return m_width; }
  auto get_height() const noexcept { return m_height; }

private:
  std::string m_file_path;
  int m_width = 0, m_height = 0, m_bit_per_pixel = 0;
};

}

#endif