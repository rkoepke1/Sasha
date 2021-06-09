#pragma once
#include "Sasha/Core/Input.h"

namespace Sasha {
	class   WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImp(int button)  override;
		virtual std::pair<float, float>GetMousePositionImp() override; 
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}

