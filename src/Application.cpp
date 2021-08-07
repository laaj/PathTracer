#include "Application.h"

namespace pt
{

Application* Application::s_instance = nullptr;

Application::Application()
	: m_window(800, 600, "Path Tracer")
{
	s_instance = this;	

	Log::init();
	m_window.init();
	m_editor.init();

	// Window event callbacks.
	auto& windowEventBinder = m_window.getEventBinder();
	windowEventBinder.addHandler<WindowCloseEvent>(PT_BIND_FN(handleWindowClose));
}

void Application::run()
{
	while (m_running)
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		m_editor.render();

		m_window.swapBuffers();
		m_window.pollEvents();
	}
}

void Application::update()
{
}

bool Application::handleWindowClose(WindowCloseEvent& ev)
{
	PT_UNUSED(ev);

	m_running = false;
	return true;
}

}