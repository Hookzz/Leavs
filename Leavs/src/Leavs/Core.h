#pragma once

#ifdef LEAVS_PLATFORM_WINDOWS
	#ifdef LEAVS_BUILD_DLL
		#define LEAVS_API __declspec(dllexport)
	#else
		#define LEAVS_API __declspec(dllimport)
	#endif // LV_BUILD_DLL
#else
	#error Leavs only support Windows!
#endif // LV_PLATFORM_WINDOWS

#define BIT(x) (1 << x)