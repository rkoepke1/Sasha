#pragma once

#ifdef SH_PLATFORM_WINDOWS
extern Sasha::Application* Sasha::CreateApplication();

int main(int argc, char** argv)
{
	Sasha::Log::Init();
	auto app = Sasha::CreateApplication();

	app->Run();
	delete app;
}

#endif