#include "Logger.h"


std::shared_ptr<spdlog::logger> Logger::s_logger;

void Logger::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	s_logger = spdlog::stdout_color_mt("ProcGen");
	s_logger->set_level(spdlog::level::trace);
}
