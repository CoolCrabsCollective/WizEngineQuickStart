//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef WIZENGINECORE_DAILYFILELOGGER_H
#define WIZENGINECORE_DAILYFILELOGGER_H


#include <fstream>
#include "LoggerBase.h"

/**
 * Logger that logs its message into a specific daily date named file in a
 * specified folder
 */
class DailyFileLogger : public LoggerBase {
    const std::string directory;
    mutable std::ofstream file;
    mutable std::string curFile;

public:
    DailyFileLogger(std::string directory, LogLevel level);

    DailyFileLogger(const DailyFileLogger& logger) = delete;

    DailyFileLogger& operator=(const DailyFileLogger& logger) = delete;

    ~DailyFileLogger() override;

    void debug(const std::string &message) const override;

    void info(const std::string &message) const override;

    void warning(const std::string &message) const override;

    void error(const std::string &message) const override;

private:
    std::ofstream& getCurrentFile() const;

    static std::string getCurrentFileName();
};


#endif //WIZENGINECORE_DAILYFILELOGGER_H
