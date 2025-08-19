#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include <vec2.hpp>

namespace FlyEngine
{
	class Window
	{
	private:
		GLFWwindow* window;
		int windowWidth;
		int windowHeight;
		std::string windowTitle;
		bool shouldClose;

		static int windowCount;

		void CreateWindow();

	public:
		Window(int width, int height, std::string title);
		Window(std::string title);
		~Window();

		std::string GetWindowName();
		glm::vec2 GetWindowSize();
		GLFWwindow* GetWindow();

		static int GetWindowCount();
	};

}
#endif // !