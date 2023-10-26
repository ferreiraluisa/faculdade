cmake_minimum_required(VERSION 3.0.0)
project(atividade_02 VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

add_executable(atividade_02 src/main.cpp)

add_subdirectory(glad)
target_link_libraries(atividade_02 glad)

target_link_libraries(atividade_02 glfw OpenGL::GL dl)


