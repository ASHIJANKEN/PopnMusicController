/*
 * Please install the library before compile this.
 * https://github.com/MHeironimus/ArduinoJoystickLibrary
 */

#include <Joystick.h>

#define BUTTONS_NUM 9

Joystick_ Joystick;
int pin_map[BUTTONS_NUM] = {21, 2, 19, 3, 15, 5, 16, 7, 9};

void setup(){
	// Initialize button pins
	for(int i = 0; i < BUTTONS_NUM; i++){
		pinMode(pin_map[i], INPUT);
	}

	// Initialize joystick library
	Joystick.begin();
}

int lastButtonState[BUTTONS_NUM] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop(){
	// Read pin values
	for(int i = 0; i < BUTTONS_NUM; i++){
		int currentButtonState = !digitalRead(pin_map[i]);
		if(currentButtonState != lastButtonState[i]){
			Joystick.setButton(i, currentButtonState);
			lastButtonState[i] = currentButtonState;
		}
	}
	delay(50);
}

