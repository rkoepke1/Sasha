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

#ifdef SH_ENABLE_ASSERTS
	#define SH_ASSERT(x, ...) {if(!(x)){SH_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define SH_CORE_ASSERT(x, ...) {if(!(x)){SH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define SH_ASSERT(x, ...)
	#define SH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)

namespace Sasha {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}