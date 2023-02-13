# OPENGL-CPP 0.0.1

## Introduction

一个基于 *GLAD* 和 *GLFW* 的 c++ 图形库

利用 c++ 的对象和模板对其进行了抽象，使之更易于使用

仅为个人练习所写，存在很多问题

## Dependencies

* GLAD

* GLFW 3.3.8

* stb_image

* glm 0.9.9.8

## Using

### 步骤

1. 确保 c++ 版本为 c++20 以上

2. 将 "include" 目录添加到头文件中

3. 链接库 openGL_cpp

### CMake 指令如下:

``` cmake

add_subdirectory(deps/openGL-0.0.1)

target_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/openGL-0.0.1/include)

target_link_libraries(${PROJECT_NAME} openGL_cpp)


```
