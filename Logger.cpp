//
// Created by Asmita Tamang on 5/21/25.
//

#include "Logger.h"

Logger::Logger(const std::string& fileName) {
    logFile.open(fileName, std::ios::app);
    if(!logFile.is_open()) {
        std::cerr << "Unable to open file " << fileName << std::endl;
    }
}

Logger::~Logger() {
    logFile.close();
}

void Logger::logInfo(const std::string& message) {
    if(logFile.is_open()) {
        std::cout << "[" << getCurrentTimestamp() << "] [INFO] " << message << std::endl;

        logFile << "[" << getCurrentTimestamp() << "] [INFO] " << message << std::endl;
        logFile.flush();
    }
}
void Logger::logWarning(const std::string& message){
    if(logFile.is_open()) {
        std::cout << "[" << getCurrentTimestamp() << "] [WARNING] " << message << std::endl;

        logFile << "[" << getCurrentTimestamp() << "] [WARNING] " << message << std::endl;
        logFile.flush();
    }
}
void Logger::logError(const std::string& message){
    if(logFile.is_open()) {
        std::cout << "[" << getCurrentTimestamp() << "] [ERROR] " << message << std::endl;

        logFile << "[" << getCurrentTimestamp() << "] [ERROR] " << message << std::endl;
        logFile.flush();
    }
}