#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Event.h"

namespace pt
{

class Window
{
public:
	using EventCallbackFn = std::function<void(const Event&)>;

	struct WindowProps
	{
		WindowProps(uint32_t width, uint32_t height, std::string title)
			: width(width), height(height), title(title) {}

		uint32_t width, height;
		std::string title;
		EventCallbackFn eventCallback;
	};

public:
	Window(uint32_t width, uint32_t height, const std::string& title);
	~Window();

	uint32_t getWidth() const { return m_props.width; }
	uint32_t getHeight() const { return m_props.height; }

	void setTitle(const std::string& title) 
	{ 
		m_props.title = title; 
		glfwSetWindowTitle(m_window, title.c_str()); 
	}
	void setEventCallback(const EventCallbackFn& fn) { m_props.eventCallback = fn; }

private:
	GLFWwindow* m_window = nullptr;
	WindowProps m_props;
};

}