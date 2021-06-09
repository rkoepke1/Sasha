#include <Sasha.h>
class ExampleLayer :public Sasha::Layer {
public:
	ExampleLayer() 
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
	
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
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}

};

Sasha::Application* Sasha::CreateApplication()
{
	return new Sandbox();
}