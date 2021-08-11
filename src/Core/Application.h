#pragma once

#include "UI/Window.h"
#include "UI/ImGuiContext.h"
#include "PathTracerContext.h"
#include "Events/WindowEvent.h"

namespace pt
{

class Application
{
public:
	Application();
	~Application() { s_instance = nullptr; }

	static Application& get() { PT_ASSERT(s_instance != nullptr); return *s_instance; }

	void run();

	Window& getWindow() { return m_window; }
	ImGuiContext& getImGuiContext() { return m_imguiContext; }

	void close() { m_running = false; }

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

private:
	bool handleWindowClose(WindowCloseEvent& ev);

private:
	Window m_window;
	ImGuiContext m_imguiContext;
	PathTracerContext m_ptContext;
	
	bool m_running = false;

	static Application* s_instance;
};

}