//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef WIZENGINECORE_MULTILOGGER_H
#define WIZENGINECORE_MULTILOGGER_H


#include <memory>
#include <vector>
#include <list>
#include "Logger.h"

/**
 * Logger implementation that delegates its logging to a list of logger for
 * simultaneous logging on multiple logger implementations
 */
class MultiLogger : public Logger {
    std::vector<std::shared_ptr<Logger>> loggers;

public:
    MultiLogger(const std::vector<Logger*>& loggers);

    MultiLogger(std::vector<std::shared_ptr<Logger>> loggers);

    ~MultiLogger() override = default;

    void debug(const std::string &message) const override;

    void info(const std::string &message) const override;

    void warning(const std::string &message) const override;

    void error(const std::string &message) const override;

    LogLevel getLogLevel() const override;

    void setLogLevel(LogLevel level) override;
};


#endif //WIZENGINECORE_MULTILOGGER_H
