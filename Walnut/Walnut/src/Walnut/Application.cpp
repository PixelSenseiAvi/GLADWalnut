#include "Application.h"

#include <iostream> //TODO: Replace cout with spdlog

namespace Walnut {
	
	Application* Application::s_Instance = nullptr;


	Application::Application(const std::string& _name, const uint32_t& _width, const uint32_t& _height)
		:m_name(_name), m_width(_width), m_height(_height)
	{
		s_Instance = this;

		int initRes = Init();
		if (initRes)
			std::cout << "Initiliased successfully" << std::endl;
		else
			std::cout << "Initialization Failed" << std::endl;

	}

	Application::~Application()
	{
		Terminate();
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow* window);

	int Application::Init()
	{
		// glfw: initialize and configure
		if (!glfwInit()) { std::cout << ("GLFW Init Failed"); return -1; }
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), NULL, NULL);
		if (!m_window)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		//Initialize IMGUI Layer
		Window win;
		win.window = m_window;
		win.width = m_width;
		win.height = m_height;
		m_imguiLayer = new ImGuiLayer(&win);
		//TODO: init Imgui
		m_imguiLayer->OnAttach();
		
		return 1;
	}

	void Application::Run()
	{

		while (!glfwWindowShouldClose(m_window))
		{

			m_imguiLayer->Begin();
			// input
			// -----
			processInput(m_window);

			// render
			// ------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
			glfwSwapBuffers(m_window);
			glfwPollEvents();

			m_imguiLayer->Run();
			
			m_imguiLayer->End();
		}
	}

	void Application::Terminate()
	{
		m_imguiLayer->OnDetach();
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
	}

	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}
};
