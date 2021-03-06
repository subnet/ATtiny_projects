#ifndef led_driver_h
#define led_driver_h

#define LATCH_LOW PORTB &= ~(1 << PB1)
#define LATCH_HIGH PORTB |= (1 << PB1)
#define LATCH LATCH_HIGH; LATCH_LOW
#define DISPLAY_ON PORTB &= ~_BV(PB0)
#define DISPLAY_OFF PORTB |= _BV(PB0)

#define AUTO_FADE_IN_DELAY      16U
#define AUTO_FADE_OUT_DELAY     16U
#define MANUAL_UP_DELAY         128U // slow ( better for the eyes in the morning ;-) )
#define MANUAL_DOWN_DELAY       128U
#define MANUAL_FADE_STEPSIZE    4U
#define BCM_BIT_DEPTH 6U

#define PATTERN_A

#ifdef PATTERN_A
#define LAMP_BRIGHTNESS_MAX 255 // ( 2^(BCM_BIT_DEPTH + 2) - 1 )
#endif

#ifdef PATTERN_B
#define LAMP_BRIGHTNESS_MAX 511 // ( 2^(BCM_BIT_DEPTH + 3) - 1 )
#endif

void led_driver_setup(void);
void fade(int16_t fade_from, int16_t fade_to, uint16_t fade_delay);
void up(uint16_t fade_delay);
void down(uint16_t fade_delay);
int16_t get_brightness(void);
uint16_t flash_channel(uint8_t channel, uint8_t times, uint16_t flash_delay);

#endif
