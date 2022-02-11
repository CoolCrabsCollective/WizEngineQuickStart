//
// Created by Alexander Winter on 2022-02-10.
//

#include "logging/LoggerBase.h"

LoggerBase::LoggerBase(LogLevel logLevel) : logLevel(logLevel) {

}

LogLevel LoggerBase::getLogLevel() const {
    return logLevel;
}

void LoggerBase::setLogLevel(LogLevel level) {
    this->logLevel = level;
}

