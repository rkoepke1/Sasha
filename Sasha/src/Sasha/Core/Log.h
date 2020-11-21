#pragma once
#include "Core.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Sasha {

	class SASHA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
// Core Log macros
#define SH_CORE_TRACE(...)	::Sasha::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SH_CORE_INFO(...)	::Sasha::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SH_CORE_WARN(...)	::Sasha::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SH_CORE_ERROR(...)	::Sasha::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SH_CORE_FATAL(...)	::Sasha::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define SH_CLIENT_TRACE(...) ::Sasha::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SH_CLIENT_INFO(...)  ::Sasha::Log::GetClientLogger()->info(__VA_ARGS__)
#define SH_CLIENT_WARN(...)  ::Sasha::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SH_CLIENT_ERROR(...) ::Sasha::Log::GetClientLogger()->error(__VA_ARGS__)
#define SH_CLIENT_FATAL(...) ::Sasha::Log::GetClientLogger()->fatal(__VA_ARGS__)

