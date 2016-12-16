#include <ncurses.h>

#include "Engine.hpp"
#include "Gauges.hpp"

Engine *engine = new Engine();
Gauges gauges;

void screenSetup() {
    initscr();
    noecho();
    curs_set(FALSE);
    refresh();
    
    mvprintw(0, 0, "DUAL RPM GAUGE SIMULATION");
    mvprintw(2, 0, "Controls");
    mvprintw(3, 0, "r - Toggle Redline Limiting");
    mvprintw(4, 0, "w - Accelerate");
    mvprintw(5, 0, "s - Decelerate");
    mvprintw(6, 0, "c - Toggle Clutch");
    mvprintw(7, 0, "e - Up Shift");
    mvprintw(8, 0, "d - Down Shift");
    mvprintw(9, 0, "q - Quit");
}

void updateInfo() {
    gauges.printCurrentRPM(engine);
    gauges.printCorrectRPM(engine);
    gauges.printCurrentVelocity(engine);
    gauges.printCurrentGear(engine);
    gauges.printClutchStatus(engine);
    gauges.printRedlineStatus(engine);
    gauges.printLimitToggle(engine);
}

int main () {
    int userInput;

    screenSetup();
    updateInfo();

    while ((userInput = getch()) != 'q') {
	switch(userInput) {
	case 'r':
	    engine -> toggleRedlineLimit();
	    break;
	    
	case 'w':
	    engine -> accelerate();
	    break;

	case 's':
	    engine -> decelerate();
	    break;

	case 'c':
	    if (engine -> getClutchStatus()) {
		engine -> disengageClutch();
	    }
	    else {
		engine -> engageClutch();
	    }
	    break;

	case 'e':
	    engine -> upShift();
	    break;

	case 'd':
	    engine -> downShift();
	    break;

	default:

	    break;
	}
	updateInfo();
    }
    
    endwin();
    
    return 0;
}
