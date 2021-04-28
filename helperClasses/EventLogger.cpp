// Elina Widdowson
// Programming Languages 2

#include "EventLogger.h"
#include <iostream>
#include "../Constants.h"

EventLogger::EventLogger() {
    this->addEvent(MESSAGE_GAME_HISTORY);
}

// Add event string with current time to events vector
void EventLogger::addEvent(std::string event) {
    string eventWithDate = getTime() + " " + event;
    this->events.push_back(eventWithDate);
}

// Return local time converted to a string
string EventLogger::getTime() {
    time_t timeNow;
    struct tm *timeAndDate;
    char buffer[80];
    time (&timeNow);
    timeAndDate = localtime(&timeNow);
    strftime(buffer, sizeof(buffer), "%d %m %Y %H:%M:%S", timeAndDate);
    string timeFormatted(buffer);

    return timeFormatted;
}

// Print all events stored in events vector
void EventLogger::printEvents() {
    for (int i = 0; i < this->events.size(); i++) {
        std::cout << this->events[i] << std::endl;
    }
}
