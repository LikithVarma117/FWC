# Simulated AVR registers
PORTD = 0
PORTB = 0
DDRD = 0
DDRB = 0
PIND = 0

# Bit positions (same as AVR)
PD2 = 2
PD3 = 3
PD4 = 4
PD5 = 5
PD6 = 6
PD7 = 7

PB0 = 0
PB1 = 1
PB2 = 2


def show0():
    global PORTD, PORTB

    # Display 0 (LOW = ON)
    PORTD &= ~((1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7))
    PORTB &= ~((1 << PB0) | (1 << PB1))
    PORTB |= (1 << PB2)

    print("Displaying 0")
    print("PORTD =", bin(PORTD))
    print("PORTB =", bin(PORTB))


def show1():
    global PORTD, PORTB

    # Display 1 (LOW = ON)
    PORTD |= (1 << PD4) | (1 << PD7)
    PORTD &= ~((1 << PD5) | (1 << PD6))
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2)

    print("Displaying 1")
    print("PORTD =", bin(PORTD))
    print("PORTB =", bin(PORTB))


def main():
    global DDRD, DDRB, PORTD, PIND

    # Buttons input
    DDRD &= ~((1 << PD2) | (1 << PD3))
    PORTD |= (1 << PD2) | (1 << PD3)   # pull-ups

    # Segment output
    DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7)
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2)

    while True:

        # Simulate button input
        b1 = int(input("Press Button PD2 (0/1): "))
        b2 = int(input("Press Button PD3 (0/1): "))

        # Update PIND register
        PIND = 0
        if b1:
            PIND |= (1 << PD2)
        if b2:
            PIND |= (1 << PD3)

        p1 = PIND & (1 << PD2)
        p2 = PIND & (1 << PD3)

        # Convert to: 0 = not pressed, 1 = pressed
        A = int(not p1)
        B = int(not p2)

        # NOR logic
        Y = int(not (A | B))

        if Y:
            show1()
        else:
            show0()


main()
