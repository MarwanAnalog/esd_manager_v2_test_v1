//============================================================================
// Name        : modeM_v1.c
// Author      : Marouen BESSROUR
// Version     :
// Copyright   : Copyright TIS Circuits 2014
// Description : ESD_Manager_V2 
//============================================================================



/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "SimpleGPIO.h"



/*FUNCTIONS PROTOTYPES*/





/*VARIABLES*/
char barcode[100] 		//to get the barcode in a array of char
char *P1; 				// tools to decompose the barcode and extract the ID number from
char *P2;				//same
char *P3;				//same
int i=0;				// to verify a barcode was entered or not
int j;


unsigned int LEDGPIO = 60;   // GPIO1_28 = (1x32) + 28 = 60  P9.12
unsigned int ButtonGPIO = 15;   // GPIO0_15 = (0x32) + 15 = 15  P9.24



/*MAIN PROGRAM*/


int main ()
{



			gpio_export(LEDGPIO);    // The LED
			gpio_export(ButtonGPIO);   // The push button switch
			gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
			gpio_set_dir(ButtonGPIO, INPUT_PIN);   // The push button input



while(1)
{
	//wait for a scan
	while(i==0)  // Loop that keep reading from stdin until a barcode is scanned!
	{
		//LCD screen : Wait for Scan
		gets(barcode);
		printf("%s\n",barcode);
		i = strlen(barcode);
		if (i>0)
                {i=1;}
	}
	
	//extract the employee ID
	P1 = strtok(barcode," - ");
    P2 = strtok(NULL," - "); // the employee ID number will be saved here!
    P3 = strtok(NULL," - ");
	printf("The ID scanned is : %s\n",P2);
	
	
	
	
	
	
	// Authorize the ESD Test (activate a LED)
	gpio_set_value(LEDGPIO, HIGH);
	
	
	
	
	
	
	//Authorize Access (By a Button)
		printf("PLEASE Mr. MED LOTFI PRESS THE BUTTON \n");
		unsigned int value = LOW;
	do {
		gpio_get_value(ButtonGPIO, &value); 
	} while (value!=HIGH);
	
	printf("THANK YOU SIR \n");
	printf("ACCESS GRANTED \n");
	

}



gpio_unexport(LEDGPIO);     // unexport the LED
	gpio_unexport(ButtonGPIO);  // unexport the push button
	return 0;
}









