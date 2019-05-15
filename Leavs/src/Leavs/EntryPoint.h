#pragma once

#ifdef LEAVS_PLATFORM_WINDOWS

extern Leavs::Application* Leavs::CreateApplication();

int main(int argc, char** argv)
{
	Leavs::Log::Init();
	LEAVS_CORE_WARN("Initialized Log !");
	int a = 5;
	LEAVS_INFO("Hi var = {0}", a);
	auto app = Leavs::CreateApplication();
	app->Run();
	delete app;
}

#endif // LEAVS_PLATFORM_WINDOWS