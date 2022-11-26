#pragma once
#include "GLFW/glfw3.h"

struct Window {
	GLFWwindow* window;
	uint32_t width;
	uint32_t height;
};
