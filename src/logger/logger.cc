#include "logger.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace logger {

constexpr auto LOG_LEVEL = spdlog::level::debug;

static std::shared_ptr<spdlog::logger> kDb;

void InitLogger() {
    kDb = spdlog::stdout_color_mt("database");
    kDb->set_level(LOG_LEVEL); 
}

} // logger