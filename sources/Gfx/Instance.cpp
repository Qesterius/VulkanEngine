#include <Gfx/Instance.h>

void Instance::create(const std::vector<const char*>& extensions, bool debug)
{
	debugEnabled = debug;
	std::vector<const char*> layers;
	vk::DebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo;
	void* pNext = nullptr;

	if (debugEnabled) 
	{
		if (!debugManager.checkValidationLayerSupport())
			throw std::runtime_error("validation layers requested, but not available");
		layers = debugManager.validationLayers;
		debugMessengerCreateInfo = debugManager.getMessengerCreateInfo();
		pNext = &debugMessengerCreateInfo;
	}
	vk::ApplicationInfo applicationInfo("VulkanClient",1,"LukiEngine",1,VK_API_VERSION_1_3);

	//printing required extensions
	std::cout << "Required extensions..." << std::endl;
	for (auto& extension : extensions) 
	{
		std::cout << extension << std::endl;
	}
	std::vector<vk::ExtensionProperties> availableExtensions = vk::enumerateInstanceExtensionProperties();
	std::cout << "Available extensions..." << std::endl;
	for (auto& extension : availableExtensions)
	{
		std::cout << extension.extensionName << std::endl;
	}
	vk::InstanceCreateInfo createInfo(
		{}, 
		&applicationInfo, 
		layers,
		extensions
	);
	createInfo.setPNext(pNext);

	instance = vk::createInstance( createInfo );
	if (debugEnabled)
	{
		debugManager.setup(instance);
	}
}

void Instance::cleanup()
{
	if (debugEnabled) 
	{
		debugManager.cleanup(instance);
	}
	instance.destroy();
}
