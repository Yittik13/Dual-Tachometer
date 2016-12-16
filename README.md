# Dual-Tachometer
Idea for a duel tachometer for manual cars

The purpose of this program is to simulate my idea for a dual RPM meter by using statistics gathered from a 2006 Scion xA.

Purpose and function of the dual meter: 
	The dual RPM meter would be useful in manual cars for engine speed matching when shifting gears. It works by calculating the "correct RPM" based on the current velocity of the car and the gear the car is currently in.


Visual Aspects of the Gauge:
	The gauge itself would have a appearance of a normal RPM gauge but with another ring on the outside of the gauge which spins to the correct RPM.


Example of how it works:
	When driving with the clutch disengaged, the “correct “RPM” meter would simply be matched with the current RPM. However, when the clutch is engaged and the driver switches gears, the “correct RPM” gauge would spin to indicate the matching speed of the engine.


To run the program:
	Navigate to the location of the program in a terminal window. Type ‘make’ then ‘./main’ to run. Once running the program will display controls for the simulated engine. One is unable to accelerate when either the clutch is engaged, or the engine is not in gear. Furthermore, if the redline limit toggle is set to ON, one will not be able to either accelerate past the redline RPM limit (which is 7000 in this car), or downshift and disengage the clutch in a gear which would exceed the redline limit. The program begins with the engine in neutral, a velocity of 0 mph, and the redline limit toggle set to ON. 
