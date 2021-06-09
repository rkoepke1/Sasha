#pragma once
#include "Sasha/Renderer/GraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


struct GLFWwindow;
namespace Sasha {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* WindowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}