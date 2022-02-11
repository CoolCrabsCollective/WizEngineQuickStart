//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef WIZENGINECORE_DATETIMELOGGERWRAPPER_H
#define WIZENGINECORE_DATETIMELOGGERWRAPPER_H


#include "Logger.h"
#include <memory>

/**
 * Logger which wraps another logger to prepend to its message the current date
 * and time
 */
class DateTimeLoggerWrapper : public Logger {
    std::shared_ptr<Logger> logger;
    const char* format;

public:
    DateTimeLoggerWrapper(Logger* logger);

    DateTimeLoggerWrapper(Logger* logger, const char* format);

    DateTimeLoggerWrapper(std::shared_ptr<Logger> logger);

    DateTimeLoggerWrapper(std::shared_ptr<Logger> logger, const char* format);

    ~DateTimeLoggerWrapper() override = default;

    void debug(const std::string &message) const override;

    void info(const std::string &message) const override;

    void warning(const std::string &message) const override;

    void error(const std::string &message) const override;

    LogLevel getLogLevel() const override;

    void setLogLevel(LogLevel level) override;

private:
    std::string getDateTime() const;
};


#endif //WIZENGINECORE_DATETIMELOGGERWRAPPER_H
