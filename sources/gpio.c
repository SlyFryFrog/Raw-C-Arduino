#include "gpio.h"

#include <avr/io.h>
#include <util/delay.h>

// Helper struct for pin mapping
typedef struct
{
	volatile uint8_t* ddr;
	volatile uint8_t* port;
	uint8_t bit;
} PinMap;

// Arduino Uno pin to port/bit mapping
static const PinMap pinMap[20] = {
	// Digital pins 0 to 7  (PORTD)
	{&DDRD, &PORTD, PD0}, // 0
	{&DDRD, &PORTD, PD1}, // 1
	{&DDRD, &PORTD, PD2}, // 2
	{&DDRD, &PORTD, PD3}, // 3
	{&DDRD, &PORTD, PD4}, // 4
	{&DDRD, &PORTD, PD5}, // 5
	{&DDRD, &PORTD, PD6}, // 6
	{&DDRD, &PORTD, PD7}, // 7
	// Digital pins 8 to 13 (PORTB)
	{&DDRB, &PORTB, PB0}, // 8
	{&DDRB, &PORTB, PB1}, // 9
	{&DDRB, &PORTB, PB2}, // 10
	{&DDRB, &PORTB, PB3}, // 11
	{&DDRB, &PORTB, PB4}, // 12
	{&DDRB, &PORTB, PB5}, // 13
	// Analog pins A0 to A5 (PORTC)
	{&DDRC, &PORTC, PC0}, // 14 / A0
	{&DDRC, &PORTC, PC1}, // 15 / A1
	{&DDRC, &PORTC, PC2}, // 16 / A2
	{&DDRC, &PORTC, PC3}, // 17 / A3
	{&DDRC, &PORTC, PC4}, // 18 / A4
	{&DDRC, &PORTC, PC5}, // 19 / A5
};

void pinMode(const uint8_t pin, const PinMode mode)
{
	if (pin > 19)
	{
		return; // invalid pin
	}
	if (mode == OUTPUT)
	{
		*pinMap[pin].ddr |= (1 << pinMap[pin].bit);
	}
	else
	{
		*pinMap[pin].ddr &= ~(1 << pinMap[pin].bit);
	}
}

void digitalWrite(const uint8_t pin, const PinState state)
{
	if (pin > 19)
	{
		return;
	}
	if (state == HIGH)
	{
		*pinMap[pin].port |= (1 << pinMap[pin].bit);
	}
	else
	{
		*pinMap[pin].port &= ~(1 << pinMap[pin].bit);
	}
}

uint8_t digitalRead(const uint8_t pin)
{
	if (pin > 19)
	{
		return 0;
	}
	return *pinMap[pin].port & (1 << pinMap[pin].bit);
}

void delay_s(uint16_t s)
{
	while (s--)
	{
		_delay_ms(1000);
	}
}

void delay_ms(uint16_t ms)
{
	while (ms--)
	{
		_delay_ms(1);
	}
}

void delay_us(uint16_t us)
{
	while (us--)
	{
		_delay_us(1);
	}
}
