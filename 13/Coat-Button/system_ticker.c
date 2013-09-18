#include <avr/interrupt.h>
#include <stdint.h>
#include "system_ticker.h"

volatile uint16_t system_ticks = 0;

void system_ticker_setup(void)
{
	// set as output for PWM (via interrupts)
	DDRB |= ( _BV(PB3) | _BV(PB4) );
	PORTB &= ~ ( _BV(PB3) | _BV(PB4) );
	OCR0A = 255; // start with LEDs OFF
	// using timer0
	// setting prescaler to 8: 9.6MHz system-clock --> 1.2MHz timer0-clock - ~5kHz PWM clock
	TCCR0B |= _BV(CS01);
	TCCR0B &= ~(_BV(CS02) | _BV(CS00));
	// set to 'NORMAL' WGM0 mode.
	TCCR0A &= ~(_BV(WGM01) | _BV(WGM00));
	TCCR0B &= ~_BV(WGM02);
	// enabling overflow interrupt
	TIMSK0 |= _BV(TOIE0);
	// enable compare match interrupt A
	TIMSK0 |= _BV(OCIE0A);
}

ISR(TIM0_COMPA_vect)
{
	// manual PWM...
	
	//
	// due to interrupt latency, runtime...
	// setting the pin at 255 and turning it off again in the overflow ISR
	// doesn't producte 0% duty cycle.
	//
	if(OCR0A < 255) {
		PORTB &= ~( _BV(PB3) | _BV(PB4) ); // LOW (ON)
	}
}

ISR(TIM0_OVF_vect)		// on attiny2313/4313 this is named TIMER0_OVF_vect
{
	system_ticks++;
	
	PORTB |= ( _BV(PB3) | _BV(PB4) ); // HIGH (OFF)
}

uint16_t time(void)
{
	uint8_t _sreg = SREG;
	uint16_t time;
	cli();
	time = system_ticks;
	SREG = _sreg;
	return time;
}

void delay(uint16_t ticks)
{
	uint16_t start_time = time();
	while ((time() - start_time) < ticks) {
		// just wait here
	}
}
