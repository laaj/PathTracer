#pragma once

#include "UI/Window.h"
#include "UI/Editor.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/WindowEvent.h"

namespace pt
{

class Application
{
public:
	Application();

	static Application& get() { return *s_instance; }

	Window& getWindow() { return m_window; }

	void run();

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

private:
	void update();

	bool handleWindowClose(WindowCloseEvent& ev);

private:
	Window m_window;
	Editor m_editor;
	bool m_running = true;

	static Application* s_instance;
};

}