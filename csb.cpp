#include "stdio.h"
#include "wiringPi.h"
#include "sys/time.h"
int main(){
	wiringPiSetup();		//initial
	pinMode(15, OUTPUT);	//set GPIO mode
	pinMode(16, INPUT);
	struct timeval t1;		//(tv_sec, tv_usec)
	struct timeval t2;
	while(1){
		digitalWrite(15, LOW);
		delayMicroseconds(2);
		digitalWrite(15, HIGH);
		delayMicroseconds(10);
		digitalWrite(15, LOW);
		
		while(!(digitalRead(16) == 1));
		gettimeofday(&t1, NULL);
		//get t1
		while(!(digitalRead(16) == 0));
		gettimeofday(&t2, NULL);
		//get t2
		
		long start = t1.tv_sec * 1000000 + t1.tv_usec;
		long end = t2.tv_sec * 1000000 + t2.tv_usec;
		float dis = 1.0 * (end - start) / 1000000.0 * 34000.0 / 2.0;   //cm
		printf("distance - %fcm\n", dis);
		
		delay(2000);
	}
}	


