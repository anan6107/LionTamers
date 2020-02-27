#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA|= (1 << PA7); // PORTB7 direction = out
	
	while (1)
	{
		
		// 1 pulse
		PORTA |= (1 << PA7); // PORTB7 hi = LED L on
		_delay_ms(2000);
		PORTA &= ~(1 << PA7);
		_delay_ms(2000);
		PORTA |= (1 << PA7); // PORTB7 hi = LED L on
		_delay_ms(2000);
		PORTA &= ~(1 << PA7);
		_delay_ms(2000);
		
	}
}
