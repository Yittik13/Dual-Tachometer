#include <ncurses.h>

#include "Gauges.hpp"

#define Y_LIMITING 11
#define Y_VELOCITY 13
#define Y_CURRENT_RPM 14
#define Y_CORRECT_RPM 15
#define Y_CURRENT_GEAR 17
#define Y_CLUTCH_STATUS 18
#define Y_REDLINING 20

void Gauges::printCurrentRPM(Engine *engine) {
    mvprintw(Y_CURRENT_RPM, 0, "\n");
    mvprintw(Y_CURRENT_RPM, 0, "Current RPM: %d", engine -> getCurrentRPM());
}

void Gauges::printCorrectRPM(Engine *engine) {
    mvprintw(Y_CORRECT_RPM, 0, "\n");
    mvprintw(Y_CORRECT_RPM, 0, "Correct RPM: %d", engine -> getCorrectRPM());
}

void Gauges::printCurrentVelocity(Engine *engine) {
    mvprintw(Y_VELOCITY, 0, "\n");
    mvprintw(Y_VELOCITY, 0, "Current Velocity: %d", engine -> getVelocity());
}

void Gauges::printCurrentGear(Engine *engine) {
    mvprintw(Y_CURRENT_GEAR, 0, "\n");
    if (engine -> getGear() == GEAR_NEUTRAL) {
	mvprintw(Y_CURRENT_GEAR, 0, "Current Gear: Neutral", engine -> getGear());
    }
    else {
	mvprintw(Y_CURRENT_GEAR, 0, "Current Gear: %d", engine -> getGear());
    }
}

void Gauges::printClutchStatus(Engine *engine) {
    if (engine -> getClutchStatus()) {
	mvprintw(Y_CLUTCH_STATUS, 0, "\n");
	mvprintw(Y_CLUTCH_STATUS, 0, "Clutch: Engaged");
    }
    else {
	mvprintw(Y_CLUTCH_STATUS, 0, "\n");
	mvprintw(Y_CLUTCH_STATUS, 0, "Clutch: Not Engaged");
    }
}

void Gauges::printRedlineStatus(Engine *engine) {
    if (engine -> redlining) {
	mvprintw(Y_REDLINING, 0, "REDLINING!!!");
    }
    else {
	mvprintw(Y_REDLINING, 0, "\n");
    }
}

void Gauges::printLimitToggle(Engine *engine) {
    if (engine -> getLimitToggle()) {
	mvprintw(11, 0, "\n");
	mvprintw(11, 0, "Redline Limiting: On");
    }
    else {
	mvprintw(11, 0, "\n");
	mvprintw(11, 0, "Redline Limiting: Off");
    }
}
