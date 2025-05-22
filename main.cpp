#include <sstream>
#include "Logger.h"


int main() {
    Logger logger("log.txt");
    logger.logInfo("This is logging info!");
    logger.logWarning("This is a warning!");
    logger.logError("This is a error!");
    return 0;
}
