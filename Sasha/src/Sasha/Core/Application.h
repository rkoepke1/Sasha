
#pragma once
#include "shpch.h"
#include "Core.h"
#include "LayerStack.h"
#include "Sasha/Events/Event.h"
#include "Window.h"
//#include "Sasha/Events/ApplicationEvent.h"
#include <Sasha/ImGui/ImGuiLayer.h>


namespace Sasha {
	class   Application
	{
	public:

		Application(const std::string& name = "Sasha App");
		virtual ~Application();
		
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushLayerOverlay(Layer* layer);
		void Close();


		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
		void Run();
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	// defined in client
	Application* CreateApplication();

}
	

