/****************************
	   Anil Efe
      The Walking Lights
	 ATMega32A-PU
*****************************/

#define F_CPU 16000000  // Crystal frequency set 16MHz
#include <avr/io.h>
#include <util/delay.h>

int main(void){
	int d_time= 30;			    // Delay time can be change.
	DDRB = 0xFF;			    // DDRB= 0b11111111 --> All bits of PORTB are set "OUTPUT".
	DDRD &= ~((1 << 6)|(1 << 7));	    // DDRD = DDRD & ~(01000000 | 10000000) --> Sixth and Seventh bits of PORTD are set "INPUT".
	PORTD |= ((1 << 6)|(1 << 7));	    // PORTD = PORTD | (01000000 | 10000000) --> Set "HIGH" as "INPUT".
	
	while(1){
	if(bit_is_clear(PIND, 6)){          // When the button pressed, value will be "0" because of GROUND.
		for(int i= 1; i<=3; i++){	
			PORTB |= (1 << i);  // PORTB's 1,2,3 pins will be "HIGH" one by one.
			_delay_ms(d_time);  // Can be change with d_value.
		}
	}
	
	if(bit_is_clear(PIND, 7)){
		for(int i= 3; i>=1; i--){
			PORTB &= ~(1 << i); // PORTB's 3,2,1 pins will be "LOW" one by one.
			_delay_ms(d_time);  // Can be change with d_value.
			}
		}
	}
}
