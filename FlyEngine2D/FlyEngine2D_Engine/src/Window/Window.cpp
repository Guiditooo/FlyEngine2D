#include "Window.h"

namespace FlyEngine
{

	const int INITIAL_HEIGHT = 720;
	const int INITIAL_WIDTH = 1080;
	int Window::windowCount = 0;

	Window::Window(int width, int height, std::string title)
	{
		windowWidth = width;
		windowHeight = height;
		windowTitle = title;

		CreateWindow();
	}

	Window::Window(std::string title)
	{
		windowWidth = INITIAL_WIDTH;
		windowHeight = INITIAL_HEIGHT;
		windowTitle = title;

		CreateWindow();
	}

	Window::~Window()
	{
		windowCount--;
	}

	std::string Window::GetWindowName()
	{
		return windowTitle;
	}

	glm::vec2 Window::GetWindowSize()
	{
		return glm::vec2(windowWidth, windowHeight);
	}

	GLFWwindow* Window::GetWindow()
	{
		return window;
	}

	void Window::CreateWindow()
	{
		if (!glfwInit())
		{
			std::cout << "GLFW not initialized!" << std::endl;
			exit(EXIT_FAILURE);
		}

		if (windowWidth <= 0 || windowHeight <= 0) 
		{
			windowWidth = 800;
			windowHeight = 600;
		}

		const char* auxName = windowTitle.c_str();
		window = glfwCreateWindow(windowWidth, windowHeight, auxName, NULL, NULL);

		if (!window)
		{
			std::cout << "Error on WINDOW initialization" << std::endl;
			const char* errorDesc;
			glfwGetError(&errorDesc);
			std::cerr << "Failed to create window: " << errorDesc << std::endl;
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		windowCount++;
		int a = 0;
		
	}

	int Window::GetWindowCount()
	{
		return windowCount;
	}

}