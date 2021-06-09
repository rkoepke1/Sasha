#pragma once

#include "Sasha/Core/Layer.h"
#include "Sasha/Core/Core.h"

#include "Sasha/Events/ApplicationEvent.h"
#include "Sasha/Events/KeyEvent.h"
#include "Sasha/Events/MouseEvent.h"

namespace Sasha {

	class   ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();



	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}

