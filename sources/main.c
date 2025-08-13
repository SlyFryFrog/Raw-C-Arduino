#define F_CPU 16000000UL
#define POLL_INTERVAL_MS 3000

#include "gpio.h"

int main(void)
{
	// Set pin modes for duration of program

	// OUTPUT PINS
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);

	// INPUT PINS

	while (1)
	{
		digitalWrite(13, HIGH);
		delay_s(3);
		digitalWrite(13, LOW);
		delay_ms(POLL_INTERVAL_MS);
	}
}
