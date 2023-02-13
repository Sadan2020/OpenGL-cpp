#include "texture.h"

#include "stb_image.h"

#include <stdexcept>

namespace openGL_cpp {

texture::texture(const std::string& path, channel format):
  m_file_path(path)
{
  stbi_set_flip_vertically_on_load(true);
  auto local_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bit_per_pixel, 4);

  glGenTextures(1, &m_ID);
  bind(15); // TO DO

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  if(!local_buffer) {
    throw std::runtime_error("failed to load texture");
  }

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0,
               static_cast<enum_t>(format), GL_UNSIGNED_BYTE, local_buffer);
  
  stbi_image_free(local_buffer);
}

}