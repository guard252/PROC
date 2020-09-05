#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#define LOGE(...)		Logger::GetLogger()->error(__VA_ARGS__);
#define LOGW(...)	Logger::GetLogger()->warn(__VA_ARGS__);
#define LOGI(...)	Logger::GetLogger()->info(__VA_ARGS__);
#define LOGT(...)	Logger::GetLogger()->trace(__VA_ARGS__);

class Logger
{
public:
	static void Init(std::string name);

	static std::shared_ptr<spdlog::logger> GetLogger() { return s_logger; }
private:
	static std::shared_ptr<spdlog::logger> s_logger;
};
