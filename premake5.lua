workspace "Sasha"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sasha/vendor/GLFW/include"
IncludeDir["Glad"] = "Sasha/vendor/Glad/include"
IncludeDir["ImGui"] = "Sasha/vendor/ImGui"

include "Sasha/vendor/GLFW"
include "Sasha/vendor/Glad"
include "Sasha/vendor/ImGui"

project "Sasha"
	location "Sasha"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "shpch.h"
	pchsource "Sasha/src/shpch.cpp"
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SH_PLATFORM_WINDOWS;",
			"SH_BUILD_DLL;",
			"GLFW_INCLUDE_NONE"
		}
	filter "configurations:Debug"
		defines "SH_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SH_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SH_DIST"
		buildoptions "/MD"
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
		"Sasha/vendor/spdlog/include;",
		"Sasha/src"
	}

	links
	{
		"Sasha"
	}

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SH_PLATFORM_WINDOWS;",
		}

	filter "configurations:Debug"
		defines "SH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SH_DIST"
		optimize "On"