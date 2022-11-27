#pragma once
#include <Gfx/graphicsBase.h>

class Window {
public:
	void create(uint32_t w, uint32_t h, const char* title);
	void cleanup();
	void close();
	bool shouldClose();

	uint32_t width, height;
private:
	GLFWwindow* window;
};