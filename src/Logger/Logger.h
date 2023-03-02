//
// Created by ofgha on 02/03/2023.
//

#ifndef TEST1_LOGGER_H
#define TEST1_LOGGER_H

#include <ostream>
#include <iostream>

enum class LogLevel {
    Info,
    Warning,
    Error,
};
inline std::string getLogLevelRepr(LogLevel l) {
    switch (l) {
        case LogLevel::Info : return "INFO";
        case LogLevel::Warning : return "WARN";
        case LogLevel::Error : return "ERROR";
        default: return "UNKNOWN";
    }
}

class Logger {
public:
    explicit Logger(const std::string context) : _context{context} {}

public:
    std::ostream& log(std::ostream& stream, LogLevel logtype, std::string message);

    std::ostream& log(LogLevel logtype, std::string message) {
        return log(std::cout, logtype, message);
    }

    std::ostream& logln(std::ostream& stream, LogLevel logtype, std::string message);

    std::ostream& logln(LogLevel logtype, std::string message) {
        return logln(std::cout, logtype, message);
    }
private:
    const std::string _context;
};


#endif //TEST1_LOGGER_H
