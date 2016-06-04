
#ifndef VASILE2KAPPA
#define VASILE2KAPPA

#include <avr/interrupt.h>

#define USED_PORT B

#define CAT(X, Y) X ## Y
#define CONCAT(X, Y) CAT(X, Y)

#define _PORT CONCAT(PORT, USED_PORT)
#define _DDR CONCAT(DDR, USED_PORT)


ISR(PCINT0_vect) {
	_PORT = ~_PORT & 0b00100000;
}

int main() {

	_DDR = 0b00100000;

	_PORT = 0b00010000;

	PCICR |= (1 << PCIE0);    // set PCIE0 to enable PCMSK0 scan
	PCMSK0 |= (1 << PCINT4);  // set PCInT0 to trigger an interrupt on state change 

	sei();                    // turn on interrupts

	while (1) {

	}
	return 0;
}

#endif // !VASILE2KAPPA
