#pragma once

#include <spdlog/spdlog.h>

namespace pt
{
	class Log
	{
	public:
		template <typename ...Args>
		static void info(Args&&... args)
		{
			s_logger->info(std::forward<Args>(args)...);
		}

		template <typename ...Args>
		static void trace(Args&&... args)
		{
			s_logger->trace(std::forward<Args>(args)...);
		}

		template <typename ...Args>
		static void warn(Args&&... args)
		{
			s_logger->warn(std::forward<Args>(args)...);
		}

		template <typename ...Args>
		static void error(Args&&... args)
		{
			s_logger->error(std::forward<Args>(args)...);
		}

		static std::shared_ptr<spdlog::logger>& get() { return s_logger; }

		static void init();

	private:
		static std::shared_ptr<spdlog::logger> s_logger;
	};
}
