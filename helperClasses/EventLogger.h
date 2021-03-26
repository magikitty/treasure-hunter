// Elina Widdowson
// Programming Languages 2

#include <vector>
#include <string>

#ifndef TREASURE_HUNTER_EVENTLOGGER_H
#define TREASURE_HUNTER_EVENTLOGGER_H


class EventLogger {
private:
    std::vector<std::string> events;
public:
    void addEvent(std::string event);
    void printEvents();
};


#endif //TREASURE_HUNTER_EVENTLOGGER_H
