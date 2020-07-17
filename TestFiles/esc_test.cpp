#include <pigpio.h>
#include <iostream>

#define PIN 4
#define SEC_IN_US 1000000
#define SPEED_RANGE 1000
#define NUM_ITERATIONS 24

int main(int argc, char *argv[]) {
	int initStatus = 0;
	int speed = 0;
	int speed_inc = SPEED_RANGE / NUM_ITERATIONS;

	// Initializes the pigpio library
	initStatus = gpioInitialise();
	// Checks for successful initialization
	if (initStatus < 0) {
		std::cout << "Initialization failed\n";
		exit(-1);
	}

	// Sets the PIN to output mode
	gpioSetMode(PIN, PI_OUTPUT);
	gpioSetPWMfrequency(PIN, 50);
	/*
	// Prints out the mode of PIN
	std::cout << PI_OUTPUT << "\n";
	std::cout << gpioGetMode(PIN) << "\n";

	// Sets the frequency to 50 Hz and generates a pulse at PIN
	gpioServo(PIN, 1000);
	// Prints out the Servo Pulsewidth
	std::cout << gpioGetServoPulsewidth(PIN) << "\n";
	std::cout << gpioGetPWMfrequency(PIN) << "\n";

	// Delays the signal for 1 second
	gpioDelay(SEC_IN_US);

	// Sets the motor to half speed
	gpioServo(PIN, 1500);
	std::cout << gpioGetServoPulsewidth(PIN) << "\n";
	std::cout << gpioGetPWMfrequency(PIN) << "\n";

	// Delays the signal for 5 seconds
	gpioDelay(SEC_IN_US * 5);

	// Sets the motor to full speed
	gpioServo(PIN, 2000);
	std::cout << gpioGetServoPulsewidth(PIN) << "\n";
	std::cout << gpioGetPWMfrequency(PIN) << "\n";

	// Delays the signal for 5 seconds
	gpioDelay(SEC_IN_US * 5);

	// Turns the motor off
	gpioServo(PIN, 1000);

	std::cout << gpioGetPWMfrequency(PIN) << "\n";
	*/

	for(int i = 0; i < NUM_ITERATIONS; i++) {
		gpioServo(PIN, 1000 + speed);
		gpioDelay(5 * SEC_IN_US);
		speed += speed_inc;

	}

	// Releases all resources used by the pins
	gpioTerminate();

	

	std::cout << "Program finished!\n";

	return 0;
}
