//
// Created by Alexander Winter on 2022-02-10.
//

#include "logging/DateTimeLoggerWrapper.h"

#include <utility>
#include <ctime>
#include <iomanip>
#include <sstream>

DateTimeLoggerWrapper::DateTimeLoggerWrapper(Logger *logger)
        : logger(std::shared_ptr<Logger>(logger)), format("[%Y-%m-%d %H:%M:%S]") {}

DateTimeLoggerWrapper::DateTimeLoggerWrapper(Logger *logger, const char* format)
        : logger(std::shared_ptr<Logger>(logger)), format(format) {}


DateTimeLoggerWrapper::DateTimeLoggerWrapper(std::shared_ptr<Logger> logger)
        : logger(std::move(logger)), format("[%Y-%m-%d %H:%M:%S]") {}

DateTimeLoggerWrapper::DateTimeLoggerWrapper(std::shared_ptr<Logger> logger, const char* format)
: logger(std::move(logger)), format(format) {}

void DateTimeLoggerWrapper::debug(const std::string& message) const {
    logger->debug(getDateTime() + " " + message);
}

void DateTimeLoggerWrapper::info(const std::string& message) const {
    logger->info(getDateTime() + " " + message);
}

void DateTimeLoggerWrapper::warning(const std::string& message) const {
    logger->warning(getDateTime() + " " + message);
}

void DateTimeLoggerWrapper::error(const std::string& message) const {
    logger->error(getDateTime() + " " + message);
}

LogLevel DateTimeLoggerWrapper::getLogLevel() const {
    return logger->getLogLevel();
}

void DateTimeLoggerWrapper::setLogLevel(LogLevel level) {
    logger->setLogLevel(level);
}

std::string DateTimeLoggerWrapper::getDateTime() const {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, format);
    return oss.str();
}
