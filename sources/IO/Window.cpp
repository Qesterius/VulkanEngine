#include <IO/Window.h>


void Window::create(uint32_t w, uint32_t h, const char* title)
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(w, h, title
		, nullptr, nullptr);

	width = w;
	height = h;
}

void Window::cleanup()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::close()
{
	glfwSetWindowShouldClose(window, true);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}
