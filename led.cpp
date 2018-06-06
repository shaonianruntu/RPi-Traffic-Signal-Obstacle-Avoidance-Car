#include "stdio.h"
#include "wiringPi.h"
int main(){
	wiringPiSetup();		//initial
	pinMode(8, OUTPUT);		//set GPIO mode
	pinMode(9, OUTPUT);
	while(1){
		digitalWrite(8, LOW);	//option GPIO signal
		digitalWrite(9, LOW);
		delay(1000);			//delay

		digitalWrite(8, HIGH);	
		digitalWrite(9, HIGH);		
		delay(1000);
	}
}	


