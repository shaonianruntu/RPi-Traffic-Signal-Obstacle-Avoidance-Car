#include "termios_control.h"

char my_getch() 
{
        int c=0;  int res=0;
        struct termios org_opts, new_opts;
   
        res=tcgetattr(STDIN_FILENO, &org_opts);
        assert(res==0);

        memcpy(&new_opts, &org_opts, sizeof(new_opts));
        new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
        c=getchar();

        res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
		assert(res==0);
        return c; 
}

enum command user_command(void)
{
	enum command dir;
	char ch = my_getch();
	         // printf("-->%d\n", ch);
      if(ch == 27)
	{
      		ch = my_getch();
      		// printf("-->%d\n", ch);
        	if(ch == 91)
		{
            ch = my_getch();
			// printf("-->%d\n", ch);
            if(ch == 65)
				dir = UP;
			else if(ch == 66)
				dir = DOWN;
			else if(ch == 67)
				dir = RIGHT;
			else if(ch == 68)
				dir = LEFT;
			else if(ch == 53)
			{
				
				ch = my_getch();
				if(ch == 126)
					dir = ADD;
			// printf("-->%d\n", ch);
			}
			else if(ch == 54)
			{
				
				ch = my_getch();
				if(ch == 126)
					dir = DEL;
			//printf("-->%d\n", ch);
			}
         }
      }
	else if(ch == '\n')
		dir = STOP;
	else
		dir = INVALID;
	return dir;
}

#ifdef DEBUG

int main(int argc, char *argv[])
{
   int dir;
   while(1)
   {
	dir = user_command();
		   //printf("dir:%d\n", dir);
   }
   return 0;
}

#endif 
