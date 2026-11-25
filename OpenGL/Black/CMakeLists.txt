cmake_minimum_required(VERSION 4.0.0)

project(Black)

find_package(glad CONFIG REQUIRED)

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad opengl32)
