//
// Created by Alexander Winter on 2022-02-10.
//

#include "logging/FileLogger.h"

FileLogger::FileLogger(const std::string& filePath, LogLevel logLevel) : LoggerBase(logLevel) {
    filePointer.open(filePath, std::ios::out | std::ios::app);
}

FileLogger::~FileLogger() {
    filePointer.close();
}

void FileLogger::debug(const std::string& message) const {
    if(logLevel <= DEBUG)
        filePointer << message << std::endl;
}

void FileLogger::info(const std::string& message) const {
    if(logLevel <= INFO)
        filePointer  << message << std::endl;
}

void FileLogger::warning(const std::string& message) const {
    if(logLevel <= WARNING)
        filePointer << message << std::endl;
}

void FileLogger::error(const std::string& message) const {
    if(logLevel <= ERROR)
        filePointer  << message << std::endl;
}

