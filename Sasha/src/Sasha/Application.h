#pragma once
#include "Core.h"

namespace Sasha {
	class SASHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// defined in client
	Application* CreateApplication();
}
	

