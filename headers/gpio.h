#pragma once

#include <stdint.h>

typedef enum
{
	INPUT = 0,
	OUTPUT = 1
} PinMode;

typedef enum
{
	LOW = 0,
	HIGH = 1
} PinState;

/**
 * @brief Sets the mode of the specified pin.
 */
void pinMode(uint8_t pin, PinMode mode);

void digitalWrite(uint8_t pin, PinState state);
uint8_t digitalRead(uint8_t pin);

void analogWrite(uint8_t pin, uint16_t value);	// TODO
uint16_t analogRead(uint8_t pin);	// TODO

/**
 * @brief Applies a delay in seconds.
 *
 * @param s Amount of time to delay.
 */
void delay_s(uint16_t s);

/**
 * @brief Applies a delay in milliseconds.
 *
 * @param ms Amount of time to delay.
 */
void delay_ms(uint16_t ms);

/**
 * @brief Applies a delay in microseconds.
 *
 * @param us Amount of time to delay.
 */
void delay_us(uint16_t us);
