add_library(glad OBJECT glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
