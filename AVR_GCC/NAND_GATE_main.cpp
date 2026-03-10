#define F_CPU 16000000UL
#include <avr/io.h>

void show0() {
    // Display 0 (LOW = ON)
    PORTD &= ~((1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7));
    PORTB &= ~((1<<PB0)|(1<<PB1));
    PORTB |= (1<<PB2);
}

void show1() {
    // Display 1 (LOW = ON)
    PORTD |= (1<<PD4)|(1<<PD7);          // a,d OFF
    PORTD &= ~((1<<PD5)|(1<<PD6));       // b,c ON
    PORTB |= (1<<PB0)|(1<<PB1)|(1<<PB2); // e,f,g OFF
}

int main(void)
{
    // Buttons input
    DDRD &= ~((1<<PD2)|(1<<PD3));
    PORTD |= (1<<PD2)|(1<<PD3);  // enable pull-up

    // Segment output
    DDRD |= (1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2);

    while(1)
    {
        uint8_t p1 = PIND & (1<<PD2);
        uint8_t p2 = PIND & (1<<PD3);

        // Convert to: 0 = not pressed, 1 = pressed
        uint8_t A = !p1;
        uint8_t B = !p2;

        // NAND Logic
        uint8_t Y = !(A & B);

        if(Y)
            show1();
        else
            show0();
    }
}
