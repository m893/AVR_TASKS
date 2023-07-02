
#include <avr\io.h>
#include <util\delay.h>

void main (void)
{
	
	DDRA=0b00010000;

	while(1)
	{
		PORTA=0b00010000;
		_delay_ms(1000);
		PORTA=0b00000000;
		_delay_ms(1000);
	}

}


