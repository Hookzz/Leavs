-- premake5.lua
workspace "Leavs"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Leavs"
	location "Leavs"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Lvpch.h"
	pchsource "Leavs/src/Lvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LEAVS_PLATFORM_WINDOWS",
			"LEAVS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LV_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LV_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "LV_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Leavs/vendor/spdlog/include",
		"Leavs/src"
	}

	links
	{
		"Leavs"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LEAVS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LV_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LV_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "LV_DIST"
		optimize "On"