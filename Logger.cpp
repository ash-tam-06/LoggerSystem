#include "Logger.h"

Logger::Logger(const std::string& fileName) {
    logFile.open(fileName, std::ios::app); //opens file in append mode
    if(!logFile.is_open()) { //make sure file is open
        std::cerr << "Unable to open file " << fileName << std::endl;
    } else {
        std::cout << "Log file opened successfully at: " << fileName << std::endl;
    }
}

Logger::~Logger() {
    logFile.close(); //close file
}

void Logger::logInfo(const std::string& message) {
    if(logFile.is_open()) { //checks if file open
        std::cout << "[" << getCurrentTimestamp() << "] [INFO] " << message << std::endl; //print log into console

        logFile << "[" << getCurrentTimestamp() << "] [INFO] " << message << std::endl; //writes log into file
        logFile.flush(); //force the writing of any buffered data to the file
    }
}
void Logger::logWarning(const std::string& message){
    if(logFile.is_open()) {
        std::cout << "[" << getCurrentTimestamp() << "] [WARNING] " << message << std::endl; //log level WARN to console

        logFile << "[" << getCurrentTimestamp() << "] [WARNING] " << message << std::endl; //log level WARN to file
        logFile.flush();
    }
}
void Logger::logError(const std::string& message){
    if(logFile.is_open()) {
        std::cout << "[" << getCurrentTimestamp() << "] [ERROR] " << message << std::endl; //log ERROR to console

        logFile << "[" << getCurrentTimestamp() << "] [ERROR] " << message << std::endl; //log ERROR to file
        logFile.flush();
    }
}