/*---------------------------------------------------------------------------------
Program:			Lab 2.1
Programmer:			Glenn Lopez
Date:				2014-02-01 16:33
Class:				E12
Description:		Uses the 3 led's on zilog for output
Github page:		https://github.com/glennlopez/lab2_1/blob/master/lab2_1.c
	(visit the link above for the latest code history & revision)		
---------------------------------------------------------------------------------*/

/*-- 			HEADER FILES 			--*/
//#include <stdio.h>			//<-- header for compiling C
#include <ez8.h>				//<-- library for interfacing with Z8
//#include<myFunctions.h>		//<-- library for future subroutines and identifiers


/*-- 			START MAIN FUNCTION 			--*/
//int main(void) //!FLAG#1 - comment out if function does not require return 0;  
void main(void) //!FLAG#1 - comment out if function requires return 0;
{
	//CONSTANT CONFIGURATION

	//create local variable 'leds' to be data 0x05 (binary 101)
	unsigned char leds = 0x05;	//<-- guessing this light up first and last leds?

	//alternate function 
	PAADDR = 0x02;				//<-- write cycle into PAADDR (0x0FDO)
	PACTL = 0x00;				//<-- disable dem' alternative functions bra'

	//data directions
	PAADDR = 0x01;				//<-- write cycle into PAADDR (0x0FDO)
	PACTL = 0xF8;				//<-- makes 2 to 0 outputs | 7 to 3 inputs

	//output controll
	PAADDR = 0x03;				//<-- write cycle into PAADDR (0x0FDO)
	PACTL = 0x00;				//<-- makes all outputs push-pull

	//
	PAADDR = 0x00;				//<-- prevent changes to sub-regs

	//assign local variable 'leds' to PAOUT constant
	PAOUT = leds;				//<-- write cycle to PAOUT (0x0FD3)

	//return 0; //!FLAG#1 - comment out if int main(void) is not in use
}
/*-- 			END MAIN FUNCTION 			--*/