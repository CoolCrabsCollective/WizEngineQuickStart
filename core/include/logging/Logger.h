//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef TEMPLATESFMLPROJECT_LOGGER_H
#define TEMPLATESFMLPROJECT_LOGGER_H

#include <string>

enum LogLevel { DEBUG, INFO, WARNING, ERROR, NONE };

/**
 * Abstract definition of a logger for logging purposes. Provides an interface
 * for logging independent of implementation.
 */
class Logger {
public:
    virtual ~Logger() = default;

    virtual void debug(const std::string& message) const = 0;
    virtual void info(const std::string& message) const = 0;
    virtual void warning(const std::string& message) const = 0;
    virtual void error(const std::string& message) const = 0;

    virtual LogLevel getLogLevel() const = 0;
    virtual void setLogLevel(LogLevel level) = 0;
};


#endif //TEMPLATESFMLPROJECT_LOGGER_H
