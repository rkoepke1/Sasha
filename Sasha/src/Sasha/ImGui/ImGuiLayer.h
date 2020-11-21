#pragma once

#include "Sasha/Core/Layer.h"

#include "Sasha/Events/ApplicationEvent.h"
#include "Sasha/Events/KeyEvent.h"
#include "Sasha/Events/MouseEvent.h"

namespace Sasha {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}

class ImGuiLayer
{
};
