#include<reg51.h>
sbit D1S1 = P2^6;
sbit D2S2 = P2^7;
void M_Delay(unsigned char ); // define delay for mux
unsigned char dig, dec; // define variables
unsigned int delay;
unsigned char pattern[] = {0xC0, 0xF9, 0XA4, 0xB0, 0X99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main(){
	P0= 0xFF; // pin o is off
	while(1){
		for(dec=0;dec<10;dec++){
			for(dig=0;dig<10;dig++){
				for(delay=0;delay<450;delay++){
					D1S1=1;
					P0=pattern[dec];
					M_Delay(900);
					D1S1=0;
					
					D2S2=1;
					P0=pattern[dig];
					M_Delay(900);
					D2S2=0;
				}
			}
		}
	}
}

void M_Delay(unsigned char time){
	unsigned char mtime;
	for(mtime=0;mtime<time;mtime++);
}
	