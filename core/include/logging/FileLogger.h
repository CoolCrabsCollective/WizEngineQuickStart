//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef WIZENGINECORE_FILELOGGER_H
#define WIZENGINECORE_FILELOGGER_H

#include <fstream>
#include "LoggerBase.h"

/**
 * Simple Logger implementation that writes its log to a single specified file
 */
class FileLogger : public LoggerBase {
private:
    mutable std::ofstream filePointer;

public:
    FileLogger(const std::string& filePath, LogLevel logLevel);

    FileLogger(const FileLogger& logger) = delete;

    FileLogger& operator=(const FileLogger& logger) = delete;

    ~FileLogger() override;

    void debug(const std::string &message) const override;

    void info(const std::string &message) const override;

    void warning(const std::string &message) const override;

    void error(const std::string &message) const override;
};


#endif //WIZENGINECORE_FILELOGGER_H
