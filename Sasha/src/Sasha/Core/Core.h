#pragma once


#ifdef SH_ENABLE_ASSERTS
	#define SH_ASSERT(x, ...) {if(!(x)){SH_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define SH_CORE_ASSERT(x, ...) {if(!(x)){SH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define SH_ASSERT(x, ...)
	#define SH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)
#define SH_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#define GLFW_INCLUDE_NONE
