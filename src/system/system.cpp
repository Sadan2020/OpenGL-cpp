#include "system.h"

#include <stdexcept>

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace openGL_cpp {

void init_glfw(float version) noexcept {
  auto version_major = static_cast<int>(version);
  auto version_minor = static_cast<int>((version - version_major) * 10);

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version_major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version_minor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void load_glad() {
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    throw std::runtime_error("Failed to initialize GLAD");
  }
}

}