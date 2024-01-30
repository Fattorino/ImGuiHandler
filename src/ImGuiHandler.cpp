#include "../include/ImGuiHandler.h"

// Global class declaration
ImGuiHandle IGH;


static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

bool ImGuiHandle::init(const std::string& bigParentName)
{
	return init(bigParentName, 1200, 800);
}

bool ImGuiHandle::init(const std::string& bigParentName, unsigned int bigParentW, unsigned int bigParentH)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return true;

	// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
	// GL ES 2.0 + GLSL 100
	const char* glsl_version = "#version 100";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
	// GL 3.2 + GLSL 150
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

	// Create window with graphics context
	window = glfwCreateWindow(bigParentW, bigParentH, bigParentName.c_str(), NULL, NULL);
	if (window == NULL)
		return false;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    setStyle(IGH_Style_FoggyPurple);

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	return true;
}

void ImGuiHandle::loop(bool* done)
{
	if (glfwWindowShouldClose(window))
	{
		*done = true;
		return;
	}

	glfwPollEvents();

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	if (_menuBar)
	{
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGuiWindowFlags bgmenu_window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		ImGui::Begin("bgmenu", nullptr, bgmenu_window_flags);

		ImGui::PopStyleVar();
		ImGui::PopStyleVar(2);

		if (ImGui::BeginMenuBar())
		{
			_menuBar();
			_winsStack[_activeWin]->menuBar();
			ImGui::EndMenuBar();
		}
		ImGui::End();
	}

	_winsStack[_activeWin]->update();

	// Rendering
	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(1.00f, 1.00f, 1.00f, 1.00f);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window);
}

void ImGuiHandle::end()
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void ImGuiHandle::setStyle(IGH_Style style)
{
    ImGuiStyle& s = ImGui::GetStyle();
    switch (style)
    {
        case IGH_Style_Classic: {
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
            break;
        }
        case IGH_Style_Dark: {
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
            break;
        }
        case IGH_Style_Light: {
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
            break;
        }
        case IGH_Style_BrownLeather: {
            s.FrameRounding = 4.0;
            s.WindowRounding = 6.0;
            s.ChildRounding = 6.0;
            s.GrabRounding = 3.0;

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
            break;
        }
        case IGH_Style_FoggyPurple: {
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
            break;
        }
        case IGH_Style_Custom: {
            if(m_stylerFunc)
                m_stylerFunc();
            break;
        }
        default:
            break;
    }
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


namespace ImToro
{
	bool vCombo(const char* label, int* current_item, std::vector<std::string> items)
	{
		bool toReturn = false;
		if (items.empty())
		{
			if (ImGui::BeginCombo(label, "Empty"))
				ImGui::EndCombo();
		}
		else
		{
			if (ImGui::BeginCombo(label, items[*current_item].c_str()))
			{
				for (int i = 0; i < items.size(); i++)
				{
                    if(items[i].empty())
                        continue;

					if (ImGui::Selectable(items[i].c_str()))
					{
						*current_item = i;
						toReturn = true;
						// std::cout << "NUM: " << i << "\n";
					}
				}
				ImGui::EndCombo();
			}
		}
		return toReturn;
	}

	PopupWindow::PopupWindow(const char* title, WinBlock content)
	{
		m_title = std::string(title);
		m_content = content;
	}

	PopupWindow::PopupWindow(const char* title, WinBlock content, ImVec2 size)
	{
		m_title = std::string(title);
		m_content = content;
		m_size = size;
	}

	void PopupWindow::update()
	{
		if (m_showFlag)
		{
			ImGui::OpenPopup(m_title.c_str());
			ImGui::SetNextWindowSize(m_size, ImGuiCond_Appearing);
			ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
			m_showFlag = false;
		}

		if (ImGui::BeginPopupModal(m_title.c_str()))
		{
			if (m_content)
				m_content();
			else
				if (ImGui::Button("CLOSE"))
					ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}
	}
}
