#ifndef OPENGL_CPP_PROGRAM_H_
#define OPENGL_CPP_PROGRAM_H_

#include "base_object.h"
#include "shader_error.h"

#include "../system/mat.h"
#include "../system/enum.h"
#include "../system/type.h"

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <type_traits>

namespace openGL_cpp {

class vertex_shader;
class fragment_shader;

class program final: public base_object, private shader_error {
public:
  program() = delete;
  program(const vertex_shader& vs, const fragment_shader& fs);

  ~program() noexcept override {  glDeleteProgram(m_ID);  }

  void bind() const noexcept { glUseProgram(m_ID); }
  static void unbind() noexcept { glUseProgram(0); }

  template<typename T, typename... Args>
  void set_uniform(const std::string& name, const T& value, Args... args) {
    static_assert(sizeof...(args) < 4, "the arguments in uniform are too much (>4)");

    constexpr auto size = sizeof...(args);
    auto location = get_uniform_location(name);

    if constexpr(std::is_same_v<T, float_t>) {
           if constexpr(size == 0)  glUniform1f(location, value);
      else if constexpr(size == 1)  glUniform2f(location, value, args...);
      else if constexpr(size == 2)  glUniform3f(location, value, args...);
      else if constexpr(size == 3)  glUniform4f(location, value, args...);
    }

    else if constexpr(std::is_same_v<T, vec1>) glUniform1f(location, value.x);
    else if constexpr(std::is_same_v<T, vec2>) glUniform2f(location, value.x, value.y); 
    else if constexpr(std::is_same_v<T, vec3>) glUniform3f(location, value.x, value.y, value.z);
    else if constexpr(std::is_same_v<T, vec4>) glUniform4f(location, value.x, value.y, value.z, value.w);

    else if constexpr(std::is_same_v<T, int_t>) {
           if constexpr(size == 0)  glUniform1i(location, value);
      else if constexpr(size == 1)  glUniform2i(location, value, args...);
      else if constexpr(size == 2)  glUniform3i(location, value, args...);
      else if constexpr(size == 3)  glUniform4i(location, value, args...);
    }

    else if constexpr(std::is_same_v<T, bool>)  glUniform1i(location, value);

    else if constexpr(std::is_same_v<T, mat3>) glUniformMatrix3fv(location, 1, false_v, glm::value_ptr(value));
    else if constexpr(std::is_same_v<T, mat4>) glUniformMatrix4fv(location, 1, false_v, glm::value_ptr(value));
  }

  template<typename T>
  void set_uniform_vector(const std::string& name, const T* ptr, std::size_t count) {
    auto location = get_uniform_location(name);

         if constexpr(std::is_same_v<T, uint_t>)   { glUniform1uiv(location, count, ptr); }
    else if constexpr(std::is_same_v<T, int_t>)    { glUniform1iv(location, count, ptr);  }
    else if constexpr(std::is_same_v<T, float_t>)  { glUniform1fv(location, count, ptr);  }
  }

private:
  mutable std::unordered_map<std::string, int_t> uniform_location_cache;

  const std::string& profile_pre() const override {
    static std::string s = "ERROR::SHADER::PROGRAM";
    return s;
  }

  int_t get_uniform_location(const std::string& name) const {
    if(auto location = uniform_location_cache.find(name); location != uniform_location_cache.end()) {
      return location->second;
    }

    auto location = glGetUniformLocation(m_ID, name.c_str());
    if(location == -1) {
      throw std::runtime_error("can't find uniform: " + name);
    }
    uniform_location_cache[name] = location;
    return location;
  }

  void link() const;
};

}

#endif