#include "stdio.h"
#include "wiringPi.h"
int main(){
	wiringPiSetup();		//initial
	pinMode(8, OUTPUT);		//set GPIO mode
	
	pinMode(9, OUTPUT);
	digitalWrite(9, LOW);	
	
	int x = 0;
	
	while(1){	
		for(int i = 0; i < 100; i++){
			digitalWrite(8, LOW);
			delayMicroseconds(x);
			digitalWrite(8, HIGH);
			delayMicroseconds(1000 - x);			
		}	
		x += 50;
		if(x > 1000)	
			x = 0;		
	}
}	


