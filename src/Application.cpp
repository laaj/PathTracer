#include "Application.h"

namespace pt
{

Application* Application::s_instance = nullptr;

Application::Application()
	: m_window(800, 600, "Path Tracer")
{
	s_instance = this;	
	auto& windowEventBinder = m_window.getEventBinder();
	windowEventBinder.addHandler<WindowCloseEvent>(BIND_FN(handleWindowClose));
}

void Application::run()
{
	while (m_running)
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		m_window.swapBuffers();
		m_window.pollEvents();
	}
}

bool Application::handleWindowClose(WindowCloseEvent& ev)
{
	m_running = false;
	return true;
}

void Application::update()
{
}

}