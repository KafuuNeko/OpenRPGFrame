#ifndef LOGGER_H_
#define LOGGER_H_

#include <spdlog/spdlog.h>

namespace logger {

extern std::shared_ptr<spdlog::logger> kDb;

void InitLogger();

} // logger

#endif