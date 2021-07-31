#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace pt
{
std::shared_ptr<spdlog::logger> Log::s_logger;

void Log::init()
{
	auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	s_logger = std::make_shared<spdlog::logger>("App", sink);
	s_logger->set_pattern("%^[%T] %v%$");
	s_logger->set_level(spdlog::level::trace);
	s_logger->flush_on(spdlog::level::trace);
}
}