#pragma once

#ifdef LEAVS_PLATFORM_WINDOWS

extern Leavs::Application* Leavs::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Leavs::CreateApplication();
	app->Run();
	delete app;
}

#endif // LV_PLATFORM_WINDOWS