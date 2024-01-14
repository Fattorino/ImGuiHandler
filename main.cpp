#include <ImGuiHandler.h>

class DemoWindow : public appLayer
{
private:
    float var = 200.f;

public:
    void onCreate() override
    {
        var = 200.f;
    }

    void update() override
    {
        ImGui::Begin("DemoWindow");
        ImGui::SliderFloat("Drag me", &var, 0.f, 100.f);
        ImGui::Text("VAL: %f", var);
        ImGui::End();
    }

    void menuBar() override
    {
        if (ImGui::BeginMenu("Demo"))
        {
            if (ImGui::MenuItem("Win")) { }
            if (ImGui::MenuItem("dow")) { }
            ImGui::EndMenu();
        }
    }
};

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
    if (!IGH.init("Example", 1300, 800))
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
