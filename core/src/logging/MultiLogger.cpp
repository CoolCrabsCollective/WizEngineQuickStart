//
// Created by Alexander Winter on 2022-02-10.
//

#include "logging/MultiLogger.h"

#include <utility>
#include "logging/Logger.h"

MultiLogger::MultiLogger(const std::vector<Logger*>& loggers)
    : loggers() {
    for(Logger* logger : loggers)
        this->loggers.push_back(std::shared_ptr<Logger>(logger));
}

MultiLogger::MultiLogger(std::vector<std::shared_ptr<Logger>> loggers)
    : loggers(std::move(loggers)) {}

void MultiLogger::debug(const std::string& message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->debug(message);
}

void MultiLogger::info(const std::string &message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->info(message);
}

void MultiLogger::warning(const std::string &message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->warning(message);
}

void MultiLogger::error(const std::string &message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->error(message);
}

LogLevel MultiLogger::getLogLevel() const {

    if(loggers.empty())
        return LogLevel::NONE;

    return loggers[0]->getLogLevel();
}

void MultiLogger::setLogLevel(LogLevel level) {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->setLogLevel(level);
}

