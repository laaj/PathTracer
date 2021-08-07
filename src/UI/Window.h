#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Events/EventDispatcher.h"

namespace pt
{

class Window
{
public:
	Window(uint32_t width, uint32_t height, const std::string& title);
	~Window();

	void init();

	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }

	GLFWwindow* getNativeWindow() { return m_window; }

	void setTitle(const std::string& title);

	void swapBuffers() { glfwSwapBuffers(m_window); }
	void pollEvents() { glfwPollEvents(); }

	EventDispatcher::Binder& getEventBinder() { return m_windowEventDispatcher.getBinder(); }

private:
	GLFWwindow* m_window = nullptr;
	uint32_t m_width, m_height;
	std::string m_title;
	EventDispatcher m_windowEventDispatcher;
};

}