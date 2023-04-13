//
// Created by ofgha on 02/03/2023.
//

#include "Logger.h"

std::ostream &Logger::log(std::ostream &stream, LogLevel logtype, std::string message) {
    stream << "[" + getLogLevelRepr(logtype) + "] : " + _context + "\t<*>\t" << message;
    return stream;
}

std::ostream &Logger::logln(std::ostream &stream, LogLevel logtype, std::string message)  {
    stream << "[" + getLogLevelRepr(logtype) + "] : " + _context + "\t<*>\t" << message << std::endl;
    return stream;
}
