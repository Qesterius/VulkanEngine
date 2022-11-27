#pragma once
#include <IO/Window.h>
#include <Gfx/Instance.h>
#include <vector>
class Engine {
public: 
	void Initialize();
	void MainLoop();
	void Cleanup();
private:
	Window window;
	Instance instance;
	std::vector<const char*> getRequiredExtensions();

#ifdef NDEBUG
	const bool debug = false;
#else
	const bool debug = true;
#endif

};
