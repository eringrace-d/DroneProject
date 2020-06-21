#include <pigpio.h>
#include <iostream>

#define PIN 0
#define SEC_IN_US 1000000

int main() {
	int initStatus = 0, modeStatus = 0;

	// Initializes the pigpio library
	initStatus = gpioInitialize();
	// Checks for successful initialization
	if (initStatus < 0) {
		std::cout << "Initialization failed\n";
		exit(-1);
	}


	// Sets the frequency to 50 Hz and generates a pulse at PIN
	gpioServo(PIN, 1000);

	// Delays the signal for 1 second
	gpioDelay(SEC_IN_US);

	// Sets the motor to half speed
	gpioServo(PIN, 1500);

	// Delays the signal for 5 seconds
	gpioDelay(SEC_IN_US * 5);

	// Sets the motor to full speed
	gpioServo(PIN, 2000);

	// Turns the motor off
	gpioServo(PIN, 1000);

	return 0;
}
