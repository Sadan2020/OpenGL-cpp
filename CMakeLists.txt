cmake_minimum_required(VERSION 3.15)

project(OPENGL_CPP VERSION 0.0.1 LANGUAGES CXX)

FILE(GLOB_RECURSE   OPENGL_CPP_SRC  
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
  ${CMAKE_CURRENT_SOURCE_DIR}/deps/glad/src/glad.c
  ${CMAKE_CURRENT_SOURCE_DIR}/deps/stb_image/src/stb_image.cpp
  )

add_library(openGL_cpp STATIC ${OPENGL_CPP_SRC})

target_include_directories(openGL_cpp PUBLIC 
  ${PROJECT_SOURCE_DIR}/deps/glfw-3.3.8/include
  ${PROJECT_SOURCE_DIR}/deps/glad/include
  ${PROJECT_SOURCE_DIR}/deps/stb_image/include
  ${PROJECT_SOURCE_DIR}/deps/glm-0.9.9.8/include
  )

#---------------------------------------------------#
#                   GLFW setting
#---------------------------------------------------#

# 禁用 GLFW tests, examples, docs
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw-3.3.8)

target_link_libraries(openGL_cpp glfw)