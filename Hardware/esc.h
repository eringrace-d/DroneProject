#include <iostream>
#include <wiringPi.h>

class Esc {
	public:
		void Esc(int pin);
		void setSpeed(int speed);
	private:
		int speed{ 0 };
		int pin{ 0 };

		void setPin(int pin);
};
