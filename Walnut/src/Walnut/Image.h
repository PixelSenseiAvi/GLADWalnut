#pragma once

#include <string>

//#include "vulkan/vulkan.h"
#include "glad/glad.h"

namespace Walnut {

	enum class ImageFormat
	{
		None = 0,
		RGBA,
		RGBA32F
	};

	class Image
	{
	public:
		Image(std::string_view path);
		Image(uint32_t width, uint32_t height, ImageFormat format, const void* data = nullptr);
		~Image();

		void UseTexture();
		void Resize(uint32_t width, uint32_t height);
		void Image::SetData(const void* data);

		inline uint32_t GetWidth() const { return m_Width; }
		inline uint32_t GetHeight() const { return m_Height; }
		inline GLuint GetTextureID() const { return m_textureID; }
		
	private:

		void Release();
	private:
		uint32_t m_Width = 0, m_Height = 0;
		uint32_t m_bitDepth = 0;

		ImageFormat m_Format = ImageFormat::None;

		std::string m_Filepath;
		GLuint m_textureID = 0;
	};

}



