#include "esc.h"

void Esc::Esc(int pin) {
	Esc::setPin(pin);
}

void Esc::setSpeed(int speed) {
	Esc::speed = speed;
}

void Esc::setPin(int pin) {
	Esc::pin = pin;
}

void Esc::init() {
	
	
}
