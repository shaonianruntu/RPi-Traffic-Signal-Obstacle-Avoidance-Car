#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>
void changespeed(int pin, int speed)  
{				// 2 3     0~1000	
	int i;
	for(i=0; i<20; i++)
	{  //  x/1000
		digitalWrite(pin, HIGH);
		delayMicroseconds(speed);
		digitalWrite(pin, LOW);
		delayMicroseconds(1000-speed);
	}
}

void forward()
{
	digitalWrite(8, HIGH); 
	digitalWrite(9, LOW); 
	digitalWrite(7, HIGH); 
	digitalWrite(0, LOW); 
	
	changespeed(2, 900);
	changespeed(3, 900);
}


void backward()
{
	digitalWrite(9, HIGH); 
	digitalWrite(8, LOW); 
	digitalWrite(0, HIGH); 
	digitalWrite(7, LOW); 
	
	changespeed(2, 900);
	changespeed(3, 900);
}



void turnleft()
{
	digitalWrite(8, HIGH); 
	digitalWrite(9, LOW); 
	
	digitalWrite(0, LOW); 
	digitalWrite(7, LOW); 
	
	changespeed(2, 900);
	//changespeed(3, 900);
}

void turnright()
{
	digitalWrite(8, LOW); 
	digitalWrite(9, LOW); 
	
	digitalWrite(7, HIGH); 
	digitalWrite(0, LOW); 
	
	//changespeed(2, 900);
	changespeed(3, 900);
}


void stop()
{
	digitalWrite(8, LOW); 
	digitalWrite(9, LOW); 
	digitalWrite(2, LOW); 
	digitalWrite(7, LOW); 
	digitalWrite(0, LOW); 
	digitalWrite(3, LOW); 
}
//#include <signal.h>
//#include <stdlib.h>
void exit_handler(int signo)
{
	stop();
	exit(0);
}
int main()
{	//  8 9 7 0 2 3 
	wiringPiSetup();
	signal(SIGINT, exit_handler);  // ctrl+c
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(0, OUTPUT);
	pinMode(3, OUTPUT);
	stop();
	
	int i;
	int dir;
	while(1)
	{
		scanf("%d", &dir);	
		switch(dir)
		{
			case 1:
				for(i=0; i<100; i++)
					forward();
				break;
			case 2:
				for(i=0; i<100; i++)
					backward();
				break;
			case 3:	
				for(i=0; i<100; i++)
					turnleft();
				break;
			case 4:	
				for(i=0; i<100; i++)
					turnright();
				break;
			default:
				break;
		}// switch
	}//while
	
}//main
