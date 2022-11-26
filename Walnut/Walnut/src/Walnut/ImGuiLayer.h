#pragma once

#include "Layer.h"
#include "Window.h"
#include "imgui.h"

//#include "GLFW/glfw3.h"

namespace Walnut {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(Window* window);
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUIRender() override;

		void Begin();
		void End();

		//void Init();
		void Run();
		//void Terminate();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;

		GLFWwindow* m_window;
		uint32_t m_width = 0, m_height = 0;
	};
}
