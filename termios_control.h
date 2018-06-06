#ifndef __TERMIOS_CONTROL_H__
#define __TERMIOS_CONTROL_H__

#include <termios.h> //操作终端
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

// #define DEBUG 1

enum command
{
	STOP,   // 0
	UP,		//1
	DOWN,	//2
	LEFT,	//3
	RIGHT,	//4
	ADD,	//5
	DEL,	//6
	UNKOWN,	//7
	INVALID
};

char my_getch(void);
void *trafficlight(void *arg);
void *webCar(void *arg);

enum command user_command(void);
#endif
