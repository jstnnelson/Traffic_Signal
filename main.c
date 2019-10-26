/*
 * Traffic_Signal.c
 *
 * Created: 10/22/2019 10:15:38 PM
 * Author : Justin
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define MIN_GREEN 5000
#define MAX_GREEN 5000
#define YELLOW_CLEARANCE 3000 
#define RED_CLEARANCE 1000

void init();

int main(void)
{
    while (1) 
    {
		//Green signal one direction 
		PORTB &= ~(1<<PORTB3);		
		PORTB |= 1<<PORTB1;
		_delay_ms(MIN_GREEN);
		//Change green to yellow
		PORTB &= ~(1<<PORTB1);		
		PORTB |= 1<<PORTB2;		
		_delay_ms(YELLOW_CLEARANCE);
		//Change yellow to red
		PORTB &= ~(1<<PORTB2);		
		PORTB |= 1<<PORTB3;		
		_delay_ms(RED_CLEARANCE);
		//Green signal other direction
		PORTD &= ~(1<<PORTD6);
		PORTB |= 1<<PORTB0;	
		_delay_ms(MIN_GREEN);
		//Change green to yellow	
		PORTB &= ~(1<<PORTB0);
		PORTD |= 1<<PORTD7;		
		_delay_ms(YELLOW_CLEARANCE);
		//Change yellow to red
		PORTD &= ~(1<<PORTD7);
		PORTD |= 1<<PORTD6;		
		_delay_ms(RED_CLEARANCE);	
    }
}

void init()
{
	DDRB |= ((1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3));
	DDRD |= ((1<<DDD6) | (1<<DDD7));
	PORTB |= 1<<PORTB3;
	PORTD |= 1<<PORTD6;	
	_delay_ms(2000);	
}

