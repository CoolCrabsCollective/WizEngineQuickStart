//
// Created by Alexander Winter on 2022-02-10.
//

#include "logging/StdOutLogger.h"

#include <iostream>

StdOutLogger::StdOutLogger(LogLevel logLevel) : LoggerBase(logLevel) {}

void StdOutLogger::debug(const std::string& message) const {
    if(logLevel <= DEBUG)
        std::cout << message << std::endl;
}

void StdOutLogger::info(const std::string& message) const {
    if(logLevel <= INFO)
        std::cout << message << std::endl;
}

void StdOutLogger::warning(const std::string& message) const {
    if(logLevel <= WARNING)
        std::cout << message << std::endl;
}

void StdOutLogger::error(const std::string& message) const {
    if(logLevel <= ERROR) {
        if(useStderr)
            std::cerr << message << std::endl;
        else
            std::cout << message << std::endl;
    }
}

bool StdOutLogger::useStderrOnError() const {
    return useStderr;
}

void StdOutLogger::setUseStderrOnError(bool useStderrOnError) {
    this->useStderr = useStderrOnError;
}

