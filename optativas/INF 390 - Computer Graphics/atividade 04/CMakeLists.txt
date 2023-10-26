cmake_minimum_required(VERSION 3.0.0)
project(atividade_04 VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

add_executable(atividade_04 src/main.cpp)

add_subdirectory(glad)
target_link_libraries(${PROJECT_NAME} glad)

option(BUILD_SHARED_LIBS "Build shared library" ON)
add_subdirectory(glm)
target_link_libraries(${PROJECT_NAME} glm)

target_link_libraries(atividade_04 
    glfw
    OpenGL::GL
    dl
)


