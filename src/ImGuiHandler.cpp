#include "../include/ImGuiHandler.h"

// Global class declaration
ImGuiHandle IGH;


static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

bool ImGuiHandle::init(std::string bigParentName)
{
	return init(bigParentName, 1200, 800);
}

bool ImGuiHandle::init(std::string bigParentName, unsigned int bigParentW, unsigned int bigParentH)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

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

	// Setup Dear ImGui style
	{
		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.07f, 0.04f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.07f, 0.04f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.07f, 0.04f, 1.00f);
		colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.13f, 0.16f, 0.18f, 1.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.16f, 0.13f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.42f, 0.34f, 0.30f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.47f, 0.39f, 0.35f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.24f, 0.16f, 0.13f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.50f, 0.42f, 0.38f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.07f, 0.04f, 0.72f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.30f, 0.22f, 0.19f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.68f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.90f, 0.90f, 0.80f, 0.56f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.90f, 0.90f, 0.80f, 0.80f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.90f, 0.90f, 0.80f, 0.80f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.80f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.36f, 0.28f, 0.24f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.90f, 0.90f, 0.80f, 0.35f);
		colors[ImGuiCol_Button] = ImVec4(0.30f, 0.22f, 0.18f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.34f, 0.30f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.31f, 0.28f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.22f, 0.16f, 0.12f, 1.00f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.28f, 0.22f, 0.16f, 1.00f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.27f, 0.21f, 0.17f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.90f, 0.90f, 0.80f, 0.28f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.90f, 0.90f, 0.80f, 0.28f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.90f, 0.90f, 0.80f, 0.28f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.36f, 0.28f, 0.24f, 1.00f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.84f, 0.81f, 0.64f, 0.50f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.84f, 0.81f, 0.64f, 0.50f);
		colors[ImGuiCol_Tab] = ImVec4(0.24f, 0.18f, 0.12f, 1.00f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.32f, 0.24f, 0.20f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.40f, 0.35f, 0.32f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
		colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

		ImGui::GetStyle().FrameRounding = 4.0;
		ImGui::GetStyle().WindowRounding = 6.0;
		ImGui::GetStyle().ChildRounding = 6.0;
		ImGui::GetStyle().GrabRounding = 3.0;
	}

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

	if (_bgFunc)
		_bgFunc();

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


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


namespace ImToro
{
	bool vCombo(const char* label, int* current_item, ::std::vector<::std::string> items, int popup_max_height_in_items)
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
