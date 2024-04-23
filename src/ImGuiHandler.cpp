#include "../include/ImGuiHandler.h"
#include "styles.h"

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
            setStyleClassic();
            break;
        }
        case IGH_Style_Dark: {
            setStyleDark();
            break;
        }
        case IGH_Style_Light: {
            setStyleLight();
            break;
        }
        case IGH_Style_BrownLeather: {
            setStyleBrownLeather();
            break;
        }
        case IGH_Style_FoggyPurple: {
            setStyleFoggyPurple();
            break;
        }
        case IGH_Style_Dracula: {
            setStyleDracula();
            break;
        }
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
