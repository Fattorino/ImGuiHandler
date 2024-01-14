#pragma once

#include "imgui.h"
#include "../imgui_bindings/imgui_impl_glfw.h"
#include "../imgui_bindings/imgui_impl_opengl3.h"
#include <cstdio>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#include <string>
#include <vector>
#include <functional>
#include <memory>

typedef void (*WinBlock)();

class appLayer
{
public:
	virtual void onCreate() {};
	virtual void update() = 0;
	virtual void menuBar() {}
};

class ImGuiHandle
{
private:
    GLFWwindow* window{};

	WinBlock _bgFunc = nullptr;
	WinBlock _menuBar = nullptr;
	
	std::vector<std::shared_ptr<appLayer>> _winsStack;
	int _activeWin = -1;

public:

	ImGuiHandle() = default;

    bool init(std::string bigParentName);
	bool init(std::string bigParentName, unsigned int bigParentW, unsigned int bigParentH);

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
};

extern ImGuiHandle IGH;

namespace ImToro
{
	bool vCombo(const char* label, int* current_item, ::std::vector<::std::string> items, int popup_max_height_in_items = -1);

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
