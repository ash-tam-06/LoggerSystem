#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

class Logger {
private:
    std::ofstream logFile;
    std::string getCurrentTimestamp() { //function to creat a timestamp
        const time_t now = time(nullptr);
        tm* timeinfo = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
        return {timestamp};
    }
public:

    explicit Logger(const std::string& fileName);//constructor to open file in append mode
    ~Logger(); //deconstructor to close file

    void logInfo(const std::string& message); //log a message for log level INFO
    void logWarning(const std::string& message); //log a message for log level WARN
    void logError(const std::string& message); //log a message for log level ERROR

};


#endif //LOGGER_H
