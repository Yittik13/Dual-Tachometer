#ifndef GAUGES_H
#define GAUGES_H

#include "Engine.hpp"

class Gauges {
public:
    
    void printCurrentRPM(Engine *engine);
    void printCorrectRPM(Engine *engine);
    void printCurrentVelocity(Engine *engine);
    void printCurrentGear(Engine *engine);
    void printClutchStatus(Engine *engine);
    void printRedlineStatus(Engine *engine);
    void printLimitToggle(Engine *engine);
    
};

#endif
