#pragma once

#include "Layer.h"

#include "GLFW/glfw3.h"

namespace Walnut {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUIRender() override;

		void Init();
		void Run();
		void Terminate();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		ImGuiIO& io;
	};
}
