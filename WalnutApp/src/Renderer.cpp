#include "Renderer.h"

#include "Walnut/Random.h"

void Renderer::OnResize(uint32_t width, uint32_t height)
{
	if (m_FinalImage)
	{
		if (m_FinalImage->GetWidth() == width && m_FinalImage->GetHeight() == height)
			return;
		m_FinalImage->Resize(width, height); //TODO: Implement
	}
	else
	{
		m_FinalImage = std::make_shared < Walnut::Image >(width, height, Walnut::ImageFormat::RGBA);
	}

	delete[] m_ImageData;
	m_ImageData = new uint32_t[width * height];
}

void Renderer::Render()
{
	for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++) {
		for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++)
		{
			glm::vec2 coord = { (float)x / (float)m_FinalImage->GetWidth(), (float)y / (float)m_FinalImage->GetHeight() };

			m_ImageData[x + y*m_FinalImage->GetWidth()] = PerPixel(coord);

		}
	}

	m_FinalImage->SetData((void*)m_ImageData);
	m_FinalImage->UseTexture();
}


//Fragment Shader
uint32_t Renderer::PerPixel(glm::vec2 coord)
{
	uint32_t pixel = Walnut::Random::UInt();
	pixel |= 0xff000000;
	return pixel;
}

