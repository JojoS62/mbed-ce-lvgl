#include "mbed.h"

DigitalOut led(LED1);
DigitalOut testPin(PA_4);

int main()
{
	printf("hello world from \n");
	
	while(true) {
		led = !led;
		testPin = !testPin;

		ThisThread::sleep_for(100ms);
	}

	// main() is expected to loop forever.
	// If main() actually returns the processor will halt
	return 0;
}