#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Leavs {

	class LEAVS_API Log
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

// Core log macros
#define LEAVS_CORE_TRACE(...)	::Leavs::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LEAVS_CORE_INFO(...)	::Leavs::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LEAVS_CORE_WARN(...)	::Leavs::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LEAVS_CORE_ERROR(...)	::Leavs::Log::GetCoreLogger()->error(__VA_ARGS__
#define LEAVS_CORE_FATAL(...)	::Leavs::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LEAVS_TRACE(...)		::Leavs::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LEAVS_INFO(...)			::Leavs::Log::GetClientLogger()->info(__VA_ARGS__)
#define LEAVS_WARN(...)			::Leavs::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LEAVS_ERROR(...)		::Leavs::Log::GetClientLogger()->error(__VA_ARGS__
#define LEAVS_FATAL(...)		::Leavs::Log::GetClientLogger()->fatal(__VA_ARGS__)