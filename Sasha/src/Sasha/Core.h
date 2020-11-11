#pragma once

#ifdef SH_PLATFORM_WINDOWS
	#ifdef SH_BUILD_DLL
		#define SASHA_API __declspec(dllexport)
	#else
		#define SASHA_API __declspec(dllimport)
	#endif
#else
	#error Sasha only supports Windows!
#endif