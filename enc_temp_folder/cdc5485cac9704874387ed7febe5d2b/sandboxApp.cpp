#include <Sasha.h>
class ExampleLayer :public Sasha::Layer {
public:
	ExampleLayer() 
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Sasha::Input::IsKeyPressed(Sasha::Key::Tab))
			SH_CORE_INFO("TAB KEY IS PRESSED!");
	}

	void OnEvent(Sasha::Event& event) override
	{
		//SH_CORE_INFO("{0}", event);
	}
};
class Sandbox : public Sasha::Application 
{
public:
	Sandbox()
	{
	
	}
	~Sandbox()
	{

	}

};

Sasha::Application* Sasha::CreateApplication()
{
	return new Sandbox();
}