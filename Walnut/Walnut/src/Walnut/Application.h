#pragma once

#include "Layer.h"

#include <string>
#include <functional>

//#include "imgui.h"
//#include "ImguiUtils.h"
#include "ImGuiLayer.h"

#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "Window.h"

namespace Walnut {

	class Application
	{
	public:
		//Application name, width and height of the screen
		Application(const std::string& _name, const uint32_t& _width, const uint32_t& _height);
		~Application();

		inline static Application& Get() { return *s_Instance; }
		inline GLFWwindow* GetWindow () { return m_window; }
		inline uint32_t GetWidth() { return m_width; }
		inline uint32_t GetHeight() { return m_height; }

		void Run();

	private:
		const std::string m_name;
		const uint32_t m_width, m_height;
		GLFWwindow* m_window = nullptr;

		static Application* s_Instance;

		ImGuiLayer* m_imguiLayer = nullptr;

		int Init();
		void Terminate();

		std::vector<std::shared_ptr<Layer>> m_LayerStack;
		std::function<void()> m_MenubarCallback;
	};

	// Implemented by CLIENT
	Application* CreateApplication(int argc, char** argv);
}


