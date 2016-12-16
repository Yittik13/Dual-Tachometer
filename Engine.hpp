#ifndef ENGINE_H
#define ENGINE_H

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


class Engine {
public:
    
    bool redlining;
    
    Engine();
    
    void accelerate();
    void decelerate();
    void upShift();
    void downShift();
    void calculateCurrentRPM();
    void calculateCorrectRPM();
    void engageClutch();
    void disengageClutch();
    void toggleRedlineLimit();

    unsigned int getVelocity() {
	return currentVelocity;
    }
    
    unsigned int getCurrentRPM() {
	return currentRPM;
    }
    
    unsigned int getCorrectRPM() {
	return correctRPM;
    }
    
    unsigned int getGear() {
	return currentGear;
    }

    bool getClutchStatus() {
	return clutchEngaged;
    }

    bool getLimitToggle() {
	return redlineLimit;
    }

    
private:
    bool clutchEngaged;

    bool redlineLimit;
    
    unsigned int currentVelocity;
    unsigned int currentRPM;
    unsigned int correctRPM;
    unsigned int currentGear;

};

#endif
