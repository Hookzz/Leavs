#include "Lvpch.h"
#include "Application.h"

#include "Leavs/Events/ApplicationEvent.h"
#include "Leavs/Log.h"

namespace Leavs {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		LEAVS_TRACE(e);
		while (true)
		{

		}
	}
}