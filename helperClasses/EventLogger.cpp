// Elina Widdowson
// Programming Languages 2

#include "EventLogger.h"
#include <iostream>
#include "../Constants.h"

EventLogger::EventLogger() {
    this->addEvent(MESSAGE_GAME_HISTORY);
}

void EventLogger::addEvent(std::string event) {
    this->events.push_back(event);
}

void EventLogger::printEvents() {
    for (int i = 0; i < this->events.size(); i++) {
        std::cout << this->events[i] << std::endl;
    }
}
