#include "Engine.hpp"


#define IDLE_RPM 900
#define REDLINE 7000
/*
 * GEAR RATIOS - RPM per 1 mph - These are based on readings at 
 * various speeds and are therefore only averages.
 */
#define RATIO_FIRST 210
#define RATIO_SECOND 120
#define RATIO_THIRD 80
#define RATIO_FOURTH 58
#define RATIO_FIFTH 50

/* Gears */
#define GEAR_NEUTRAL 0
#define GEAR_FIRST 1
#define GEAR_SECOND 2
#define GEAR_THIRD 3
#define GEAR_FOURTH 4
#define GEAR_FIFTH 5

Engine::Engine() {
    currentVelocity = 0;
    currentRPM = IDLE_RPM;
    correctRPM = 0;
    currentGear = GEAR_NEUTRAL;
    clutchEngaged = false;
    redlining = false;
    redlineLimit = true;
}

void Engine::toggleRedlineLimit() {
    if (redlineLimit) {
	redlineLimit = false;
    }
    else {
	redlineLimit = true;
    }
}

/* Increase current velocity */
void Engine::accelerate() {
    if (currentGear == GEAR_NEUTRAL || clutchEngaged) {
	
    }
    else {
	currentVelocity++;
	calculateCorrectRPM();
	calculateCurrentRPM(); 
	if (correctRPM > REDLINE) {
	    redlining = true;
	    if (redlineLimit) {
		currentVelocity--;
		calculateCorrectRPM();
		calculateCurrentRPM();
	    }
	}
    }
}

/* Decrease current velocity */
void Engine::decelerate() {
    if (currentVelocity > 0) {
	currentVelocity--;
	calculateCorrectRPM();
	calculateCurrentRPM();
	if (correctRPM <= REDLINE) {
	    redlining = false;
	}
    }
}

/* Up shift one gear */
void Engine::upShift() {
    if (clutchEngaged && currentGear < GEAR_FIFTH) {
	currentGear++;
	calculateCorrectRPM();
	calculateCurrentRPM();
	redlining = false;
	if (correctRPM >= REDLINE) {
	    redlining = true;
	}
    }
}

/* Down shift one gear  */
void Engine::downShift() {
    if (clutchEngaged && currentGear > GEAR_NEUTRAL) {
	currentGear--;
	calculateCorrectRPM();
	calculateCurrentRPM();
	redlining = false;
	if (correctRPM >= REDLINE) {
	    redlining = true;
	}
    }
}

/* Engages the clutch */
void Engine::engageClutch() {
    clutchEngaged = true;
    currentRPM = IDLE_RPM;
}

/* Disengages the clutch */
void Engine::disengageClutch() {
    if (redlineLimit) {
	if (!redlining) {
	    clutchEngaged = false;
	    calculateCurrentRPM();
	    calculateCorrectRPM();
	}
    }
    else {
	clutchEngaged = false;
	calculateCurrentRPM();
	calculateCorrectRPM();
    }
}

/* Calculate current RPM based on current velocity */
void Engine::calculateCurrentRPM() {
    if (clutchEngaged) {
	currentRPM = IDLE_RPM;
    }

    else {
	switch(currentGear) {
	case 0:
	    currentRPM = IDLE_RPM;
	    break;

	case 1:
	    currentRPM = currentVelocity * RATIO_FIRST;
	    //correctRPM = currentVelocity * RATIO_FIRST;
	    break;

	case 2:
	    currentRPM = currentVelocity * RATIO_SECOND;
	    //correctRPM = currentVelocity * RATIO_SECOND;
	    break;

	case 3:
	    currentRPM = currentVelocity * RATIO_THIRD;
	    //correctRPM = currentVelocity * RATIO_THIRD;
	    break;

	case 4:
	    currentRPM = currentVelocity * RATIO_FOURTH;
	    //correctRPM = currentVelocity * RATIO_FOURTH;
	    break;

	case 5:
	    currentRPM = currentVelocity * RATIO_FIFTH;
	    //correctRPM = currentVelocity * RATIO_FIFTH;
	    break;

	default:

	    break;
	}
	
	if (currentRPM >= REDLINE) {
		currentRPM = REDLINE;
	}
    }
}

/* Calculate correct RPM based on current velocity */
void Engine::calculateCorrectRPM() {
    switch(currentGear) {
    case 0:
	currentRPM = IDLE_RPM;
	correctRPM = IDLE_RPM;
	break;

    case 1:
	//currentRPM = currentVelocity * RATIO_FIRST;
	correctRPM = currentVelocity * RATIO_FIRST;
	break;

    case 2:
	//currentRPM = currentVelocity * RATIO_SECOND;
	correctRPM = currentVelocity * RATIO_SECOND;
	break;

    case 3:
	//currentRPM = currentVelocity * RATIO_THIRD;
	correctRPM = currentVelocity * RATIO_THIRD;
	break;

    case 4:
	//currentRPM = currentVelocity * RATIO_FOURTH;
	correctRPM = currentVelocity * RATIO_FOURTH;
	break;

    case 5:
	//currentRPM = currentVelocity * RATIO_FIFTH;
	correctRPM = currentVelocity * RATIO_FIFTH;
	break;

    default:

	break;
    }
}


