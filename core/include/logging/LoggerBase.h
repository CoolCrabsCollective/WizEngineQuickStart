//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef WIZENGINECORE_LOGGERBASE_H
#define WIZENGINECORE_LOGGERBASE_H

#include "Logger.h"

/**
 * Base class for logger that implements storage for the log level without
 * specifying the way logging happens
 */
class LoggerBase : public Logger {
protected:
    LogLevel logLevel;

public:
    explicit LoggerBase(LogLevel logLevel);

    ~LoggerBase() override = default;

    LogLevel getLogLevel() const override;

    void setLogLevel(LogLevel level) override;
};


#endif //WIZENGINECORE_LOGGERBASE_H
