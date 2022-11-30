#include "Image.h"

#include "imgui.h"
//#include "backends/imgui_impl_vulkan.h"

#include "Application.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Walnut {

	namespace Utils {

		/*static uint32_t GetVulkanMemoryType(VkMemoryPropertyFlags properties, uint32_t type_bits)
		{
			VkPhysicalDeviceMemoryProperties prop;
			vkGetPhysicalDeviceMemoryProperties(Application::GetPhysicalDevice(), &prop);
			for (uint32_t i = 0; i < prop.memoryTypeCount; i++)
			{
				if ((prop.memoryTypes[i].propertyFlags & properties) == properties && type_bits & (1 << i))
					return i;
			}

			return 0xffffffff;
		}*/

		static uint32_t BytesPerPixel(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGBA:    return 4;
			case ImageFormat::RGBA32F: return 16;
			}
			return 0;
		}

		/*static VkFormat WalnutFormatToVulkanFormat(ImageFormat format)
		{
			switch (format)
			{
				case ImageFormat::RGBA:    return VK_FORMAT_R8G8B8A8_UNORM;
				case ImageFormat::RGBA32F: return VK_FORMAT_R32G32B32A32_SFLOAT;
			}
			return (VkFormat)0;
		}*/

	}

	Image::Image(std::string_view path)
		: m_Filepath(path)
	{
		int width, height, channels;
		uint8_t* data = nullptr;

		if (stbi_is_hdr(m_Filepath.c_str()))
		{
			data = (uint8_t*)stbi_loadf(m_Filepath.c_str(), &width, &height, &channels, 4);
			m_Format = ImageFormat::RGBA32F;
		}
		else
		{
			data = stbi_load(m_Filepath.c_str(), &width, &height, &channels, 4);
			m_Format = ImageFormat::RGBA;
		}

		m_Width = width;
		m_Height = height;

		glGenTextures(1, &m_textureID);
		//AllocateMemory(m_Width * m_Height * Utils::BytesPerPixel(m_Format));
		SetData(data);

		stbi_image_free(data);

		UseTexture();
	}

	Image::Image(uint32_t width, uint32_t height, ImageFormat format, const void* data)
		: m_Width(width), m_Height(height), m_Format(format)
	{
		glGenTextures(1, &m_textureID);
		if (data)
		{
			SetData((uint8_t*)data);

			UseTexture();
		}
	}

	Image::~Image()
	{
		Release();
	}

	void Image::SetData(const void* data)
	{
		
		glBindTexture(GL_TEXTURE_2D, m_textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

	}

	void Image::UseTexture()
	{
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, m_textureID);
	}

	void Image::Release()
	{
		glDeleteTextures(1, &m_textureID);
	}

	void Image::Resize(uint32_t width, uint32_t height)
	{
		if (m_Width == width && m_Height == height)
			return;

			// TODO: max size?

		m_Width = width;
		m_Height = height;

		//Release();
	}

}