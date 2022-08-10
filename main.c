#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SIFT_PORT PORTB
#define SIFT_DDR DDRB

#define SIFT_DS_POS PB2//Data pin location

#define SIFT_SH_CP_POS PB0//Shift Clock (SH_CP) pin location 
#define SIFT_ST_CP_POS PB1//Store Clock (ST_CP) pin location

#define BUTTON_PORT PORTD
#define BUTTON_DDR DDRD

#define BUTTON_LED_PORT PORTC
#define BUTTON_LED_DDR DDRC

#define SIFTDataHigh() (SIFT_PORT|=(1<<SIFT_DS_POS))//Low level macros to change data (DS)lines
#define SIFTDataLow() (SIFT_PORT&=(~(1<<SIFT_DS_POS)))//Sends a clock pulse on SH_CP line

volatile unsigned int p=0, btn = 0;


void SIFTInit(){
	SIFT_DDR|=((1<<SIFT_SH_CP_POS)|(1<<SIFT_ST_CP_POS)|(1<<SIFT_DS_POS));	//Make the Data(DS), Shift clock (SH_CP), Store Clock (ST_CP) lines output
   
}

void SIFTPulse(){//Pulse the Shift Clock
	
	SIFT_PORT|=(1<<SIFT_SH_CP_POS);//HIGH
	SIFT_PORT&=(~(1<<SIFT_SH_CP_POS));//LOW
}

void SIFTLatch(){//Sends a clock pulse on ST_CP line

   SIFT_PORT|=(1<<SIFT_ST_CP_POS);//HIGH
   _delay_loop_1(10000);

   SIFT_PORT&=(~(1<<SIFT_ST_CP_POS));//LOW
   _delay_loop_1(10000);
}

void SIFTWrite(int data){//Send each 8 bits serially
   
	for(int i=0;i<8;i++){//Order is MSB first
  
		if(data & 0b10000000){//Output the data on DS line according to the
			
			SIFTDataHigh();//MSB is 1 so output high
		}else{
         
         SIFTDataLow();//MSB is 0 so output high
		}

		SIFTPulse();  //Pulse the Clock line
		data=data<<1;  //Now bring next bit at MSB position
	}

   SIFTLatch();//Now all 8 bits have been transferred to shift register NOW Move them to output latch at one 
}

void Wait(){
	for(int i=0;i<20;i++){
  
		_delay_loop_2(10000);
	}
}

int main(){
	BUTTON_LED_DDR |= 1<< PC0 | 1<< PC1;
	PORTC = 0x00;
	BUTTON_DDR &= ~(1<<PD2);//inturrupt0
	BUTTON_LED_PORT &= ~(1<< PA0);
	GICR |= (1<<INT0 | 1<<INT1);
	MCUCR |= 1<<ISC10| 1<<ISC11 | 1<<ISC00| 1<<ISC01 ;
   sei();
	btn=0;
	p=0;

	SIFTInit();

	while(1){
		if(p==0){
			int led_pattern[8]={						
				0b11111111,
				0b11000111,
				0b11100111,
				0b11111111,
				0b01111110,
				0b00111100,
				0b00011000,
				0b00000000,
				};
				for(int i=0;i<8;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==1){
			int led_pattern[8]={
				0b11111111,
				0b11111110,
				0b11111100,
				0b11111000,
				0b11110000,
				0b11100000,
				0b11000000,
				0b10000000,
				};
				for(int i=0;i<100;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==2){
			int led_pattern[8]={
				0b11111111,
				0b11000111,
				0b11100111,
				0b11111111,
				0b01111110,
				0b00111100,
				0b00011000,
				0b00000000,
				};
				for(int i=0;i<20;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==3){
			int led_pattern[8]={
				0b00000000,
				0b11111111,
				0b00000000,
				0b00000000,
				0b11111111,
				0b00000000,
				0b00000000,
				0b11111111,
				};
				for(int i=0;i<20;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==4){
			int led_pattern[8]={
				0b01111111,
				0b00111111,
				0b00011111,
				0b00001111,
				0b00000111,
				0b00000011,
				0b00000001,
				0b00000000,
				};
				for(int i=0;i<20;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==5){
			int led_pattern[8]={
				0b11111111,
				0b00000000,
				0b11111111,
				0b00000000,
				0b11111111,
				0b00000000,
				0b11111111,
				0b00000000,
				};
				for(int i=0;i<20;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==6){
			int led_pattern[8]={
				0b11111111,
				0b01111110,
				0b00111100,
				0b00111100,
				0b01111110,
				0b11111111,
				0b01111110,
				0b00111100,
				};
				for(int i=0;i<8;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==7){
			int led_pattern[8]={
				0b01010101,
				0b10101010,
				0b01010101,
				0b10101010,
				0b01010101,
				0b10101010,
				0b01010101,
				0b10101010,
				};
				for(int i=0;i<40;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==8){
			int led_pattern[8]={
				0b01010101,
				0b10101010,
				0b01010101,
				0b10101010,
				0b01010101,
				0b10101010,
				0b01010101,
				0b10101010,
				};
				for(int i=0;i<20;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else if (p==9){
			int led_pattern[8]={
				0b10000001,
				0b10000001,
				0b01111110,
				0b01111110,
				0b10000001,
				0b10000001,
				0b01111110,
				0b01111110,
				};
				for(int i=0;i<50;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}else{
			int led_pattern[8]={
				0b11111111,
				0b11000111,
				0b11100111,
				0b11111111,
				0b01111110,
				0b00111100,
				0b00011000,
				0b00000000,
				};
				for(int i=0;i<8;i++){
					SIFTWrite(led_pattern[i]);//Write the data to sHIFT REGISTER
					Wait(); //Wait	
				}
		}
	}
return 0;
}

ISR(INT0_vect){
	p++; btn++;
	PORTC = 0b00000001;
	_delay_ms(100);
	PORTC = 0x00;

}

ISR(INT1_vect){
	p--; btn--;
	PORTC = 0b00000010;
	_delay_ms(100);
	PORTC = 0x00;
}