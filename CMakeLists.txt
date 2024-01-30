cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

# CREATE PROJECT
project(ImGuiHandler)

# SET SOURCE FILES FOR PROJECT
file(GLOB_RECURSE _HDRS "include/*.h")
file(GLOB_RECURSE _SRCS "src/*.cpp" "src/*.h")

# CREATE LIBRARY FROM SOURCE_FILES
add_library(${PROJECT_NAME} ${_SRCS} ${_HDRS})

# FIND DEPENDENCIES
find_package(imgui)
find_package(opengl_system)
find_package(glfw3)

# LINK DEPENDENCIES
target_link_libraries(ImGuiHandler
        imgui::imgui
        opengl::opengl
        glfw)

# ADD TO INCLUDE DIRECTORIES
target_include_directories(ImGuiHandler PUBLIC include)
