cmake_minimum_required(VERSION 4.0.0)

project(PrivilegeElevation)

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE shell32)