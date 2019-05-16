#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Leavs {

	class LEAVS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in client
	Application* CreateApplication();

}