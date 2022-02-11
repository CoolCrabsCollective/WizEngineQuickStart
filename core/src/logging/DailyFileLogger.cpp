//
// Created by Alexander Winter on 2022-02-10.
//

#include <ctime>
#include <iomanip>
#include <sstream>
#include <util/FileUtil.h>
#include <util/StringUtil.h>
#include "logging/DailyFileLogger.h"


DailyFileLogger::DailyFileLogger(std::string directory, LogLevel level)
: LoggerBase(level), directory(std::move(directory) + (ends_with(directory, "/") ? "" : "/")) {

}

DailyFileLogger::~DailyFileLogger() {
    file.close();
}

void DailyFileLogger::debug(const std::string& message) const {
    if(logLevel <= DEBUG)
        getCurrentFile() << message << std::endl;
}

void DailyFileLogger::info(const std::string& message) const {
    if(logLevel <= INFO)
        getCurrentFile() << message << std::endl;
}

void DailyFileLogger::warning(const std::string& message) const {
    if(logLevel <= WARNING)
        getCurrentFile() << message << std::endl;
}

void DailyFileLogger::error(const std::string& message) const {
    if(logLevel <= ERROR)
        getCurrentFile() << message << std::endl;
}

std::ofstream& DailyFileLogger::getCurrentFile() const {
    std::string presentFile = getCurrentFileName();
    if(presentFile != curFile)
    {
        file.close();
        curFile = presentFile;

#ifndef OS_SWITCH
        if(ensure_directory(directory) != 0)
            throw std::runtime_error("Failed to create directory " + directory + " for logging");
#endif

        std::string fileName = directory + curFile;
        file.open(fileName, std::ios::out | std::ios::app);

#ifndef OS_SWITCH
        if(file.fail())
            throw std::runtime_error("Failed to open file " + fileName + " for logging");
#endif
    }

    return file;
}

std::string DailyFileLogger::getCurrentFileName() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d") << ".log";
    return oss.str();
}


