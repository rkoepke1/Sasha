#include <Sasha.h>
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