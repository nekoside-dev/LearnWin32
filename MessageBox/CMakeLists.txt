project(MessageBox)

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_options(${PROJECT_NAME} PRIVATE "/ENTRY:mainCRTStartup")