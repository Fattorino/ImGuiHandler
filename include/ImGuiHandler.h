#pragma once

#include "imgui.h"
#include "../src/imgui_bindings/imgui_impl_glfw.h"
#include "../src/imgui_bindings/imgui_impl_opengl3.h"
#include <cstdio>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#include <string>
#include <vector>
#include <functional>
#include <memory>

typedef void (*WinBlock)();
typedef void (*CustomStyler_Callback)();
enum IGH_Style
{
    IGH_Style_Classic,
    IGH_Style_Dark,
    IGH_Style_Light,
    IGH_Style_BrownLeather,
    IGH_Style_FoggyPurple,
    IGH_Style_Custom
};

class appLayer
{
public:
	virtual void onCreate() {};
	virtual void update() = 0;
	virtual void menuBar() {}
};

class ImGuiHandle
{
public:

	ImGuiHandle() = default;

    bool init(const std::string& bigParentName);
	bool init(const std::string& bigParentName, unsigned int bigParentW, unsigned int bigParentH);

	void menuBar(WinBlock menuBarContent) { _menuBar = menuBarContent; }

	void loop(bool* done);

	void end();

	template<typename T>
	void pushLayer()
	{
		static_assert(std::is_base_of<appLayer, T>::value, "Pushed type is not subclass of Layer!");
		_winsStack.emplace_back(std::make_shared<T>())->onCreate();
	}

	void setActiveWin(int index)
	{
		if (index >= _winsStack.size())
			_activeWin = 0;
		else
			_activeWin = index;
	}

    void setCustomStyler(CustomStyler_Callback styler) { m_stylerFunc = styler; } // TODO: Add support for multiple custom styles
    void setStyle(IGH_Style style);
private:
    GLFWwindow* window{};

    WinBlock _menuBar = nullptr;
    CustomStyler_Callback m_stylerFunc = nullptr;

    std::vector<std::shared_ptr<appLayer>> _winsStack;
    int _activeWin = -1;
};

extern ImGuiHandle IGH;

namespace ImToro
{
	bool vCombo(const char* label, int* current_item, ::std::vector<::std::string> items);

	class PopupWindow
	{
	public:
		PopupWindow(const char* title, WinBlock content);
		PopupWindow(const char* title, WinBlock content, ImVec2 size);

		void update();

		void show() { m_showFlag = true; }
		// void hide() { m_visible = false; }

		void setSize(ImVec2 size) { m_size = size; }

	private:
		std::string m_title;
		ImVec2 m_size{ 200, 200 };
		bool m_visible = false;
		bool m_showFlag = false;

		WinBlock m_content = nullptr;

	};
}
