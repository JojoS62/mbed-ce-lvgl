#include "mbed.h"

DigitalOut led(LED1);
DigitalOut testPin(PA_4);

int main()
{
    printf("Test for TFT Displays\n");
    printf("Hello from "  MBED_STRINGIFY(TARGET_NAME) "\n");
    printf("Mbed OS version: %d.%d.%d\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
	
	while(true) {
		led = !led;
		testPin = !testPin;

		ThisThread::sleep_for(50ms);
	}

	// main() is expected to loop forever.
	// If main() actually returns the processor will halt
	return 0;
}