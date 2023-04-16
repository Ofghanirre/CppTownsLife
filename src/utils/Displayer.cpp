//
// Created by Antonin on 13/04/2023.
//

#include "Displayer.h"

bool askBoolean(Logger &logger, string question) {
    string validationInput;
    logger.logln(LogLevel::Info, question)
            << "\n"
            << "[Choice : Y | n] > ";
    cin >> validationInput;
    return (validationInput.empty() || validationInput != "n");
}
