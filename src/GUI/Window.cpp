#include "Window.h"
#include "WindowEvent.h"
#include "MouseEvent.h"
#include "KeyEvent.h"

namespace pt
{

Window::Window(uint32_t width, uint32_t height, const std::string& title)
	: m_props(width, height, title)
{
	// Initialize GLFW and glad.
	if (!glfwInit())
		crash("Failed to initialize GLFW.");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_props.width, m_props.height, m_props.title.c_str(), nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		crash("Failed to create a window.");
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &m_props);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		crash("Failed to initialize glad.");
	}

	// Set callbacks.
	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			WindowProps* props = static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent ev;
			props->eventCallback(ev);
		});

	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			WindowProps* props = static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
			props->width = width;
			props->height = height;
			WindowResizeEvent ev(width, height);
			props->eventCallback(ev);
		});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowProps* props = static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
			if (action == GLFW_PRESS)
			{
				KeyPressEvent ev(key, false);
				props->eventCallback(ev);
			} 			
			else if (action == GLFW_RELEASE)
			{
				KeyReleaseEvent ev(key);
				props->eventCallback(ev);
			} 			
			else
			{
				KeyPressEvent ev(key, true);
				props->eventCallback(ev);
			}
		});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowProps* props = static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
			MouseMoveEvent ev(xpos, ypos);
			props->eventCallback(ev);
		});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowProps* props = static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
			if (action == GLFW_PRESS)
			{
				MousePressEvent ev(button);
				props->eventCallback(ev);
			} 			
			else
			{
				MouseReleaseEvent ev(button);
				props->eventCallback(ev);
			}
		});

	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowProps* props = static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
			MouseScrollEvent ev(xoffset, yoffset);
			props->eventCallback(ev);
		});

	glfwSetErrorCallback([](int error, const char* description)
		{
			fprintf(stderr, "Error: %s\n", description);
		});
}

Window::~Window()
{
	glfwTerminate();
}

}