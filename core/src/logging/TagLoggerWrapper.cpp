//
// Created by Alexander Winter on 2022-02-10.
//

#include "logging/TagLoggerWrapper.h"

#include <utility>
#include <iomanip>

TagLoggerWrapper::TagLoggerWrapper(Logger* logger)
        : logger(std::shared_ptr<Logger>(logger)) {}

TagLoggerWrapper::TagLoggerWrapper(std::shared_ptr<Logger> logger)
    : logger(std::move(logger)) {}

void TagLoggerWrapper::debug(const std::string& message) const {
    logger->debug("[DEBUG] " + message);
}

void TagLoggerWrapper::info(const std::string& message) const {
    logger->info("[INFO] " + message);
}

void TagLoggerWrapper::warning(const std::string& message) const {
    logger->warning("[WARNING] " + message);
}

void TagLoggerWrapper::error(const std::string& message) const {
    logger->error("[ERROR] " + message);
}

LogLevel TagLoggerWrapper::getLogLevel() const {
    return logger->getLogLevel();
}

void TagLoggerWrapper::setLogLevel(LogLevel level) {
    logger->setLogLevel(level);
}

