//
// Created by Antonin on 13/04/2023.
//

#ifndef TEST1_DISPLAYER_H
#define TEST1_DISPLAYER_H

#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include "../Logger/Logger.h"

using namespace std;


inline auto displayer_identity = [](const auto& str) { return str; };
inline auto displayer_truth = [](const auto v){return true;};

template<typename T>
string join(const vector<T> &vec, const string &delimiter, function<string(T)> mappingFunction, bool enumerate) {
    ostringstream ss;

    for (size_t i = 0; i < vec.size(); i++) {
        if (enumerate) ss << "[" << i << "] : ";
        ss << mappingFunction(vec[i]);
        if (i < vec.size() - 1) {
            ss << delimiter;
        }
    }
    return ss.str();
}

template<typename T>
string join(const vector<T> &vec, const string &delimiter, function<string(T)> mappingFunction) {
    return join(vec, delimiter, mappingFunction, false);
}

bool askBoolean(Logger& logger, string input);

template<typename T>
T prompt(Logger& logger, string question, function<T(string)> mappingFunction, function<bool(T)> predicate, bool validation) {
    string input;
    string validationInput;
    T value;
    do {
        logger.logln(LogLevel::Info, "Input")
            << "[" + question + "] > ";
        cin >> input;
        value = mappingFunction(input);
        if (!predicate(value)) {
            logger.logln(LogLevel::Warning, "Wrong value!");
            continue;
        }
        if (!validation) break;
    } while (!predicate(value) || !askBoolean(logger, "Do you confirm " + input + "?"));
    return value;
}

template<typename T>
T prompt(Logger& logger, string question, function<T(string)> mappingFunction, function<bool(T)> predicate) {
    return prompt(logger, question, mappingFunction, predicate, false);
}


template<typename T>
T prompt(Logger& logger, string question, function<T(string)> mappingFunction) {
    return prompt(logger, question, mappingFunction, [](T value){return true;});
}

template<typename T>
T choose(Logger& logger, string question, vector<T> &choices, function<string(T)> mappingFunction, bool validation) {
    string inputChoice;
    T result;
    logger.logln(LogLevel::Info, "Select")
            << question << endl
            << "Choices possible:" << endl
            << join<T>(choices, "  |  ", mappingFunction, true) << endl;
    int value;
    do {
        value = prompt<int>(logger, "Select : number", [](string value){return std::stoi(value);}, [](int value){return true;}, false);
        while (value < 0 || value >= choices.size()) {
            logger.logln(LogLevel::Warning, "Wrong input, need to be between [0, " + std::to_string(choices.size()) + "[!");
            value = prompt<int>(logger, "Select : number", [](string value){return std::stoi(value);}, [](int value){return true;}, false);
        }
        if (!validation) break;
    } while (!askBoolean(logger, "Do you confirm " + std::to_string(value) + "?"));

    return choices[value];
}

template<typename T>
T choose(Logger& logger, string question, vector<T> &choices, function<string(T)> mappingFunction) {
    return choose(logger, question, choices, mappingFunction, false);
}
#endif //TEST1_DISPLAYER_H
