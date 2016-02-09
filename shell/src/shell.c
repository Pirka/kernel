/*
 ============================================================================
 Name        : shell.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

int main(void)
{
//	char c;

//	system("/bin/stty raw");
	system( "/bin/stty --file=/dev/tty -icanon" );

   int c;
   static struct termios oldt, newt;

   /*tcgetattr gets the parameters of the current terminal
	STDIN_FILENO will tell tcgetattr that it should write the settings
	of stdin to oldt*/
   tcgetattr( STDIN_FILENO, &oldt);
   /*now the settings will be copied*/
   newt = oldt;

   /*ICANON normally takes care that one line at a time will be processed
	that means it will return if it sees a "\n" or an EOF or an EOL*/
   newt.c_lflag &= ~(ICANON | ECHO);

   /*Those new settings will be set to STDIN
	TCSANOW tells tcsetattr to change attributes immediately. */
//   tcsetattr( STDIN_FILENO, TCSANOW, &newt);


	printf("$");

	do {
		c = getchar();
		putchar(c);

	} while (c != '\r');



	system("/bin/stty cooked");

	return /*EXIT_SUCCESS*/0;
}
