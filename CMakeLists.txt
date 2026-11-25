cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows-static")

project(LearnWin32)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(MessageBox)
add_subdirectory(Window)
add_subdirectory(Notification)
add_subdirectory(Button)
add_subdirectory(ChildWindow)
add_subdirectory(Icon)
add_subdirectory(Text)
add_subdirectory(OpenGL)