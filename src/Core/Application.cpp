#include "Application.h"
#include <imgui.h>
#include "Events/WindowEvent.h"

namespace pt
{

Application* Application::s_instance = nullptr;

Application::Application()
	: m_window(800, 600, "Path Tracer")
{
	PT_ASSERT(s_instance == nullptr);
	s_instance = this;	

	Log::init();
	m_window.init();
	m_imguiContext.init();

	// Window event callbacks.
	auto& windowEventBinder = m_window.getEventBinder();
	windowEventBinder.addHandler<WindowCloseEvent>(PT_BIND_FN(handleWindowClose));
}

void Application::run()
{
	PT_ASSERT(!m_running);
	m_running = true;

	while (m_running)
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		m_imguiContext.startRender();
		m_ptContext.renderImGui();
		m_imguiContext.endRender();

		m_window.pollEvents();
		m_window.swapBuffers();
	}
}

bool Application::handleWindowClose(WindowCloseEvent& ev)
{
	PT_UNUSED(ev);

	m_running = false;
	return true;
}

}