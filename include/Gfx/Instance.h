#pragma once

#include <Gfx/graphicsBase.h>
#include <vector>
#include <iostream>
#include <Gfx/Debug.h>

class Instance {
public:
	void Instance::create(const std::vector<const char*>& extensions, bool debug);
	void Instance::cleanup();
private:
	vk::Instance instance;
	bool debugEnabled;
	Debug debugManager;
};