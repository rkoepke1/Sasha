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
IncludeDir["glm"] = "Sasha/vendor/glm"


include "Sasha/vendor/GLFW"
include "Sasha/vendor/Glad"
include "Sasha/vendor/ImGui"


project "Sasha"
	location "Sasha"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "shpch.h"
	pchsource "Sasha/src/shpch.cpp"
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"

	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"GLFW",
		"Glad", 
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SH_PLATFORM_WINDOWS",
			"SH_BUILD_DLL",
			"GFLW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "SH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SH_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Sasha/vendor/spdlog/include",
		"Sasha/src",
		"Sasha/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Sasha"
	}

	filter "system:Windows"
		systemversion "latest"

		defines
		{
			"SH_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SH_DIST"
		runtime "Release"
		optimize "on"