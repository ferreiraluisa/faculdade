cmake_minimum_required(VERSION 3.0.0)
project(atividade_03 VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

add_executable(atividade_03 src/main.cpp)

add_subdirectory(glad)
target_link_libraries(atividade_03 glad)

add_subdirectory(glm)
target_link_libraries(atividade_03 glm)

target_link_libraries(atividade_03 glfw OpenGL::GL dl)


