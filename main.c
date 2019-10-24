/*
 * Traffic_Signal.c
 *
 * Created: 10/22/2019 10:15:38 PM
 * Author : Justin
 */ 

#include <avr/io.h>
#include <util/delay.h>

void init();

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		PINB &= ~(1<<PINB1);
		PINB |= 1<<PINB3;
		_delay_ms(1000);
		PINB &= ~(1<<PINB3);
		PINB |= 1<<PINB2;
		_delay_ms(1000);
		PINB &= ~(1<<PINB2);
		PINB |= 1<<PINB1;
		_delay_ms(1000);		
    }
}

void init()
{
	DDRB |= ((1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3));
	DDRD |= ((1<<DDD6) | (1<<DDD7));
	PORTB |= ((1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3));
	PORTD |= ((1<<PORTD6) | (1<<PORTD7));
	PINB &= (~(1<<PINB0) & ~(1<<PINB1) & ~(1<<PINB2) & ~(1<<PINB3));
	PIND &= (~(1<<PIND6) & ~(1<<PIND7)); 
}

