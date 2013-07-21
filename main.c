#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define LED_PIN 1
#define HOLD 16

inline static void sw_pwm(uint8_t fill);

int main() {
	uint8_t level, wait;
	DDRB |= LED_PIN;
	while (1) {
		for (level = 0; level < 255; level++) {
			for (wait = 0; wait < HOLD; wait++) {
				sw_pwm(level);
			}
		}
		for (level = 255; level > 0; level--) {
			for (wait = 0; wait < HOLD; wait++) {
				sw_pwm(level);
			}
		}
	}
}

inline static void sw_pwm(uint8_t fill) {
	uint8_t ctr = 0;
	for (ctr = 0; ctr < fill; ctr++) {
		asm("nop");
	}
	PORTB ^= LED_PIN;
	for (ctr = fill; ctr != 0; ctr++) {
		asm("nop");
	}
	PORTB ^= LED_PIN;
}
