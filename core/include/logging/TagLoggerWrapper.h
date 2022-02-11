//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef WIZENGINECORE_TAGLOGGERWRAPPER_H
#define WIZENGINECORE_TAGLOGGERWRAPPER_H


#include "Logger.h"
#include <memory>

/**
 * Logger which wraps another logger to prepend to its message the LogLevel of
 * its messages
 */
class TagLoggerWrapper : public Logger {
    std::shared_ptr<Logger> logger;

public:
    TagLoggerWrapper(Logger* logger);

    TagLoggerWrapper(std::shared_ptr<Logger> logger);

    ~TagLoggerWrapper() override = default;

    void debug(const std::string &message) const override;

    void info(const std::string &message) const override;

    void warning(const std::string &message) const override;

    void error(const std::string &message) const override;

    LogLevel getLogLevel() const override;

    void setLogLevel(LogLevel level) override;
};


#endif //WIZENGINECORE_TAGLOGGERWRAPPER_H
