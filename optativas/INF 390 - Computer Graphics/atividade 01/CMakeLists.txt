cmake_minimum_required(VERSION 3.0.0)
project(atividade_01 VERSION 0.1.0)

include_directories(include)

add_subdirectory(src)

add_executable(atividade_01 src/main.cpp)
target_link_libraries(atividade_01 PRIVATE glad glfw dl)  # Add dl here
