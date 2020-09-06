#include "Logger.h"


std::shared_ptr<spdlog::logger> Logger::s_logger;

void Logger::Init(std::string name)
{
	s_logger = spdlog::stdout_color_mt(name);
	spdlog::set_pattern("%^[%T] %n: %v%$");
	//spdlog::register_logger(s_logger);

	s_logger->set_level(spdlog::level::trace);		
	s_logger->flush_on(spdlog::level::trace);


	//spdlog::register_logger(s_logger);

}
