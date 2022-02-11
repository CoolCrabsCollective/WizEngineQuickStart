//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef TEMPLATESFMLPROJECT_STDOUTLOGGER_H
#define TEMPLATESFMLPROJECT_STDOUTLOGGER_H

#include "LoggerBase.h"

/**
 * Simple logger that outputs its log to STDOUT
 */
class StdOutLogger : public LoggerBase {
    bool useStderr = false;

public:
    explicit StdOutLogger(LogLevel logLevel);

    ~StdOutLogger() override = default;

    void debug(const std::string& message) const override;

    void info(const std::string& message) const override;

    void warning(const std::string& message) const override;

    void error(const std::string& message) const override;

    bool useStderrOnError() const;

    void setUseStderrOnError(bool useStderrOnError);
};


#endif //TEMPLATESFMLPROJECT_STDOUTLOGGER_H
