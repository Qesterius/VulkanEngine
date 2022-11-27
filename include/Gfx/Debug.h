#pragma once
#include<Gfx/graphicsBase.h>

class Debug {
public:
	void setup(const vk::Instance& instance);
	void cleanup(const vk::Instance& instance);
	bool checkValidationLayerSupport();
	vk::DebugUtilsMessengerCreateInfoEXT getMessengerCreateInfo();


	const std::vector<const char*> validationLayers = {
		"VK_LAYER+KHRONOS_validation"
	};

private:
	vk::DebugUtilsMessengerEXT debugmessenger;
};