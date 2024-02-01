# ImGui Handler
**Simple library to handle an OpenGL window with Dear ImGui integration**

![image](https://github.com/Fattorino/ImGuiHandler/assets/90210751/18c16629-a39f-4835-8510-b0e2a76fe58d)


## Features
- Class based windows management system
- Built-in OpenGL event handling
- Built-in ImGui handling

## Implementation (CMake project)
### CMake `FetchContent`
1. Add the following lines to your CMakeLists.txt:
   ```
   include(FetchContent)
   FetchContent_Declare(ImGuiHandler
        GIT_REPOSITORY "https://github.com/Fattorino/ImGuiHandler.git"
        GIT_TAG "origin/master"
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/includes/ImGuiHandler"
   )
   FetchContent_MakeAvailable(ImGuiHandler)
   ```
   ```
   target_link_libraries(YourProject ImGuiHandler)
   ```
2. Make sure you have the following dependencies available for `find_package()`:
   - [Dear ImGui](https://github.com/ocornut/imgui)
   - OpenGL
   - GLFW

### Manually
1. Download and copy, or clone the repo inside your project
2. Add the following lines to your CMakeLists.txt:
   ```
   add_subdirectory(path/to/ImGuiHandler)
   target_link_libraries(YourProject ImGuiHandler)
   ```
3. Make sure you have the following dependencies available for `find_package()`:
   - [Dear ImGui](https://github.com/ocornut/imgui)
   - OpenGL
   - GLFW

## Basic Usage
### DemoWindow.h
```c++
#include <ImGuiHandler.h>

class DemoWindow : public appLayer
{
private:
    float var = 200.f;

public:
    void onCreate() override;

    void update() override;

    void menuBar() override;
};
```
### DemoWindow.cpp
```c++
#include "DemoWindow.h

void DemoWindow::onCreate() { var = 200.f; }

void DemoWindow::update()
{
    ImGui::Begin("DemoWindow");
    ImGui::SliderFloat("Drag me", &var, 0.f, 100.f);
    ImGui::Text("VAL: %f", var);
    ImGui::End();
}

void DemoWindow::menuBar()
{
    if (ImGui::BeginMenu("Demo"))
    {
        if (ImGui::MenuItem("Win")) { }
        if (ImGui::MenuItem("dow")) { }
        ImGui::EndMenu();
    }
}
```
### main.cpp
```c++
#include "DemoWindow.h"

void menuBar()
{
    if (ImGui::BeginMenu("Main parent window"))
    {
        if (ImGui::MenuItem("Menu")) { }
        if (ImGui::MenuItem("Bar")) { }
        ImGui::EndMenu();
    }
}

int main()
{
    if (!IGH.init("Example", 650, 200))
        return 1;

    ImGui::GetIO().IniFilename = nullptr;

    IGH.pushLayer<DemoWindow>();

    IGH.menuBar(menuBar);
    IGH.setActiveWin(0);

    bool done = false;
    while (!done)
    {
        IGH.loop(&done);
    }

    IGH.end();
    return 0;
}
```
![image](https://github.com/Fattorino/ImGuiHandler/assets/90210751/d617ef49-2dcf-42d0-be06-fec69cee16be)

