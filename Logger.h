//
// Created by Asmita Tamang on 5/21/25.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

class Logger {
private:
    std::ofstream logFile;

    static std::string getCurrentTimestamp() {
        const time_t now = time(nullptr);
        tm* timeinfo = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
        return {timestamp};
    }
public:
    explicit Logger(const std::string& fileName);
    ~Logger();

    // void set_level(LogLevel level);

    void logInfo(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);

};


#endif //LOGGER_H
