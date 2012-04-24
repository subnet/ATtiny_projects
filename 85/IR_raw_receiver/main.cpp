#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <inttypes.h>

#include "util.hpp"
#include "system_ticker.hpp"
#include "uart.hpp"
#include "IR_receiver.hpp"
#include "main.hpp"

int main(void)
{
    setup_hw();

    soft_uart_send(PSTR("Ready!\r\n"));

    while(1) {

        //TOGGLE_LED;
        //delay(200);

        if ( IR_available() ) {
            switch(eval_IR_code()) {
            case VOL_UP:
                soft_uart_send(PSTR("+"));
                //soft_uart_send(PSTR("volume up\r\n"));
                break;
            case VOL_DOWN:
                soft_uart_send(PSTR("-"));
                //soft_uart_send(PSTR("volume down\r\n"));
                break;
            case ARROW_UP:
                soft_uart_send(PSTR("F"));
                //soft_uart_send(PSTR("arrow up\r\n"));
                break;
            case ARROW_DOWN:
                soft_uart_send(PSTR("f"));
                //soft_uart_send(PSTR("arrow down\r\n"));
                break;
            case REPEAT_CODE:
                //soft_uart_send(PSTR("repeat code\r\n"));
                break;
            case MISMATCH:
                //soft_uart_send(PSTR("UNKNOWN / ERROR ARGH ARGH ARGH!\r\n"));
                break;
            case NOT_SURE_YET:
                //soft_uart_send(PSTR("You should NEVER see this!\r\n"));
                break;
            default:
                break;
            }
        }
    }
    return 0;
}

void setup_hw(void)
{
    LED_DIR |= _BV(LED_PIN);
    system_ticker_setup();
    sei(); // turn global irq flag on
    init_IR();
    soft_uart_init();
}

void read_mcusr(void)
{
    my_mcusr = MCUSR;
    MCUSR = 0;
}