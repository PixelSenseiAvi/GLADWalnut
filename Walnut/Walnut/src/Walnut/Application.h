#pragma once

#include "Layer.h"

#include <string>
#include <functional>

#include "ImguiUtils.h"
#include "glad/glad.h"

namespace Walnut {

	class Application
	{
	public:
		//Application name, width and height of the screen
		Application(const std::string& _name, const uint32_t& _width, const uint32_t& _height);
		~Application();

	private:
		const std::string m_name;
		const uint32_t m_width, m_height;
		GLFWwindow* m_window = nullptr;

		int Init();
		void Run();
		void Terminate();

		std::vector<std::shared_ptr<Layer>> m_LayerStack;
		std::function<void()> m_MenubarCallback;
	};

	// Implemented by CLIENT
	Application* CreateApplication(int argc, char** argv);
}


