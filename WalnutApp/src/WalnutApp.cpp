#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"

#include "Walnut/Timer.h"

using namespace Walnut;

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Text("Last render: %.3fms", m_LastRenderTime);
		if (ImGui::Button("Render"))
		{
			Render();
		}
		ImGui::End();

		//ImGui::ShowDemoWindow();
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
		ImGui::Begin("Viewport");

		//m_ViewPortWidth = ImGui::GetContentRegionAvail().x;
		//m_ViewPortHeight = ImGui::GetContentRegionAvail().y;

		/*if (m_Image)
			ImGui::Image(m_Image->GetDescriptorSet(), { (float)m_Image->GetWidth(), (float)m_Image->GetHeight() });*/

		ImGui::End();
		ImGui::PopStyleVar();
	}
	void Render()
	{
		Timer timer;
		/*if (!m_Image || m_ViewPortWidth != m_Image->GetWidth() || m_ViewPortHeight != m_Image->GetHeight())
		{
			m_Image = std::make_shared<Image>(m_ViewPortWidth, m_ViewPortHeight, ImageFormat::RGBA);
			delete[] m_ImageData;
			m_ImageData = new uint32_t[m_ViewPortWidth * m_ViewPortHeight];
		}
		for (uint32_t i = 0; i < m_ViewPortWidth * m_ViewPortHeight; i++)
		{
			m_ImageData[i] = 0xffff00ff;
		}*/

		m_LastRenderTime = timer.ElapsedMillis();
	}
private:
	uint32_t m_ViewPortWidth = 0, m_ViewPortHeight = 0;
	uint32_t* m_ImageData;
	float m_LastRenderTime;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}