#include "stdio.h"
#include "wiringPi.h"
int main(){
	wiringPiSetup();
	pinMode(8, OUTPUT);	//led1
	pinMode(9, OUTPUT);	//led2
	pinMode(7, OUTPUT); //led3
	pinMode(0, OUTPUT); //led4
	pinMode(2, OUTPUT);	//led5
	pinMode(3, OUTPUT); //led6
	pinMode(30, OUTPUT);//led7
	pinMode(21, OUTPUT);//led8
	
	pinMode(22, OUTPUT);//R
	pinMode(23, OUTPUT);//G
	pinMode(24, OUTPUT);//B
	
	while(1){
		//led1
		digitalWrite(8,  LOW);
		digitalWrite(9,  HIGH);
		digitalWrite(7,  HIGH);
		digitalWrite(0,  HIGH);
		digitalWrite(2,  HIGH);
		digitalWrite(3,  HIGH);
		digitalWrite(30, HIGH);
		
		digitalWrite(22, LOW);
		digitalWrite(23, HIGH);
		digitalWrite(24, HIGH);
		delay(1000);
		//led2
		digitalWrite(8,  HIGH);
		digitalWrite(9,  LOW);
		digitalWrite(7,  HIGH);
		digitalWrite(0,  HIGH);
		digitalWrite(2,  HIGH);
		digitalWrite(3,  HIGH);
		digitalWrite(30, HIGH);
		
		digitalWrite(22, HIGH);
		digitalWrite(23, LOW);
		digitalWrite(24, HIGH);
		delay(1000);
		//led3
		digitalWrite(8,  HIGH);
		digitalWrite(9,  HIGH);
		digitalWrite(7,  LOW);
		digitalWrite(0,  HIGH);
		digitalWrite(2,  HIGH);
		digitalWrite(3,  HIGH);
		digitalWrite(30, HIGH);		

		digitalWrite(22, HIGH);
		digitalWrite(23, HIGH);
		digitalWrite(24, LOW);	
		delay(1000);
		//led4
		digitalWrite(8,  HIGH);
		digitalWrite(9,  HIGH);
		digitalWrite(7,  HIGH);
		digitalWrite(0,  LOW);
		digitalWrite(2,  HIGH);
		digitalWrite(3,  HIGH);
		digitalWrite(30, HIGH);	
		
		digitalWrite(22, LOW);
		digitalWrite(23, LOW);
		digitalWrite(24, HIGH);	
		delay(1000);
		//led5
		digitalWrite(8,  HIGH);
		digitalWrite(9,  HIGH);
		digitalWrite(7,  HIGH);
		digitalWrite(0,  HIGH);
		digitalWrite(2,  LOW);
		digitalWrite(3,  HIGH);
		digitalWrite(30, HIGH);	

		digitalWrite(22, LOW);
		digitalWrite(23, HIGH);
		digitalWrite(24, LOW);
		delay(1000);
		//led6
		digitalWrite(8,  HIGH);
		digitalWrite(9,  HIGH);
		digitalWrite(7,  HIGH);
		digitalWrite(0,  HIGH);
		digitalWrite(2,  HIGH);
		digitalWrite(3,  LOW);
		digitalWrite(30, HIGH);	

		digitalWrite(22, HIGH);
		digitalWrite(23, LOW);
		digitalWrite(24, LOW);
		delay(1000);
		//led7
		digitalWrite(8,  HIGH);
		digitalWrite(9,  HIGH);
		digitalWrite(7,  HIGH);
		digitalWrite(0,  HIGH);
		digitalWrite(2,  HIGH);
		digitalWrite(3,  HIGH);
		digitalWrite(30, LOW);	

		digitalWrite(22, LOW);
		digitalWrite(23, LOW);
		digitalWrite(24, LOW);
		delay(1000);
	}		
	
}
