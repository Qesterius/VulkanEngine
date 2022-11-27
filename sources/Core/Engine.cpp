#include <Core/Engine.h>

void Engine::Initialize()
{
	window.create(1600,800,"Vulkan");
	instance.create(getRequiredExtensions(),debug);
}

void Engine::MainLoop()
{
	while (!window.shouldClose()) 
	{
		glfwPollEvents();
		//rendering code...

		
	}
}

void Engine::Cleanup()
{
	window.cleanup();
	instance.cleanup();
}

std::vector<const char*> Engine::getRequiredExtensions() 
{
	uint32_t glfwExtensionsCount;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);
	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionsCount);

	return extensions;		
}
