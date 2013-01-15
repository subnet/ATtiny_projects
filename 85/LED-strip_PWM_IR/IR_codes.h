#ifndef IR_codes_h
#define IR_codes_h

#include <avr/pgmspace.h>

/*
 * data is in extended NEC format ( http://www.sbprojects.com/knowledge/ir/nec.php )
 *
 * start: (9.0ms, 4.5ms)
 * logic 0: (560µs, 560µs)
 * logic 1: (560µs, 1690µs)
 * address low-byte
 * address high-byte: in standard NEC format this would be the logical invers of the low-byte
 * command byte
 * logically inverted command byte
 * "something" <-- my remote seems to mess this up quite often (sends a very short pulse intead of 4000 something), so I don't check the last pulses
 * repeat-code
 *
 */

#define MAXPULSE 65000U
#define MINPULSE 5U
#define REPEAT_CODE_PAUSE 250	// this has to be signed !
#define NUMPULSES 72U // adjust this to capture all of the IR data. If you get lots of '0' at the end, reduce.
#define FUZZINESS 35U // had to increase to 35 for the ATtiny85 + ext. resonator.

#define	vol_down { \
	 882, 438,\
	 54, 56,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 52, 166,\
	 54, 166,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 54, 54,\
	 54, 166,\
	 52, 56,\
	 54, 56,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 54, 164,\
	 56, 164,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 54, 164,\
	 52, 166,\
	 56, 164,\
	 54, 4002,\
	 878, 218,\
	 54, 0}\

#define play_pause { \
	 882, 440,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 52, 58,\
	 50, 58,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 54, 166,\
	 52, 4006,\
	 874, 224,\
	 48, 0} \

#define vol_up { \
	 882, 440,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 52, 58,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 58,\
	 52, 168,\
	 50, 58,\
	 52, 168,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 54, 166,\
	 52, 4004,\
	 876, 222,\
	 50, 0}\

#define	setup_key {\
	 880, 440,\
	 54, 56,\
	 50, 60,\
	 50, 56,\
	 54, 58,\
	 50, 58,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 54, 166,\
	 52, 166,\
	 50, 168,\
	 54, 166,\
	 52, 56,\
	 54, 166,\
	 52, 56,\
	 54, 56,\
	 50, 168,\
	 52, 58,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 58,\
	 52, 166,\
	 52, 166,\
	 54, 56,\
	 50, 168,\
	 54, 166,\
	 52, 166,\
	 52, 166,\
	 54, 166,\
	 52, 4004,\
	 876, 222,\
	 50, 0}\

#define	arrow_up { \
	 880, 440,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 56,\
	 52, 60,\
	 50, 56,\
	 54, 56,\
	 52, 58,\
	 52, 166,\
	 52, 166,\
	 54, 168,\
	 50, 168,\
	 50, 166,\
	 54, 168,\
	 50, 56,\
	 54, 168,\
	 50, 168,\
	 50, 58,\
	 52, 166,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 168,\
	 52, 58,\
	 50, 166,\
	 54, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 4004,\
	 878, 220,\
	 50, 0}\

#define	stop_mode {\
	 882, 438,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 54, 56,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 54, 166,\
	 52, 166,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 54,\
	 52, 166,\
	 56, 164,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 4002,\
	 878, 220,\
	 52, 0}\

#define	arrow_left {\
	 882, 436,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 54, 164,\
	 56, 166,\
	 52, 164,\
	 54, 164,\
	 56, 166,\
	 52, 54,\
	 56, 166,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 52, 58,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 54, 52,\
	 58, 164,\
	 54, 164,\
	 52, 166,\
	 56, 164,\
	 54, 4002,\
	 878, 218,\
	 54, 0}\

#define	enter_save {\
	 882, 440,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 54, 166,\
	 50, 168,\
	 50, 168,\
	 54, 166,\
	 52, 56,\
	 54, 166,\
	 52, 166,\
	 50, 60,\
	 50, 58,\
	 52, 168,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 52, 166,\
	 54, 168,\
	 50, 56,\
	 54, 166,\
	 52, 166,\
	 52, 166,\
	 54, 168,\
	 50, 4004,\
	 878, 220,\
	 50, 0}\

#define	arrow_right {\
	 882, 436,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 166,\
	 54, 52,\
	 58, 164,\
	 52, 54,\
	 56, 166,\
	 52, 164,\
	 54, 164,\
	 56, 166,\
	 52, 4002,\
	 880, 218,\
	 54, 0}\

#define	digit_0_or_10 { \
	 880, 438,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 52, 58,\
	 52, 166,\
	 52, 166,\
	 54, 166,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 54, 54,\
	 54, 166,\
	 52, 56,\
	 54, 56,\
	 52, 164,\
	 56, 166,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 164,\
	 54, 164,\
	 54, 56,\
	 54, 54,\
	 56, 164,\
	 54, 164,\
	 52, 166,\
	 56, 164,\
	 54, 4002,\
	 878, 218,\
	 54, 0}\

#define	arrow_down {\
	 882, 438,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 52, 58,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 166,\
	 52, 166,\
	 54, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 56,\
	 54, 168,\
	 50, 168,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 52, 58,\
	 52, 166,\
	 52, 58,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 54, 166,\
	 52, 4004,\
	 876, 222,\
	 50, 0}\

#define	arrow_repeat {\
	 882, 436,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 52, 56,\
	 54, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 164,\
	 54, 164,\
	 56, 54,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 52, 164,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 164,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 4002,\
	 878, 220,\
	 54, 0}\

#define	digit_1 {\
	 880, 438,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 54, 56,\
	 52, 166,\
	 52, 166,\
	 56, 164,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 54,\
	 52, 56,\
	 54, 54,\
	 56, 164,\
	 54, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 164,\
	 54, 56,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 0}\

#define	digit_2 {\
	 882, 436,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 56, 54,\
	 52, 58,\
	 52, 54,\
	 56, 54,\
	 54, 56,\
	 54, 164,\
	 54, 164,\
	 56, 164,\
	 54, 166,\
	 52, 164,\
	 56, 166,\
	 52, 54,\
	 56, 166,\
	 52, 164,\
	 54, 58,\
	 52, 54,\
	 56, 54,\
	 54, 164,\
	 56, 54,\
	 54, 56,\
	 54, 54,\
	 54, 56,\
	 52, 166,\
	 54, 166,\
	 52, 166,\
	 52, 58,\
	 52, 164,\
	 54, 164,\
	 56, 166,\
	 52, 4002,\
	 880, 220,\
	 52, 0}\

#define	digit_3 {\
	 882, 438,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 58,\
	 52, 166,\
	 52, 166,\
	 54, 168,\
	 50, 168,\
	 50, 168,\
	 52, 166,\
	 52, 56,\
	 54, 166,\
	 52, 56,\
	 54, 166,\
	 52, 56,\
	 54, 56,\
	 50, 168,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 168,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 50, 60,\
	 50, 166,\
	 52, 168,\
	 52, 168,\
	 50, 4006,\
	 876, 220,\
	 50, 0}\

#define	digit_4 {\
	 882, 442,\
	 50, 58,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 52, 170,\
	 48, 60,\
	 50, 168,\
	 50, 58,\
	 52, 58,\
	 50, 168,\
	 52, 58,\
	 50, 166,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 54, 168,\
	 50, 166,\
	 50, 60,\
	 52, 166,\
	 52, 58,\
	 50, 168,\
	 52, 166,\
	 54, 166,\
	 50, 4006,\
	 876, 222,\
	 50, 0}\

#define	digit_5 {\
	 880, 440,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 58,\
	 52, 56,\
	 54, 56,\
	 52, 58,\
	 52, 166,\
	 50, 168,\
	 54, 166,\
	 52, 166,\
	 52, 166,\
	 54, 168,\
	 50, 56,\
	 54, 168,\
	 50, 166,\
	 52, 58,\
	 52, 166,\
	 52, 58,\
	 52, 166,\
	 52, 58,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 168,\
	 50, 58,\
	 52, 168,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 52, 168,\
	 50, 4004,\
	 878, 220,\
	 50, 0}\

#define	digit_6 {\
	 882, 438,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 166,\
	 52, 166,\
	 54, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 56,\
	 54, 168,\
	 50, 56,\
	 54, 168,\
	 50, 168,\
	 50, 60,\
	 50, 168,\
	 50, 58,\
	 52, 56,\
	 54, 56,\
	 50, 168,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 4006,\
	 876, 220,\
	 50, 0}\

#define	digit_7 {\
	 882, 438,\
	 54, 56,\
	 52, 58,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 58,\
	 52, 60,\
	 48, 58,\
	 52, 170,\
	 48, 170,\
	 50, 168,\
	 50, 168,\
	 50, 166,\
	 54, 166,\
	 52, 56,\
	 54, 166,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 52, 58,\
	 50, 60,\
	 50, 168,\
	 50, 166,\
	 54, 168,\
	 50, 4006,\
	 876, 224,\
	 46, 0}\

#define	digit_8 {\
	 882, 438,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 58,\
	 52, 58,\
	 50, 60,\
	 50, 166,\
	 52, 166,\
	 54, 168,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 56,\
	 54, 168,\
	 50, 168,\
	 50, 60,\
	 50, 56,\
	 54, 168,\
	 50, 166,\
	 52, 58,\
	 52, 56,\
	 54, 56,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 58,\
	 50, 60,\
	 50, 168,\
	 50, 168,\
	 52, 168,\
	 50, 4006,\
	 876, 224,\
	 46, 0}\

#define	digit_9 {\
	 880, 442,\
	 50, 60,\
	 50, 56,\
	 54, 56,\
	 52, 58,\
	 52, 56,\
	 54, 58,\
	 48, 60,\
	 50, 58,\
	 52, 170,\
	 48, 168,\
	 50, 168,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 52, 58,\
	 50, 168,\
	 52, 56,\
	 52, 168,\
	 52, 56,\
	 52, 168,\
	 52, 168,\
	 50, 56,\
	 54, 60,\
	 48, 58,\
	 52, 166,\
	 52, 60,\
	 50, 166,\
	 50, 60,\
	 50, 58,\
	 52, 168,\
	 50, 168,\
	 50, 168,\
	 54, 4004,\
	 874, 226,\
	 48, 0}\

/*
 * If you don't need some of the IR codes, just remove them from the IRsignals[][] array below
 * Also add/remove them from the IR_code_t enum (see IR_receiver.hpp), but make sure the ORDER of the remaining IR
 * code is the same in both. To free up memory, reduce 'NUMBER_OF_IR_CODES' to match the
 * remaining elements of the IRsignals array.
 *
 * If that is done, adjust the switch-statement in the main code by disabling all obsolete cases.
 *
 */

#define NUMBER_OF_IR_CODES 4	// does not include the repeat-code, which I don't consider as a "full" code.

const uint16_t PROGMEM IRsignals[NUMBER_OF_IR_CODES][NUMPULSES] = {
    vol_up,
    vol_down,
    arrow_up,
    arrow_down
};

#endif
