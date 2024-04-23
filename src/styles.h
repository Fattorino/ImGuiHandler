#include <imgui.h>

inline static void setStyleClassic()
{
    ImGuiStyle& s = ImGui::GetStyle();

    s.Alpha = 1.0f;
    s.DisabledAlpha = 0.6000000238418579f;
    s.WindowPadding = ImVec2(8.0f, 8.0f);
    s.WindowRounding = 0.0f;
    s.WindowBorderSize = 1.0f;
    s.WindowMinSize = ImVec2(32.0f, 32.0f);
    s.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    s.WindowMenuButtonPosition = ImGuiDir_Left;
    s.ChildRounding = 0.0f;
    s.ChildBorderSize = 1.0f;
    s.PopupRounding = 0.0f;
    s.PopupBorderSize = 1.0f;
    s.FramePadding = ImVec2(4.0f, 3.0f);
    s.FrameRounding = 0.0f;
    s.FrameBorderSize = 0.0f;
    s.ItemSpacing = ImVec2(8.0f, 4.0f);
    s.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    s.CellPadding = ImVec2(4.0f, 2.0f);
    s.IndentSpacing = 21.0f;
    s.ColumnsMinSpacing = 6.0f;
    s.ScrollbarSize = 14.0f;
    s.ScrollbarRounding = 9.0f;
    s.GrabMinSize = 10.0f;
    s.GrabRounding = 0.0f;
    s.TabRounding = 4.0f;
    s.TabBorderSize = 0.0f;
    s.TabMinWidthForCloseButton = 0.0f;
    s.ColorButtonPosition = ImGuiDir_Right;
    s.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    s.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    ImGui::StyleColorsClassic();
}

inline static void setStyleDark()
{
    ImGuiStyle& s = ImGui::GetStyle();

    s.Alpha = 1.0f;
    s.DisabledAlpha = 0.6000000238418579f;
    s.WindowPadding = ImVec2(8.0f, 8.0f);
    s.WindowRounding = 0.0f;
    s.WindowBorderSize = 1.0f;
    s.WindowMinSize = ImVec2(32.0f, 32.0f);
    s.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    s.WindowMenuButtonPosition = ImGuiDir_Left;
    s.ChildRounding = 0.0f;
    s.ChildBorderSize = 1.0f;
    s.PopupRounding = 0.0f;
    s.PopupBorderSize = 1.0f;
    s.FramePadding = ImVec2(4.0f, 3.0f);
    s.FrameRounding = 0.0f;
    s.FrameBorderSize = 0.0f;
    s.ItemSpacing = ImVec2(8.0f, 4.0f);
    s.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    s.CellPadding = ImVec2(4.0f, 2.0f);
    s.IndentSpacing = 21.0f;
    s.ColumnsMinSpacing = 6.0f;
    s.ScrollbarSize = 14.0f;
    s.ScrollbarRounding = 9.0f;
    s.GrabMinSize = 10.0f;
    s.GrabRounding = 0.0f;
    s.TabRounding = 4.0f;
    s.TabBorderSize = 0.0f;
    s.TabMinWidthForCloseButton = 0.0f;
    s.ColorButtonPosition = ImGuiDir_Right;
    s.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    s.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    ImGui::StyleColorsDark();
}

inline static void setStyleLight()
{
    ImGuiStyle& s = ImGui::GetStyle();

    s.Alpha = 1.0f;
    s.DisabledAlpha = 0.6000000238418579f;
    s.WindowPadding = ImVec2(8.0f, 8.0f);
    s.WindowRounding = 0.0f;
    s.WindowBorderSize = 1.0f;
    s.WindowMinSize = ImVec2(32.0f, 32.0f);
    s.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    s.WindowMenuButtonPosition = ImGuiDir_Left;
    s.ChildRounding = 0.0f;
    s.ChildBorderSize = 1.0f;
    s.PopupRounding = 0.0f;
    s.PopupBorderSize = 1.0f;
    s.FramePadding = ImVec2(4.0f, 3.0f);
    s.FrameRounding = 0.0f;
    s.FrameBorderSize = 0.0f;
    s.ItemSpacing = ImVec2(8.0f, 4.0f);
    s.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    s.CellPadding = ImVec2(4.0f, 2.0f);
    s.IndentSpacing = 21.0f;
    s.ColumnsMinSpacing = 6.0f;
    s.ScrollbarSize = 14.0f;
    s.ScrollbarRounding = 9.0f;
    s.GrabMinSize = 10.0f;
    s.GrabRounding = 0.0f;
    s.TabRounding = 4.0f;
    s.TabBorderSize = 0.0f;
    s.TabMinWidthForCloseButton = 0.0f;
    s.ColorButtonPosition = ImGuiDir_Right;
    s.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    s.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    ImGui::StyleColorsLight();
}

inline static void setStyleBrownLeather()
{
    ImGuiStyle& s = ImGui::GetStyle();

    s.Alpha = 1.0f;
    s.DisabledAlpha = 0.1000000014901161f;
    s.WindowPadding = ImVec2(8.0f, 8.0f);
    s.WindowRounding = 6.0f;
    s.WindowBorderSize = 0.0f;
    s.WindowMinSize = ImVec2(30.0f, 30.0f);
    s.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    s.WindowMenuButtonPosition = ImGuiDir_Right;
    s.ChildRounding = 6.0f;
    s.ChildBorderSize = 1.0f;
    s.PopupRounding = 10.0f;
    s.PopupBorderSize = 0.0f;
    s.FramePadding = ImVec2(5.0f, 3.5f);
    s.FrameRounding = 4.0f;
    s.FrameBorderSize = 0.0f;
    s.ItemSpacing = ImVec2(5.0f, 4.0f);
    s.ItemInnerSpacing = ImVec2(5.0f, 5.0f);
    s.CellPadding = ImVec2(4.0f, 2.0f);
    s.IndentSpacing = 5.0f;
    s.ColumnsMinSpacing = 5.0f;
    s.ScrollbarSize = 15.0f;
    s.ScrollbarRounding = 9.0f;
    s.GrabMinSize = 11.5f;
    s.GrabRounding = 3.0f;
    s.TabRounding = 5.0f;
    s.TabBorderSize = 0.0f;
    s.TabMinWidthForCloseButton = 0.0f;
    s.ColorButtonPosition = ImGuiDir_Right;
    s.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    s.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    s.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    s.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    s.Colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.07f, 0.04f, 1.00f);
    s.Colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.07f, 0.04f, 1.00f);
    s.Colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.07f, 0.04f, 1.00f);
    s.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    s.Colors[ImGuiCol_BorderShadow] = ImVec4(0.13f, 0.16f, 0.18f, 1.00f);
    s.Colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.16f, 0.13f, 1.00f);
    s.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.42f, 0.34f, 0.30f, 1.00f);
    s.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.47f, 0.39f, 0.35f, 1.00f);
    s.Colors[ImGuiCol_TitleBg] = ImVec4(0.24f, 0.16f, 0.13f, 1.00f);
    s.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.50f, 0.42f, 0.38f, 1.00f);
    s.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.07f, 0.04f, 0.72f);
    s.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.30f, 0.22f, 0.19f, 1.00f);
    s.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.68f);
    s.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.90f, 0.90f, 0.80f, 0.56f);
    s.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.90f, 0.90f, 0.80f, 0.80f);
    s.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.90f, 0.90f, 0.80f, 0.80f);
    s.Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.80f, 1.00f);
    s.Colors[ImGuiCol_SliderGrab] = ImVec4(0.36f, 0.28f, 0.24f, 1.00f);
    s.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.90f, 0.90f, 0.80f, 0.35f);
    s.Colors[ImGuiCol_Button] = ImVec4(0.30f, 0.22f, 0.18f, 1.00f);
    s.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.34f, 0.30f, 1.00f);
    s.Colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.31f, 0.28f, 1.00f);
    s.Colors[ImGuiCol_Header] = ImVec4(0.22f, 0.16f, 0.12f, 1.00f);
    s.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.28f, 0.22f, 0.16f, 1.00f);
    s.Colors[ImGuiCol_HeaderActive] = ImVec4(0.27f, 0.21f, 0.17f, 1.00f);
    s.Colors[ImGuiCol_Separator] = ImVec4(0.90f, 0.90f, 0.80f, 0.28f);
    s.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.90f, 0.90f, 0.80f, 0.28f);
    s.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.90f, 0.90f, 0.80f, 0.28f);
    s.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.36f, 0.28f, 0.24f, 1.00f);
    s.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.84f, 0.81f, 0.64f, 0.50f);
    s.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.84f, 0.81f, 0.64f, 0.50f);
    s.Colors[ImGuiCol_Tab] = ImVec4(0.24f, 0.18f, 0.12f, 1.00f);
    s.Colors[ImGuiCol_TabHovered] = ImVec4(0.32f, 0.24f, 0.20f, 1.00f);
    s.Colors[ImGuiCol_TabActive] = ImVec4(0.40f, 0.35f, 0.32f, 1.00f);
    s.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
    s.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
    s.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    s.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    s.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    s.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    s.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
    s.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
    s.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
    s.Colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    s.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
    s.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    s.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    s.Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    s.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    s.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    s.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

inline static void setStyleFoggyPurple()
{
    ImGuiStyle& s = ImGui::GetStyle();

    s.Alpha = 1.0f;
    s.DisabledAlpha = 0.1000000014901161f;
    s.WindowPadding = ImVec2(8.0f, 8.0f);
    s.WindowRounding = 10.0f;
    s.WindowBorderSize = 0.0f;
    s.WindowMinSize = ImVec2(30.0f, 30.0f);
    s.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    s.WindowMenuButtonPosition = ImGuiDir_Right;
    s.ChildRounding = 5.0f;
    s.ChildBorderSize = 1.0f;
    s.PopupRounding = 10.0f;
    s.PopupBorderSize = 0.0f;
    s.FramePadding = ImVec2(5.0f, 3.5f);
    s.FrameRounding = 5.0f;
    s.FrameBorderSize = 0.0f;
    s.ItemSpacing = ImVec2(5.0f, 4.0f);
    s.ItemInnerSpacing = ImVec2(5.0f, 5.0f);
    s.CellPadding = ImVec2(4.0f, 2.0f);
    s.IndentSpacing = 5.0f;
    s.ColumnsMinSpacing = 5.0f;
    s.ScrollbarSize = 15.0f;
    s.ScrollbarRounding = 9.0f;
    s.GrabMinSize = 11.5f;
    s.GrabRounding = 5.0f;
    s.TabRounding = 5.0f;
    s.TabBorderSize = 0.0f;
    s.TabMinWidthForCloseButton = 0.0f;
    s.ColorButtonPosition = ImGuiDir_Right;
    s.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    s.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    s.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    s.Colors[ImGuiCol_TextDisabled] = ImVec4(1.0f, 1.0f, 1.0f, 0.3605149984359741f);
    s.Colors[ImGuiCol_WindowBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    s.Colors[ImGuiCol_ChildBg] = ImVec4(1.0f, 0.0f, 0.0f, 0.0f);
    s.Colors[ImGuiCol_PopupBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    s.Colors[ImGuiCol_Border] = ImVec4(0.4235294163227081f, 0.3803921639919281f, 0.572549045085907f, 0.54935622215271f);
    s.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    s.Colors[ImGuiCol_FrameBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    s.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3803921639919281f, 0.4235294163227081f, 0.572549045085907f, 0.5490196347236633f);
    s.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_TitleBg] = ImVec4(0.1373390555381775f, 0.1373376846313477f, 0.1373376846313477f, 1.0f);
    s.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.2317596673965454f, 0.2317573428153992f, 0.2317573428153992f, 1.0f);
    s.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.2588235437870026f, 0.2588235437870026f, 0.2588235437870026f, 0.0f);
    s.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.3843137323856354f, 0.3607843220233917f, 0.4666666686534882f, 1.0f);
    s.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 0.0f);
    s.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    s.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.2352941185235977f, 0.2352941185235977f, 0.2352941185235977f, 1.0f);
    s.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.294117659330368f, 0.294117659330368f, 0.294117659330368f, 1.0f);
    s.Colors[ImGuiCol_CheckMark] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.8412017226219177f);
    s.Colors[ImGuiCol_SliderGrab] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.8156862854957581f, 0.772549033164978f, 0.9647058844566345f, 0.5490196347236633f);
    s.Colors[ImGuiCol_Button] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_ButtonActive] = ImVec4(0.8156862854957581f, 0.772549033164978f, 0.9647058844566345f, 0.5490196347236633f);
    s.Colors[ImGuiCol_Header] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_HeaderActive] = ImVec4(0.8156862854957581f, 0.772549033164978f, 0.9647058844566345f, 0.5490196347236633f);
    s.Colors[ImGuiCol_Separator] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.8156862854957581f, 0.772549033164978f, 0.9647058844566345f, 0.5490196347236633f);
    s.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.8156862854957581f, 0.772549033164978f, 0.9647058844566345f, 0.5490196347236633f);
    s.Colors[ImGuiCol_Tab] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_TabHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_TabActive] = ImVec4(0.8156862854957581f, 0.772549033164978f, 0.9647058844566345f, 0.5490196347236633f);
    s.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.0f, 0.4509803950786591f, 1.0f, 0.0f);
    s.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1333333402872086f, 0.2588235437870026f, 0.4235294163227081f, 0.0f);
    s.Colors[ImGuiCol_PlotLines] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.6196078658103943f, 0.5764706134796143f, 0.7686274647712708f, 0.5490196347236633f);
    s.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
    s.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.4235294163227081f, 0.3803921639919281f, 0.572549045085907f, 0.5490196347236633f);
    s.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.4235294163227081f, 0.3803921639919281f, 0.572549045085907f, 0.2918455004692078f);
    s.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    s.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.03433477878570557f);
    s.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.7372549176216125f, 0.6941176652908325f, 0.886274516582489f, 0.5490196347236633f);
    s.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    s.Colors[ImGuiCol_NavHighlight] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    s.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    s.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
    s.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

inline static void setStyleDracula()
{
    ImGuiStyle& s = ImGui::GetStyle();

    s.Alpha = 1.0f;
    s.DisabledAlpha = 0.1000000014901161f;
    s.WindowPadding = ImVec2(8.0f, 8.0f);
    s.WindowRounding = 7.0f;
    s.WindowBorderSize = 0.0f;
    s.WindowMinSize = ImVec2(30.0f, 30.0f);
    s.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    s.WindowMenuButtonPosition = ImGuiDir_Right;
    s.ChildRounding = 4.0f;
    s.ChildBorderSize = 1.0f;
    s.PopupRounding = 4.0f;
    s.PopupBorderSize = 0.0f;
    s.FramePadding = ImVec2(5.0f, 3.5f);
    s.FrameRounding = 3.0f;
    s.FrameBorderSize = 0.0f;
    s.ItemSpacing = ImVec2(5.0f, 4.0f);
    s.ItemInnerSpacing = ImVec2(5.0f, 5.0f);
    s.CellPadding = ImVec2(4.0f, 2.0f);
    s.IndentSpacing = 5.0f;
    s.ColumnsMinSpacing = 5.0f;
    s.ScrollbarSize = 15.0f;
    s.ScrollbarRounding = 9.0f;
    s.GrabMinSize = 11.5f;
    s.GrabRounding = 3.0f;
    s.TabRounding = 4.0f;
    s.TabBorderSize = 0.0f;
    s.TabMinWidthForCloseButton = 0.0f;
    s.ColorButtonPosition = ImGuiDir_Right;
    s.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    s.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    ImGui::StyleColorsDark();

    auto &colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_WindowBg] = ImVec4{0.1f, 0.1f, 0.13f, 1.0f};
    colors[ImGuiCol_MenuBarBg] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};

// Border
    colors[ImGuiCol_Border] = ImVec4{0.44f, 0.37f, 0.61f, 0.29f};
    colors[ImGuiCol_BorderShadow] = ImVec4{0.0f, 0.0f, 0.0f, 0.24f};

// Text
    colors[ImGuiCol_Text] = ImVec4{1.0f, 1.0f, 1.0f, 1.0f};
    colors[ImGuiCol_TextDisabled] = ImVec4{0.5f, 0.5f, 0.5f, 1.0f};

// Headers
    colors[ImGuiCol_Header] = ImVec4{0.13f, 0.13f, 0.17, 1.0f};
    colors[ImGuiCol_HeaderHovered] = ImVec4{0.19f, 0.2f, 0.25f, 1.0f};
    colors[ImGuiCol_HeaderActive] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};

// Buttons
    colors[ImGuiCol_Button] = ImVec4{0.13f, 0.13f, 0.17, 1.0f};
    colors[ImGuiCol_ButtonHovered] = ImVec4{0.19f, 0.2f, 0.25f, 1.0f};
    colors[ImGuiCol_ButtonActive] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};
    colors[ImGuiCol_CheckMark] = ImVec4{0.74f, 0.58f, 0.98f, 1.0f};

// Popups
    colors[ImGuiCol_PopupBg] = ImVec4{0.1f, 0.1f, 0.13f, 0.92f};

// Slider
    colors[ImGuiCol_SliderGrab] = ImVec4{0.44f, 0.37f, 0.61f, 0.54f};
    colors[ImGuiCol_SliderGrabActive] = ImVec4{0.74f, 0.58f, 0.98f, 0.54f};

// Frame BG
    colors[ImGuiCol_FrameBg] = ImVec4{0.13f, 0.13, 0.17, 1.0f};
    colors[ImGuiCol_FrameBgHovered] = ImVec4{0.19f, 0.2f, 0.25f, 1.0f};
    colors[ImGuiCol_FrameBgActive] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};

// Tabs
    colors[ImGuiCol_Tab] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};
    colors[ImGuiCol_TabHovered] = ImVec4{0.24, 0.24f, 0.32f, 1.0f};
    colors[ImGuiCol_TabActive] = ImVec4{0.2f, 0.22f, 0.27f, 1.0f};
    colors[ImGuiCol_TabUnfocused] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};

// Title
    colors[ImGuiCol_TitleBg] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};
    colors[ImGuiCol_TitleBgActive] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};

// Scrollbar
    colors[ImGuiCol_ScrollbarBg] = ImVec4{0.1f, 0.1f, 0.13f, 1.0f};
    colors[ImGuiCol_ScrollbarGrab] = ImVec4{0.16f, 0.16f, 0.21f, 1.0f};
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4{0.19f, 0.2f, 0.25f, 1.0f};
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4{0.24f, 0.24f, 0.32f, 1.0f};

// Seperator
    colors[ImGuiCol_Separator] = ImVec4{0.44f, 0.37f, 0.61f, 1.0f};
    colors[ImGuiCol_SeparatorHovered] = ImVec4{0.74f, 0.58f, 0.98f, 1.0f};
    colors[ImGuiCol_SeparatorActive] = ImVec4{0.84f, 0.58f, 1.0f, 1.0f};

// Resize Grip
    colors[ImGuiCol_ResizeGrip] = ImVec4{0.44f, 0.37f, 0.61f, 0.29f};
    colors[ImGuiCol_ResizeGripHovered] = ImVec4{0.74f, 0.58f, 0.98f, 0.29f};
    colors[ImGuiCol_ResizeGripActive] = ImVec4{0.84f, 0.58f, 1.0f, 0.29f};
}
