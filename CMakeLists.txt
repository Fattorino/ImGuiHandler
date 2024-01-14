cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

# CREATE PROJECT
project(ImGuiHandler)

# SET SOURCE FILES FOR PROJECT
file(GLOB_RECURSE _HDRS "include/*.h")
file(GLOB_RECURSE _SRCS "src/*.cpp")
file(GLOB_RECURSE _IMGUI_BINDINGS "imgui_bindings/*.cpp" "imgui_bindings/*.h")

# CREATE LIBRARY FROM SOURCE_FILES
add_library(ImGuiHandler ${_SRCS} ${_HDRS} ${_IMGUI_BINDINGS})

# FIND DEPENDENCIES
find_package(imgui)
find_package(opengl_system)
find_package(glfw3)

# LINK CONAN LIBS
target_link_libraries(ImGuiHandler
        imgui::imgui
        opengl::opengl
        glfw)

# PREP TO USE "#include <>"
target_include_directories(ImGuiHandler PUBLIC include)

#DEVELOPMENT PROJECT
project(ImGuiHandler_dev)
add_executable(ImGuiHandler_dev main.cpp)
target_link_libraries(ImGuiHandler_dev ImGuiHandler)
