#include "Window.h"
#include "Events/WindowEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

namespace pt
{

Window::Window(uint32_t width, uint32_t height, const std::string& title)
	: m_width(width), m_height(height), m_title(title)
{
	// Initialize GLFW and glad.
	if (!glfwInit())
		crash("Failed to initialize GLFW.");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		crash("Failed to create a window.");
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		crash("Failed to initialize glad.");
	}

	// Set callbacks.
	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			Window* ctx = static_cast<Window*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent ev;
			ctx->m_windowEventDispatcher.dispatch(ev);
		});

	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			Window* ctx = static_cast<Window*>(glfwGetWindowUserPointer(window));
			ctx->m_width = width;
			ctx->m_height = height;
			WindowResizeEvent ev(width, height);
			ctx->m_windowEventDispatcher.dispatch(ev);
		});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* ctx = static_cast<Window*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressEvent ev(key, false);
				ctx->m_windowEventDispatcher.dispatch(ev);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleaseEvent ev(key);
				ctx->m_windowEventDispatcher.dispatch(ev);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressEvent ev(key, true);
				ctx->m_windowEventDispatcher.dispatch(ev);
				break;
			}
			default:
				PT_UNREACHABLE();
			}
		});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
		{
			Window* ctx = static_cast<Window*>(glfwGetWindowUserPointer(window));
			MouseMoveEvent ev(xpos, ypos);
			ctx->m_windowEventDispatcher.dispatch(ev);
		});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
		{
			Window* ctx = static_cast<Window*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressEvent ev(button);
				ctx->m_windowEventDispatcher.dispatch(ev);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleaseEvent ev(button);
				ctx->m_windowEventDispatcher.dispatch(ev);
				break;
			}
			default:
				PT_UNREACHABLE();
			}
		});

	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			Window* ctx = static_cast<Window*>(glfwGetWindowUserPointer(window));
			MouseScrollEvent ev(xoffset, yoffset);
			ctx->m_windowEventDispatcher.dispatch(ev);
		});

	glfwSetErrorCallback([](int error, const char* description)
		{
			Log::error("GLFW error: {}", description);
		});
}

Window::~Window()
{
	glfwTerminate();
}

void Window::setTitle(const std::string& title)
{
	m_title = title;
	glfwSetWindowTitle(m_window, title.c_str());
}

}